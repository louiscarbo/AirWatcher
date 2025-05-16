/*************************************************************************
                           Classe  -  Coordinates
*************************************************************************/

//- Interface de la classe <Coordinates> (fichier Coordinates.h) -
#if ! defined ( Coordinates_H )
#define Coordinates_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe Coordinates
//
//
//------------------------------------------------------------------------

class Coordinates 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques    

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    Coordinates ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Coordinates ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    double latitude;
    double longitude;
};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // Coordinates
