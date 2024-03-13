#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>

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
			std::cout << "Enter last name: ";
			std::cin >> lastName;
			std::cout << "Enter nickname: ";
			std::cin >> nickname;
			std::cout << "Enter phone number: ";
			std::cin >> phoneNumber;
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
