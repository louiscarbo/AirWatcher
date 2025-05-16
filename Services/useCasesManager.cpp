/*************************************************************************
                           Classe : useCasesManager
*************************************************************************/

// Réalisation de la classe <UseCasesManager> (fichier UseCasesManager.cpp)

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>  // For sort, min, max
#include <numeric>    // For accumulate
#include <cmath>      // For abs
#include <chrono>
using Timestamp = std::chrono::time_point<std::chrono::system_clock>;

//------------------------------------------------------ Include personnel
#include "UseCasesManager.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
vector<pair<Sensor, double>> UseCasesManager::identifySuspiciousSensors()
// Algorithme :
//  Voir le document de conception pour les détails de l'algorithme.
{
    const int LAST_N = 30;                   // number of most recent readings to consider
    const int RANGE_MIN = 1;                 // ATMO lower bound
    const int RANGE_MAX = 10;                // ATMO upper bound
    const double NEIGHBOR_RADIUS_KM = 5.0;   // km
    const double LOCAL_DIFF_THRESHOLD = 2.0; // ATMO points

    // How many times the average daily change counts as a "spike"
    const double K_SPIKE_MULTIPLIER = 2.0; 

    // Weights for different checks
    const double WEIGHT_RANGE_VIOLATION = 2.0;
    const double WEIGHT_SPIKE_DETECTION = 1.5;
    const double WEIGHT_LOCAL_INCONSISTENCY = 2.0;

    const double MAX_SCORE = 10.0;

    // Initialize the list to hold the suspicious sensor scores
    vector<pair<Sensor, double>> scoredSensors;
    vector<Sensor> allSensors = sensors;

    for (auto& sensor : allSensors) {
        // Retrieve recent ATMO readings to compute the suspicion score
        vector<Timestamp> times = sensor.getMeasurementTimestamps();
        
        // Sort times in descending order and take only LAST_N elements
        sort(times.begin(), times.end(), greater<Timestamp>());
        if (times.size() > LAST_N) {
            times.resize(LAST_N);
        }
        
        // Map each timestamp to its corresponding ATMO index
        vector<double> recentAtmo;
        for (auto& t : times) {
            recentAtmo.push_back(sensor.calculateMeanAtmoIndex(t));
        }

        int N = recentAtmo.size();
        double score;

        if (N == 0) {
            // No recent data available, set maximum suspicion score
            score = MAX_SCORE;
        } else {
            // CHECK 1 - Out of range values
            int violations = 0;
            for (auto& atmo : recentAtmo) {
                if (atmo < RANGE_MIN || atmo > RANGE_MAX) {
                    violations++;
                }
            }
            double rateRange = static_cast<double>(violations) / N;

            // CHECK 2 - Spikes
            // a) Compute average daily change in ATMO value
            vector<double> changes;
            double prevAtmo = -1;
            
            for (auto& currentAtmo : recentAtmo) {
                if (prevAtmo >= 0) {  // Check if prevAtmo is valid
                    changes.push_back(abs(currentAtmo - prevAtmo));
                }
                prevAtmo = currentAtmo;
            }
            
            double avgChange = 0.0;
            if (!changes.empty()) {
                avgChange = accumulate(changes.begin(), changes.end(), 0.0) / changes.size();
            }
            
            double spikeThreshold = K_SPIKE_MULTIPLIER * avgChange;
            
            // b) Rate of spikes
            int spikes = 0;
            for (auto& change : changes) {
                if (change > spikeThreshold) {
                    spikes++;
                }
            }
            
            double rateSpike = static_cast<double>(spikes) / max(1, (int)changes.size());

            // CHECK 3 - Local inconsistency (comparison with neighbors)
            vector<double> deviations;
            
            for (auto& time : times) {
                double selfValue = sensor.calculateMeanAtmoIndex(time);
                vector<Sensor> neighbors = findSensorsWithinRadius(sensor.getCoordinates(), NEIGHBOR_RADIUS_KM);

                vector<double> neighborValues;
                for (auto& neighbor : neighbors) {
                    if (neighbor.hasMeasurementAt(time)) {
                        neighborValues.push_back(neighbor.calculateMeanAtmoIndex(time));
                    }
                }

                if (!neighborValues.empty()) {
                    double averageNeighborValues = accumulate(neighborValues.begin(), neighborValues.end(), 0.0) / neighborValues.size();
                    deviations.push_back(abs(selfValue - averageNeighborValues));
                }
            }
            
            double inconsistency = 0.0;
            if (!deviations.empty()) {
                double meanDev = accumulate(deviations.begin(), deviations.end(), 0.0) / deviations.size();
                double diffNorm = meanDev / LOCAL_DIFF_THRESHOLD;
                // Clamp inconsistency between 0 and 1
                inconsistency = min(max(diffNorm, 0.0), 1.0);
            }

            // Calculate final suspicion score
            double rawScore = WEIGHT_RANGE_VIOLATION * rateRange +
                            WEIGHT_SPIKE_DETECTION * rateSpike +
                            WEIGHT_LOCAL_INCONSISTENCY * inconsistency;
            
            score = min(rawScore, MAX_SCORE);
        }

        // Add the sensor and its suspicion score to the result list
        scoredSensors.push_back(make_pair(sensor, score));
    }

    // Sort by suspicion score (descending)
    sort(scoredSensors.begin(), scoredSensors.end(), 
         [](const pair<Sensor, double>& a, const pair<Sensor, double>& b) {
             return a.second > b.second;
         });
    
    return scoredSensors;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

UseCasesManager::UseCasesManager ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <UseCasesManager>" << endl;
#endif
} //----- Fin de UseCasesManager


UseCasesManager::~UseCasesManager ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <UseCasesManager>" << endl;
#endif
} //----- Fin de ~UseCasesManager


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

