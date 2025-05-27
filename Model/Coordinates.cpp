/*************************************************************************
                           Classe : Coordinates
*************************************************************************/

// Réalisation de la classe <Coordinates> (fichier Coordinates.cpp)

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "Coordinates.h"
#include <string>

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

double Coordinates::getLatitude() const {
    return latitude;
}

double Coordinates::getLongitude() const {
    return longitude;
}

Coordinates Coordinates::parseCoordinates(const std::string &input) {
    size_t commaPos = input.find(',');
    if (commaPos == std::string::npos) {
        throw std::invalid_argument("Invalid coordinate format. Use 'latitude,longitude'.");
    }
    
    double lat = std::stod(input.substr(0, commaPos));
    double lon = std::stod(input.substr(commaPos + 1));
    
    return Coordinates(lat, lon);
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