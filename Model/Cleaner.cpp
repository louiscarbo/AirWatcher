/*************************************************************************
                           Classe : Cleaner
*************************************************************************/

// Réalisation de la classe <Cleaner> (fichier Cleaner.cpp)

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include <string>
#include <ctime>
using namespace std;
#include "Cleaner.h"
#include "Coordinates.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

time_t Cleaner::getTimestamp_start() const {
    return timestamp_start;
}

time_t Cleaner::getTimestamp_stop() const {
    return timestamp_stop;
}

Coordinates * Cleaner::getCoordinates() const {
    return coordinates;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Cleaner::Cleaner() {
    #ifdef MAP
        cout << "Appel au constructeur par défaut de <Cleaner>" << endl;
    #endif
    this->cleanerID = "";
    this->timestamp_start = 0;
    this->timestamp_stop = 0;
    this->coordinates = new Coordinates();
}

Cleaner::Cleaner(string cleanerID, time_t timestamp_start, time_t timestamp_stop, double uneLatitude, double uneLongitude) {
    #ifdef MAP
        cout << "Appel au constructeur de <Cleaner>" << endl;
    #endif
    this->cleanerID = cleanerID;
    this->timestamp_start = timestamp_start;
    this->timestamp_stop = timestamp_stop;
    this->coordinates = new Coordinates(uneLatitude, uneLongitude);
}

Cleaner::~Cleaner() {
    #ifdef MAP
        cout << "Appel au destructeur de <Cleaner>" << endl;
    #endif
    delete coordinates;
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées