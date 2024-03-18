#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <cstdlib> // Pour std::atoi

/**
 * Constructeur par défaut pour PhoneBook.
 * Initialise le carnet d'adresses avec une taille actuelle de 0 et l'indice le p
 * lus ancien à 0.
 */
PhoneBook::PhoneBook() : currentSize(0), oldestIndex(0) {}

/**
 * Ajoute un contact au carnet d'adresses.
 * Si le carnet contient déjà 8 contacts, le plus ancien est remplacé par le
 * nouveau.
 *
 * @param contact Le contact à ajouter ou à remplacer dans le carnet.
 */
void PhoneBook::addContact(const Contact &contact) {
	contacts[oldestIndex] = contact;
	oldestIndex = (oldestIndex + 1) % 8;
	if (currentSize < 8) currentSize++;
}

/**
 * Affiche un sommaire de chaque contact stocké et permet à l'utilisateur de
 * sélectionner un contact pour afficher plus de détails.
 * L'utilisateur est invité à entrer l'indice du contact à visualiser.
 */
void PhoneBook::searchContact() const {
    for (int i = 0; i < currentSize; i++) {
        contacts[i].displayHeader(i + 1);
    }
    std::cout << "Enter the index of the contact you want to view: ";
    std::string input;
    std::cin >> input;

    // Vérification que l'entrée est numérique
    bool isNumeric = true;
    for (int i = 0; i < input.length(); i++) {
        if (!isdigit(input[i])) {
            isNumeric = false;
            break;
        }
    }

    if (isNumeric) {
        int index = std::atoi(input.c_str()); // Conversion de la chaîne en entier

        if (index < 1 || index > currentSize) {
            std::cout << "Invalid index" << std::endl;
        } else {
            contacts[index - 1].displayContact();
        }
    } else {
        std::cout << "Invalid index" << std::endl;
    }

    // Nettoyer le flux d'entrée au cas où l'utilisateur aurait saisi plusieurs valeurs
    std::cin.clear();
    std::cin.ignore(10000, '\n');
}
