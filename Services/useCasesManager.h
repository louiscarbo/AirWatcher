/*************************************************************************
                           Classe  -  UseCasesManager
*************************************************************************/

//- Interface de la classe <UseCasesManager> (fichier UseCasesManager.h) -
#if ! defined ( UseCasesManager_H )
#define UseCasesManager_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
#include "../Model/Sensor.h"

//------------------------------------------------------------------------
// Rôle de la classe UseCasesManager
//
//
//------------------------------------------------------------------------

class UseCasesManager 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques    
    vector<pair<Sensor, double>> identifySuspiciousSensors();
    // Mode d'emploi :
    //  Appeler cette méthode pour identifier les capteurs suspicieux
    //  (soit des capteurs défectueux, soit des capteurs malicieux).
    //  Elle renvoie une liste de paires (capteur, valeur) où la valeur
    //  est le score de suspicion du capteur.
    // Contrat :
    //  - La liste de capteurs doit être initialisée avant d'appeler cette méthode.

    vector<Sensor> findSensorsWithinRadius(const Coordinates& center, double radius);
    // Mode d'emploi :
    //  Renvoie une liste de capteurs situés dans un rayon donné autour d'un point central.
    //  Le rayon est en kilomètres.
    // Contrat :
    //  - center doit être un objet de type Coordinates valide.

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    UseCasesManager ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~UseCasesManager ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    bool trackPerformance;
    vector<Sensor> sensors;
};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // UseCasesManager

