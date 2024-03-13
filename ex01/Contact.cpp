/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:39:52 by raveriss          #+#    #+#             */
/*   Updated: 2024/03/13 15:42:49 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <sstream>
#include <iostream>
#include <iomanip>

/**
 * Convertit un entier en chaîne de caractères.
 *
 * @param value L'entier à convertir.
 * @return La représentation sous forme de chaîne de l'entier.
 */
std::string intToString(int value) {
    std::stringstream ss;
    ss << value;
    return ss.str();
}

/*
    Constructeur par défaut de la classe Contact.
*/
Contact::Contact() {}

/**
 * Initialise les données d'un contact.
 *
 * @param fName Prénom du contact.
 * @param lName Nom de famille du contact.
 * @param nick Surnom du contact.
 * @param phone Numéro de téléphone du contact.
 * @param secret Le secret le plus sombre du contact.
 */
void Contact::setContact(const std::string &fName, const std::string &lName, const std::string &nick, const std::string &phone, const std::string &secret) {
    firstName = fName;
    lastName = lName;
    nickname = nick;
    phoneNumber = phone;
    darkestSecret = secret;
}

/**
 * Formate une chaîne de caractères pour l'affichage dans une colonne.
 * Tronque la chaîne à 10 caractères ou la remplit avec des espaces.
 *
 * @param str La chaîne de caractères à formater.
 * @return La chaîne formatée pour l'affichage.
 */
std::string Contact::formatColumn(const std::string &str) const {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    else
        return std::string(10 - str.length(), ' ') + str;
}

/**
 * Affiche l'en-tête de la liste des contacts.
 *
 * @param index L'index du contact dans la liste.
 */
void Contact::displayHeader(int index) const {
    std::cout << "|" << formatColumn(intToString(index))
              << "|" << formatColumn(firstName)
              << "|" << formatColumn(lastName)
              << "|" << formatColumn(nickname)
              << "|" << std::endl;
}

/**
 * Affiche les détails d'un contact.
 */
void Contact::displayContact() const {
    std::cout << "First name: " << firstName << std::endl
              << "Last name: " << lastName << std::endl
              << "Nickname: " << nickname << std::endl
              << "Phone number: " << phoneNumber << std::endl
              << "Darkest secret: " << darkestSecret << std::endl;
}
