/*************************************************************************
                           AirCleanerProvider
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <AirCleanerProvider> (fichier AirCleanerProvider.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "AirCleanerProvider.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
const std::string& AirCleanerProvider::GetProviderID() const {
    return providerID;
}

void AirCleanerProvider::GetCleaners() const {
    return cleanersID;
}

void AirCleanerProvider::AddCleanerID(const Cleaner& cleanerID) {
    cleanersID.push_back(cleanerID);
}
//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
AirCleanerProvider::AirCleanerProvider(const std::string& providerID) : providerID(providerID)
{ }

AirCleanerProvider::~AirCleanerProvider() = default;
//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

