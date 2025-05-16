/*************************************************************************
                           Classe : Measurement
*************************************************************************/

// Réalisation de la classe <Measurement> (fichier Measurement.cpp)

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <ctime>
#include <string>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Measurement.h"
#include "Attribute.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

float Measurement::getValue(){
    return value;
}

Attribute Measurement::getAttribute(){
    return attribute;
}

time_t Measurement::getTimeStamp(){
    return timestamp;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Measurement::Measurement(time_t time, float valeur, string capteurID, Attribute attribut){
    timestamp = time;
    attribute = attribut;
    sensorID = capteurID;
    value = valeur;
}

Measurement::~Measurement ( ){
#ifdef MAP
    cout << "Appel au destructeur de <Measurement>" << endl;
#endif
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées