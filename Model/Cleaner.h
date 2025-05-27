/*************************************************************************
                           Classe  -  Cleaner
*************************************************************************/

//- Interface de la classe <Cleaner> (fichier Cleaner.h) -
#if ! defined ( Cleaner_H )
#define Cleaner_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe Cleaner
//
//
//------------------------------------------------------------------------
#include <string>
#include <ctime>
using namespace std;
#include "Coordinates.h"

class Cleaner 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    time_t getTimestamp_start() const;
    // Mode d'emploi :
    // Retourne le timestamp de début du Cleaner.
    // Contrat :
    //

    time_t getTimestamp_stop() const;
    // Mode d'emploi :
    // Retourne le timestamp de fin du Cleaner.
    // Contrat :
    //

    Coordinates * getCoordinates() const;
    // Mode d'emploi :
    // Retourne les coordonnées du Cleaner.
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    Cleaner ( );
    // Mode d'emploi :
    // Constructeur par défaut de la classe Cleaner.
    // Contrat :
    //

    Cleaner (string cleanerID, time_t timestamp_start, time_t timestamp_stop, double uneLatitude, double uneLongitude);
    // Mode d'emploi :
    // Constructeur de la classe Cleaner avec paramètres.
    // Contrat :
    //

    virtual ~Cleaner ( );
    // Mode d'emploi :
    // Destructeur de la classe Cleaner.
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    string cleanerID;
    time_t timestamp_start;
    time_t timestamp_stop;
    Coordinates * coordinates;

};

//-------------------------------- Autres définitions dépendantes de <Cleaner>

#endif // Cleaner
