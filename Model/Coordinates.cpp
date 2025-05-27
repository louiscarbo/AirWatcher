/*************************************************************************
                           Classe : Coordinates
*************************************************************************/

// Réalisation de la classe <Coordinates> (fichier Coordinates.cpp)

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "Coordinates.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

double Coordinates::getLatitude() const {
    return latitude;
}

double Coordinates::getLongitude() const {
    return longitude;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Coordinates::Coordinates() {
    #ifdef MAP
        cout << "Appel au constructeur par défault de <Coordinates>" << endl;
    #endif
    this->latitude = 0.0;
    this->longitude = 0.0;
}

Coordinates::Coordinates(double uneLatitude, double uneLongitude) {
    #ifdef MAP
        cout << "Appel au constructeur de <Coordinates>" << endl;
    #endif
    this->latitude = uneLatitude;
    this->longitude = uneLongitude;
}

Coordinates::~Coordinates() {
    #ifdef MAP
        cout << "Appel au destructeur de <Coordinates>" << endl;
    #endif
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées