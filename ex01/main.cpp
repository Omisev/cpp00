#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>
#include <limits>
#include <cctype>

// Fonction pour vérifier si une chaîne contient des chiffres
bool containsDigit(const std::string& s) {
    for (std::string::size_type i = 0; i < s.length(); i++) {
        if (std::isdigit(s[i])) {
            return true;
        }
    }
    return false;
}

// Fonction pour vérifier si une chaîne est numérique
bool isNumeric(const std::string& s) {
    for (std::string::size_type i = 0; i < s.length(); i++) {
        if (!std::isdigit(s[i]) && s[i] != '-' && s[i] != ' ') {
            return false;
        }
    }
    return true;
}

// Supprime les espaces au début et à la fin d'une chaîne
std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(' ');
    if (first == std::string::npos)
        return ""; // La chaîne ne contient que des espaces

    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

bool isNotEmptyOrWhitespace(const std::string& str) {
    if (str.empty()) return false;

    size_t compteEspaces = 0;
    for (size_t i = 0; i < str.length(); ++i) {
        if (isspace(static_cast<unsigned char>(str[i]))) compteEspaces++;
    }

    return compteEspaces != str.length();
}

std::string reduceMultipleSpacesToOne(const std::string& input) {
    std::string output;
    bool lastWasSpace = false;

    for (size_t i = 0; i < input.length(); ++i) {
        if (std::isspace(static_cast<unsigned char>(input[i]))) {
            if (!lastWasSpace) {
                // Si c'est le premier espace après des caractères non-espaces, l'ajouter
                output.push_back(' ');
                lastWasSpace = true;
            }
            // Sinon, ignorer les espaces supplémentaires
        } else {
            // Si ce n'est pas un espace, l'ajouter à la sortie
            output.push_back(input[i]);
            lastWasSpace = false;
        }
    }

    return output;
}

// Définition de la fonction pour lire une ligne de manière sécurisée
bool safeGetline(std::string& input) {
    std::getline(std::cin, input);
    if (!std::cin) {
        if (std::cin.eof()) {
            // Si CTRL+D est détecté, réinitialiser std::cin et sortir de addContact
            std::cin.clear();
            std::cout << "\nCTRL+D was pressed. Exiting addContact.\n";
            return false; // Indique l'échec de la lecture
        } else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return true; // Indique que la lecture est un succès
}

// int addContact(PhoneBook& phoneBook) {
//     Contact contact;
//     std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

//     while(true) {
//         std::cout << "Enter first name: ";
//         if (!safeGetline(firstName)) return -2;
//         firstName = trim(firstName);
//         firstName = reduceMultipleSpacesToOne(firstName);
//         if (!containsDigit(firstName) && isNotEmptyOrWhitespace(firstName)) {
//             break; // Sortie de la boucle si l'entrée est valide
//         } else {
//             std::cout << "Invalid input: first name should not contain digits and cannot be empty." << std::endl;
//         }
//     }

//     while(true) {
//         std::cout << "Enter last name: ";
//         if (!safeGetline(lastName)) return -2;
//         lastName = trim(lastName);
//         lastName = reduceMultipleSpacesToOne(lastName);
//         if (!containsDigit(lastName) && isNotEmptyOrWhitespace(lastName)) {
//             break;
//         } else {
//             std::cout << "Invalid input: last name should not contain digits and cannot be empty." << std::endl;
//         }
//     }

//     std::cout << "Enter nickname: ";
//     if (!safeGetline(nickname)) return -2;
//     nickname = trim(nickname);
//     nickname = reduceMultipleSpacesToOne(nickname);

//     while(true) {
//         std::cout << "Enter phone number: ";
//         if (!safeGetline(phoneNumber)) return -2;
//         phoneNumber = trim(phoneNumber);
//         if (isNumeric(phoneNumber)) {
//             break;
//         } else {
//             std::cout << "Invalid input: phone number should only contain digits." << std::endl;
//         }
//     }

//     std::cout << "Enter darkest secret: ";
//     if (!safeGetline(darkestSecret)) return -2;
//     darkestSecret = trim(darkestSecret);
//     darkestSecret = reduceMultipleSpacesToOne(darkestSecret);

//     contact.setContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
//     phoneBook.addContact(contact);

//     return 0;
// }



// int addContact(PhoneBook& phoneBook) {
//     if (std::cin.eof())
//         return -2;

//     Contact contact;
//     std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

//     // Saisie du prénom
//     while(true) {
//         std::cout << "Enter first name: ";
//         std::getline(std::cin, firstName);
//         firstName = trim(firstName);
//         firstName = reduceMultipleSpacesToOne(firstName);
//         if (isNotEmptyOrWhitespace(firstName)) {
//             break; // Sortie de la boucle si l'entrée est valide
//         } else {
//             std::cout << "Invalid input: first name cannot be empty or only spaces." << std::endl;
//         }
//     }

//     // Saisie du nom de famille
//     while(true) {
//         std::cout << "Enter last name: ";
//         std::getline(std::cin, lastName);
//         lastName = trim(lastName);
//         lastName = reduceMultipleSpacesToOne(lastName);
//         if (!containsDigit(lastName) && isNotEmptyOrWhitespace(lastName)) {
//             break;
//         } else {
//             std::cout << "Invalid input: last name should not contain digits and cannot be empty." << std::endl;
//         }
//     }			

//     // Saisie du surnom
//     std::cout << "Enter nickname: ";
//     std::getline(std::cin, nickname);
//     nickname = trim(nickname);
//     nickname = reduceMultipleSpacesToOne(nickname);

//     // Saisie du numéro de téléphone
//     while(true) {
//         std::cout << "Enter phone number: ";
//         std::getline(std::cin, phoneNumber);
//         phoneNumber = trim(phoneNumber);
//         if (isNumeric(phoneNumber)) {
//             break;
//         } else {
//             std::cout << "Invalid input: phone number should only contain digits." << std::endl;
//         }
//     }

//     // Saisie du secret le plus sombre
//     std::cout << "Enter darkest secret: ";
//     std::getline(std::cin, darkestSecret);
//     darkestSecret = trim(darkestSecret);
//     darkestSecret = reduceMultipleSpacesToOne(darkestSecret);

//     // Ajout du contact
//     contact.setContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
//     phoneBook.addContact(contact);

//     return 0; // Indique une opération réussie
// }


int addContact(PhoneBook& phoneBook) {
    if (std::cin.eof())
        return -2;

    Contact contact;
    std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

    std::cout << "Enter first name: ";
    std::getline(std::cin, firstName);
    if (std::cin.eof())
    {
        std::cout << "\nCTRL+D was pressed. Exiting addContact.\n";
        return -2;
    }
    firstName = trim(firstName);
    firstName = reduceMultipleSpacesToOne(firstName);
    if (std::cin.eof())
    {
        std::cout << "\nCTRL+D was pressed. Exiting addContact.\n";
        return -2;
    }

    std::cout << "Enter last name: ";
    std::getline(std::cin, lastName);
    if (std::cin.eof())
    {
        std::cout << "\nCTRL+D was pressed. Exiting addContact.\n";
        return -2;
    }
    lastName = trim(lastName);
    lastName = reduceMultipleSpacesToOne(lastName);

    if (containsDigit(lastName)) {
        std::cout << "Invalid input: first name should not contain digits." << std::endl;
        return -1; // Revenir au début de la boucle
    }			
    std::cout << "Enter nickname: ";
    std::getline(std::cin, nickname);
    if (std::cin.eof())
    {
        std::cout << "\nCTRL+D was pressed. Exiting addContact.\n";
        return -2;
    }
    nickname = trim(nickname);

    std::cout << "Enter phone number: ";
    std::getline(std::cin, phoneNumber);
    if (std::cin.eof())
    {
        std::cout << "\nCTRL+D was pressed. Exiting addContact.\n";
        return -2;
    }
    phoneNumber = trim(phoneNumber);


    if (!isNumeric(phoneNumber)) {
        std::cout << "Invalid input: phone number should only contain digits." << std::endl;
        return -1; // Revenir au début de la boucle
    }
    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, darkestSecret);
    if (std::cin.eof())
    {
        std::cout << "\nCTRL+D was pressed. Exiting addContact.\n";
        return -2;
    }
    darkestSecret = trim(darkestSecret);

    if (isNotEmptyOrWhitespace(firstName) && isNotEmptyOrWhitespace(lastName) && 
        isNotEmptyOrWhitespace(nickname) && isNotEmptyOrWhitespace(phoneNumber) && 
        isNotEmptyOrWhitespace(darkestSecret))
    {
        contact.setContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
        phoneBook.addContact(contact);
    }
    else
    {
        std::cout << "All fields must be filled and cannot contain only spaces." << std::endl;
        return -1; // Revenir au début de la boucle pour permettre à l'utilisateur de réessayer
    }
    return 0;
}

void displayMenu() {
    std::cout << "Enter command (ADD, SEARCH, EXIT): ";
}

bool handleInputError() {
    if (!std::cin) {
        if (std::cin.eof()) {
            std::cin.clear();
            std::cout << "\nCTRL+D was pressed. Exiting the program.\n";
            return true; // Indique la fin du programme
        } else {
            std::cin.clear();
            std::cout << "An error occurred while reading your input. Please try again.\n";
        }
    }
    return false; // Indique que le programme doit continuer
}

int main() {
    PhoneBook phoneBook;
    std::string command;

    while (true) {
        displayMenu();
        std::getline(std::cin, command);

        if (handleInputError()) {
            break; // Sortie du programme si nécessaire
        }

        if (command == "ADD")
        {
            int result = addContact(phoneBook);
            if (result == -2)
            {
                // Si CTRL+D a été pressé dans addContact, on réinitialise std::cin et on continue
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return (0); // Continue la boucle sans quitter le programme
            }
        }
        else if (command == "SEARCH") {
            bool continueRunning = phoneBook.searchContact();
            if (!continueRunning) {
                return (0); // Arrête le programme si searchContact retourne false
            }
        }
        else if (command == "EXIT") {
            break;
        }
    }
    return 0;
}

/**
 * Point d'entrée principal du programme.
 * Permet à l'utilisateur d'ajouter des contacts, de rechercher des contacts et de quitter l'application.
 *
 * @return EXIT_SUCCESS (0) pour indiquer une exécution réussie.
 */
// int main()
// {
// 	PhoneBook phoneBook;
// 	std::string command;
// 	while (true)
// 	{
//         std::cout << "Enter command (ADD, SEARCH, EXIT): ";
//         std::getline(std::cin, command);

//         // Si std::getline échoue à cause de EOF ou d'autres erreurs, réinitialiser std::cin et continuer
//         if (!std::cin) {
//             if (std::cin.eof())//<---
//             {
//                 // Réinitialiser std::cin pour enlever l'état de fail/EOF
//                 std::cin.clear();
//                 std::cout << "\nCTRL+D was pressed. Exiting the program.\n";
//                 break; // Ou continue selon le comportement souhaité
//             } else {
//                 std::cin.clear();
//                 std::cout << "An error occurred while reading your input. Please try again.\n";
//                 continue;
//             }
//         }
// 		if (command == "ADD")
// 		{
// 			if (std::cin.eof())
// 				return 0;
// 			Contact contact;
// 			std::string firstName, lastName, nickname, phoneNumber, darkestSecret;
// 			std::cout << "Enter first name: ";
// 			std::getline(std::cin, firstName);
//             firstName = trim(firstName);
//             firstName = reduceMultipleSpacesToOne(firstName);

// 			std::cout << "Enter last name: ";
// 			std::getline(std::cin, lastName);
//             lastName = trim(lastName);
//             lastName = reduceMultipleSpacesToOne(lastName);

// 			if (containsDigit(lastName)) {
//                 std::cout << "Invalid input: first name should not contain digits." << std::endl;
//                 continue; // Revenir au début de la boucle
//             }			
// 			std::cout << "Enter nickname: ";
// 			std::getline(std::cin, nickname);
//             nickname = trim(nickname);

// 			std::cout << "Enter phone number: ";
// 			std::getline(std::cin, phoneNumber);
//             phoneNumber = trim(phoneNumber);

//             if (!isNumeric(phoneNumber)) {
//                 std::cout << "Invalid input: phone number should only contain digits." << std::endl;
//                 continue; // Revenir au début de la boucle
//             }
// 			std::cout << "Enter darkest secret: ";
// 			std::getline(std::cin, darkestSecret);
//             darkestSecret = trim(darkestSecret);

// 			if (isNotEmptyOrWhitespace(firstName) && isNotEmptyOrWhitespace(lastName) && 
//                 isNotEmptyOrWhitespace(nickname) && isNotEmptyOrWhitespace(phoneNumber) && 
//                 isNotEmptyOrWhitespace(darkestSecret))
//             {
//                 contact.setContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
//                 phoneBook.addContact(contact);
//             }
//             else
//             {
//                 std::cout << "All fields must be filled and cannot contain only spaces." << std::endl;
//                 continue; // Revenir au début de la boucle pour permettre à l'utilisateur de réessayer
//             }
// 		}
// 		else if (command == "SEARCH")
// 			phoneBook.searchContact();
// 		else if (command == "EXIT")
// 			break;
// 	}
// 	return 0;
// }


