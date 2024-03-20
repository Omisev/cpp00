/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raveriss <raveriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:32:07 by raveriss          #+#    #+#             */
/*   Updated: 2024/03/19 17:36:00 by raveriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

#define EXIT_SUCCESS 0
#define FIRST_ARGUMENT_INDEX 1

const std::string LOUD_FEEDBACK = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

/**
 * Convertit une chaîne de caractères en majuscules.
 *
 * @param input La chaîne de caractères à convertir.
 * @return La chaîne convertie en majuscules.
 */
std::string toUpperCase(const std::string &input)
{
	std::string result = input;

	for (size_t i = 0; i < result.length(); ++i)
	{
		result[i] = std::toupper(result[i]);
	}
	return result;
}

/**
 * Affiche les arguments de la ligne de commande en majuscules.
 * Si aucun argument n'est fourni, affiche un message d'erreur sonore.
 *
 * @param argc Le nombre d'arguments de la ligne de commande.
 * @param argv Les arguments de la ligne de commande.
 * @return EXIT_SUCCESS pour indiquer une exécution réussie.
 */
int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << LOUD_FEEDBACK << std::endl;
	else
	{
	
		for (int i = FIRST_ARGUMENT_INDEX; i < argc; ++i)
		{
			std::string str = toUpperCase(argv[i]);
			std::cout << str;
		}
		std::cout << std::endl;
		
	}

	return EXIT_SUCCESS;
}
