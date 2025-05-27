/*************************************************************************
                           Classe  -  Sensor
*************************************************************************/

//- Interface de la classe <Sensor> (fichier Sensor.h) -
#if ! defined ( Sensor_H )
#define Sensor_H

//--------------------------------------------------- Interfaces utilisées
#include <chrono>
#include <string>
#include <vector>
#include <list>
using namespace std;
using Timestamp = std::chrono::time_point<std::chrono::system_clock>;
#include "../Model/Coordinates.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe Sensor
//
//
//------------------------------------------------------------------------

class Sensor 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques    
    vector<Timestamp> getMeasurementTimestamps() const;
    // Mode d'emploi :
    //  Renvoie les horodatages des mesures du capteur.

    int calculateMeanAtmoIndex(Timestamp at);
    // Mode d'emploi :
    //  Calcule l'indice ATMO moyen à partir des mesures du capteur
    //  pour un horodatage donné.
    // Contrat :
    //  - at doit être un horodatage valide.
    //  - S'il n'y a pas de mesures à cet horodatage, la méthode renvoie NaN

    Coordinates getCoordinates() const;
    // Mode d'emploi :
    //  Renvoie les coordonnées du capteur.
    // Contrat :
    //  - Les coordonnées doivent être initialisées avant d'appeler cette méthode.

    bool hasMeasurementAt(Timestamp at) const;
    // Mode d'emploi :
    //  Vérifie si le capteur a une mesure à un horodatage donné.
    // Contrat :
    //  - at doit être un horodatage valide.

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    Sensor ( );
    // Mode d'emploi :
    //
    // Contrat :
    //
    Sensor(string sensor_ID, float latitudeInit, float longitudeInit);

    virtual ~Sensor ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    string sensorID;
    string ownerID;
    Coordinates coordinates;
    list<Measurement> measurements;
    PrivateIndividual privateIndividual;
    map<string,map<int,int>> dictUnitAtmoMaxValue;
//----------------------------------------------------- Méthodes protégées    

    void initDictUnit()
    // initialise le dictionnaire dictUnitAtmoMaxValue sous la forme : 
    //  dictUnitAtmoMaxValue[U][atmo value]= X; avec X la valeur maximale dans l'unité U correspondant à l'atmo value
    //  exemple : dictUnitAtmoMaxValue["O3"][1]=29;
};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // Sensor
