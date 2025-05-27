/*************************************************************************
                           CSVParser
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <CSVParser> (fichier CSVParser.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "CSVParser.h"
#include <fstream>
#include <iostream>
#include <sstream>

#include <vector>
#include <string>
#include <unordered_map>



//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
 vector<string> CSVParser::splitLine ( const string & ligne, char delimiter) {
    vector <string> elements;
    stringstream ss(ligne);
    string car;

    while (getline(ss,car,delimiter)) {
        elements.push_back(car);
    }
    return elements;
 }

vector<Attribute> CSVParser::loadAttributes (){
    vector<Attribute> attributs;
    ifstream file(path + "/attributes.csv");

    if (!file) {
        cerr <<"Erreur ouverture du fichier contenant les attributs";
        return attributs;   
    }

    string line;
    getline(file,line);

    while (getline(file,line)){
        if (line.empty()) continue;
        auto cols = splitLine(line);

        if (cols.size() <3) continue;
        attributs.emplace_back( cols[0],cols[1],cols[2]);
    }
    return attributs; 
}

vector<Sensor> CSVParser::loadSensors (){
    vector<Sensor> sensors;
    ifstream file(path + "/sensors.csv");

    if (!file) {
        cerr <<"Erreur ouverture du fichier contenant les capteurs (sensors)";
        return sensors;   
    }

    string line;

    while (getline(file,line)){
        if (line.empty()) continue;
        auto cols = splitLine(line);

        if (cols.size() <3) continue; //3 car 
        Sensor s( 
            cols[0],
            Coordinates {
                stod(cols[1]),
                stod(cols[2]) }
            );
        sensors.push_back(move(s));
    }
    return sensors; 
}

vector<Measurement> CSVParser::loadMeasurements (){
    vector<Measurement> mesures;
    ifstream file(path + "/measurements.csv");

    if (!file) {
        cerr <<"Erreur ouverture du fichier contenant les mesures (measurements)";
        return mesures;   
    }

    string line;

    while (getline(file,line)){
        if (line.empty()) continue;
        auto cols = splitLine(line);

        if (cols.size() <4) continue; //4 car 4 colonnes

        mesures.emplace_back(
            TimeStamp::fromString(cols[0]),
            stof(cols[3]),
            cols[1],
            Attribute{cols[2],"",""}
        );
    }
    return mesures; 
}

vector<Cleaner> CSVParser::loadCleaners (){
    vector<Cleaner> cleaners;
    ifstream file(path + "/cleaners.csv");

    if (!file) {
        cerr <<"Erreur ouverture du fichier contenant les cleaners";
        return cleaners;   
    }

    string line;

    while (getline(file,line)){
        if (line.empty()) continue;
        auto cols = splitLine(line);

        if (cols.size() <5) continue;

        Cleaner c(
            cols[0],
            TimeStamp::fromString(cols[3]),
            TimeStamp::fromString(cols[4]),
            Coordinates {
                stod(cols[1]),
                stod(cols[2]) }
            );
            cleaners.push_back(move(c));
    }
    return cleaners; 
}

vector<PrivateIndividual> CSVParser::loadPrivateIndividuals() {
    std::ifstream file(path + "/users.csv");
    if (!file) {
        cerr << "Erreur d'ouverture de /users.csv";
        return {};
    }

    unordered_map<std::string, PrivateIndividual> mapUsers;
    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        auto cols = splitLine(line);
        // on s'attend à : userName;sensorID
        if (cols.size() < 2) continue;

        const std::string& userName = cols[0];
        const std::string& sensorID = cols[1];

        // crée le PrivateIndividual une seule fois
        auto it = mapUsers.find(userName);
        if (it == mapUsers.end()) {
            auto [ins, pairIt] = mapUsers.emplace(
                userName,
                PrivateIndividual(userName, true, 0)
            );
            it = pairIt;
        }
        // ajoute le capteur à cet utilisateur
        it->second.AddSensor(sensorID);
    }

    // convertit la map en vector à retourner
    std::vector<PrivateIndividual> users;
    users.reserve(mapUsers.size());
    for (auto& kv : mapUsers) {
        users.push_back(std::move(kv.second));
    }
    return users;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
CSVParser::CSVParser ( const std::string & unpath ): path(unpath){
    #ifdef MAP
    cout << "Appel constructeur <CSVParser>" << endl;
    #endif
}



CSVParser::~CSVParser ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CSVParser>" << endl;
#endif
} //----- Fin de ~CSVParser


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

