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

    double getLatitude() const;
    double getLongitude() const;
    static Coordinates parseCoordinates(const std::string &input);

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    Coordinates ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    Coordinates (double uneLatitude, double uneLongitude);
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
