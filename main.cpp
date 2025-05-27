#include "Services/UseCasesManager.h"
#include "Presentation/Menu.h"
#include <string>
#include <iostream>
using namespace std;

int main() {

    // Initialiser les données et les cas d'utilisation
    UseCasesManager manager;
    // manager.loadData(); // Ou une méthode similaire ?

    // Initialiser le menu avec le manager
    Menu menu(manager);

    bool profileSelected = false;
    bool applicationRunning = true;

    while(applicationRunning) {

        if (!profileSelected) {
            menu.displayProfileSelectionMenu();
            profileSelected = true;
        }

        // Afficher le menu principal adapté au rôle utilisateur
        menu.displayMainMenu();
        // Lire l'option choisie par l'utilisateur
        std::string optionStr = menu.getUserInput("Veuillez sélectionner une option (ou 'q' pour quitter): ");
        
        if (optionStr == "q") {
            applicationRunning = false;
        } else {
            int option = std::stoi(optionStr);
            menu.selectFunctionality(option);
        }
    }

    cout << "Exiting the application. Goodbye!" << endl;

    return 0;
}