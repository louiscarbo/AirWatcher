/*************************************************************************
                           Menu
*************************************************************************/

//---------- Réalisation de la classe <Menu> (fichier Menu.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Menu.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Menu::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void Menu::displayProfileSelectionMenu()
{
    #ifdef MAP
        cout << "Appel à displayProfileSelectionMenu" << endl;
    #endif
    cout << "--- Sélection de Profil ---" << endl;
    cout << "1. Utilisateur" << endl;
    cout << "2. Administrateur" << endl;
    cout << "3. Superviseur" << endl;
    cout << "Veuillez sélectionner un profil (1-3): ";
    
    int choice;
    bool validChoice = false;
    
    while (!validChoice)
    {
        cin >> choice;
        
        if (choice < 1 || choice > 3)
        {
            cin.clear();
            cout << "Choix invalide. Veuillez entrer un nombre entre 1 et 3: ";
        } else {
            validChoice = true;
            selectedProfile = choice;
            cout << "Profil sélectionné." << endl;
        }
    }
}

void Menu::displayMainMenu()
{
    #ifdef MAP
        cout << "Appel à displayMainMenu" << endl;
    #endif
    
    cout << "--- Menu Principal ---" << endl;
    
    cout << "1. Calculate Air Quality at a Precise Moment and Geography" << endl;
    cout << "2. Calculate the Average Air Quality in a Given Area" << endl;
    cout << "3. Identify Areas with Similar Air Quality" << endl;
    cout << "4. Observe Impact of the Cleaners on Air Quality" << endl;

    if (selectedProfile == 1) // Utilisateur
    {
        cout << "5. Consult your Awarded Points" << endl;
    }

    if (selectedProfile == 2) // Administrateur
    {
        cout << "5. Identify malfunctioning or malicious sensors" << endl;
    }
}

std::string Menu::getUserInput(const std::string &prompt)
{
    #ifdef MAP
        cout << "Appel à getUserInput avec prompt: " << prompt << endl;
    #endif
    
    cout << prompt;
    std::string input;
    cin >> input;
    return input;
}

//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur
Menu::Menu(UseCasesManager &useCasesManager)
    : manager(useCasesManager)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Menu>" << endl;
#endif
} //----- Fin de Menu

Menu::~Menu()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Menu>" << endl;
#endif
} //----- Fin de ~Menu

//------------------------------------------------------------------ PRIVE
//------------------------------------------------------------------ PRIVE

void Menu::selectFunctionality(int option)
{
    #ifdef MAP
        cout << "Appel à selectFunctionality avec option: " << option << endl;
    #endif
    
    switch (option)
    {
        case 1:
            calculateAirQualityAtMoment();
            break;
        case 2:
            calculateMeanAirQualityArea();
            break;
        case 3:
            identifyAreasWithSimilarAirQuality();
            break;
        case 4:
            observeCleanerImpact();
            break;
        case 5:
            if (selectedProfile == 1) // Utilisateur
            {
                consultUserPoints();
            } else if (selectedProfile == 2) {
                identifyMalfunctioningSensors();
            }
            break;
        default:
            cout << "Option invalide. Veuillez réessayer." << endl;
            break;
    }
}

//----------------------------------------------------- Méthodes protégées
