#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

/**
 * @brief Classe représentant un contact dans un annuaire téléphonique.
 * 
 * Cette classe stocke les informations personnelles d'un contact, telles que
 * le prénom, le nom, le surnom, le numéro de téléphone et le secret le plus 
 * sombre. Elle permet de définir et d'afficher ces informations, ainsi que de
 * formater l'affichage pour une présentation en liste.
 */

class Contact {
private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

public:
	Contact();
	void setContact(const std::string &firstName, const std::string &lastName, const std::string &nickname, const std::string &phoneNumber, const std::string &darkestSecret);
	void displayContact() const;
	void displayHeader(int index) const;
	std::string formatColumn(const std::string &str) const;
};

#endif
