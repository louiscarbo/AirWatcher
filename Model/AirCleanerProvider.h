/*************************************************************************
                           Classe : AirCleanerProvider
                             -------------------
    début                : 
    copyright            : B3232 B3235
    e-mail               : 
*************************************************************************/

//---------- Interface de la classe <useCasesManager> (fichier useCasesManager.h) ----------------
#if ! defined ( AIRCLEANERPROVIDER_H )
#define AIRCLEANERPROVIDER_H

#include <string>
#include <vector>
using namespace std;

//--------------------------------------------------- Interfaces utilisées
#include "Cleaner.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <AirCleanerProvider>
//
//
//------------------------------------------------------------------------

class AirCleanerProvider
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    const std::string& GetProviderID() const;
    const std::vector<Cleaner>& GetCleaners() const;
    void AddCleaner(const Cleaner& cleaner);

//-------------------------------------------- Constructeurs - destructeur
    explicit AirCleanerProvider(const std::string& providerID);
    ~AirCleanerProvider();

private:
//----------------------------------------------------- Méthodes protégées
//----------------------------------------------------- Attributs protégés
    std::string providerID;
    std::vector<Cleaner>  cleaners;
};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // AIRCLEANERPROVIDER_H
