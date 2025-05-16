/*************************************************************************
                           Classe  -  useCasesManager
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <useCasesManager> (fichier useCasesManager.h) ----------------
#if ! defined ( USECASESMANAGER_H )
#define USECASESMANAGER_H

#include Sensor.h;
#include Measurement.h;
#include Cleaner;
#include privateIndividual; 

#include <list>;

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Xxx>
//
//
//------------------------------------------------------------------------

class useCasesManager 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    useCasesManager & operator = ( const Xxx & unXxx );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    useCasesManager ( const Xxx & unXxx );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    useCasesManager ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~useCasesManager ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
bool trackPerformance;
std::list<Sensor> sensors;
std::list<Measurement> measurements;
std::list<Cleaner> cleaners;
std::list<rivateIndividual> privateIndividuals;




};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // USECASESMANAGER

