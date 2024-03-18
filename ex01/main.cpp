#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>

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

/**
 * Point d'entrée principal du programme.
 * Permet à l'utilisateur d'ajouter des contacts, de rechercher des contacts et de quitter l'application.
 *
 * @return EXIT_SUCCESS (0) pour indiquer une exécution réussie.
 */
int main()
{
	PhoneBook phoneBook;
	std::string command;
	while (true)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		std::cin >> command;
		if (command == "ADD")
		{
			if (std::cin.eof())
				return 0;
			Contact contact;
			std::string firstName, lastName, nickname, phoneNumber, darkestSecret;
			std::cout << "Enter first name: ";
			std::cin >> firstName;
			if (containsDigit(firstName)) {
                std::cout << "Invalid input: first name should not contain digits." << std::endl;
                continue; // Revenir au début de la boucle
            }
			std::cout << "Enter last name: ";
			std::cin >> lastName;
			if (containsDigit(lastName)) {
                std::cout << "Invalid input: first name should not contain digits." << std::endl;
                continue; // Revenir au début de la boucle
            }			
			std::cout << "Enter nickname: ";
			std::cin >> nickname;				
			std::cout << "Enter phone number: ";
			std::cin >> phoneNumber;
            if (!isNumeric(phoneNumber)) {
                std::cout << "Invalid input: phone number should only contain digits." << std::endl;
                continue; // Revenir au début de la boucle
            }
			std::cout << "Enter darkest secret: ";
			std::cin >> darkestSecret;
			contact.setContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
			phoneBook.addContact(contact);
		}
		else if (command == "SEARCH")
			phoneBook.searchContact();
		else if (command == "EXIT")
			break;
	}
	return 0;
}
