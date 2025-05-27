/*************************************************************************
                           Classe : CSVParser
                             -------------------
    début                : 
    copyright            : B3232 B3235
    e-mail               : 
*************************************************************************/

//---------- Interface de la classe <useCasesManager> (fichier useCasesManager.h) ----------------
#if ! defined ( CSVPARSER_H )
#define CSVPARSER_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;


//--------------------------------------------------- Interfaces utilisées
#include "useCasesManager.h"
#include "Sensor.h"
#include "Measurement.h"
#include "Cleaner.h"
#include "PrivateIndividual.h"
#include "Attribute.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <CSVParser>
//
//
//------------------------------------------------------------------------

class CSVParser
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    
    vector<Attributes> loadAttributes();
    // Charge et retourne la liste de tous les attributs  (attributes.csv)
    
    vector<Sensor> loadSensors();
    // Charge et retourne la liste de tous les capteurs (sensors.csv)

    vector<Measurement> loadMeasurements(); 
    // Charge et retourne la liste de toutes les mesures (measurements.csv)

    vector<Cleaner> loadCleaners();
    // Charge et retourne la liste de tous les cleaners (cleaners.csv)

    vector<PrivateIndividual> loadPrivateIndividuals();
    // Charge et retourne la liste de tous les utilisateurs privés (users.csv)

    vector<PrivateIndividual> loadProviders();
    // Charge et retourne la liste de tous les utilisateurs privés (providers.csv)

//-------------------------------------------- Constructeurs - destructeur


Xxx ( const Xxx & unXxx );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Xxx ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Xxx ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- Méthodes protégées

    vector<string> CSVParser :: splitLine (const string & ligne, char delimiter=';');
//----------------------------------------------------- Attributs protégés
    string path;
};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // CSVPARSER_H

