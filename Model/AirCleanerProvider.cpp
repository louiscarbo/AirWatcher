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

const std::vector<Cleaner>& AirCleanerProvider::GetCleaners() const {
    return cleaners;
}

void AirCleanerProvider::AddCleaner(const Cleaner& cleaner) {
    cleaners.push_back(cleaner);
}
//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
AirCleanerProvider::AirCleanerProvider(const std::string& providerID) : providerID(providerID)
{ }

AirCleanerProvider::~AirCleanerProvider() = default;
//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

