#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"

/**
 * @brief Classe représentant un annuaire téléphonique.
 * 
 * Cette classe gère un annuaire téléphonique pouvant contenir jusqu'à 8 contacts.
 * Elle permet d'ajouter des contacts à l'annuaire et de rechercher parmi les contacts existants.
 */
class PhoneBook {
private:
	Contact contacts[8];
	int currentSize;
	int oldestIndex;

public:
	PhoneBook();
	void addContact(const Contact &contact);
	void searchContact() const;
};

#endif
