# **Projet CPP00 - École 42**

## Introduction
Le module CPP00 est conçu pour introduire les étudiants aux bases de la programmation en C++, avec un accent particulier sur la programmation orientée objet (POO) selon le standard C++98. Ce projet sert de fondement pour des modules plus avancés.

## Structure du Projet
Chaque exercice est contenu dans son propre dossier et comprend des fichiers spécifiques essentiels à la réalisation de l'exercice. Voici une vue d'ensemble des composants de chaque exercice :

### Exercice 00: Mégaphone
- **Dossier :** `ex00/`
- **Fichiers :**
  - `Makefile` : Script pour compiler le programme.
  - `megaphone.cpp` : Code source du mégaphone.

#### Fonctionnalité
Convertit le texte entré en arguments en majuscules, simulant un mégaphone. Si aucun argument n'est fourni, il produit un son de feedback fort et insupportable.

### Exercice 01: My Awesome PhoneBook
- **Dossier :** `ex01/`
- **Fichiers :**
  - `Makefile` : Script pour compiler le programme.
  - `PhoneBook.cpp` : Implémentation de la classe PhoneBook.
  - `Contact.cpp` : Implémentation de la classe Contact.
  - `main.cpp` : Point d'entrée principal du programme.

#### Fonctionnalité
Simule un répertoire téléphonique des années 80 avec la capacité de stocker, ajouter, et rechercher des contacts.

### Exercice 02: L’emploi de vos rêves
- **Dossier :** `ex02/`
- **Fichiers :**
  - `Makefile` : Script pour compiler le programme.
  - `Account.cpp` : Implémentation de la classe Account.
  - `Account.hpp` : Définition de la classe Account.
  - `tests.cpp` : Fichier de tests pour vérifier le fonctionnement de Account.

#### Fonctionnalité
Simule un système bancaire où les interactions sont tracées et vérifiées par un fichier de tests.

## Compilation et Exécution

### Exercice 00: Mégaphone
```bash
cd ex00
make
./megaphone "Votre message"
```

### Exercice 00: My Awesome PhoneBook
```bash
cd ex01
make
./phonebook
```
### Exercice 02: L’emploi de vos rêves
```bash
cd ex02
make
./Account 
```
## Ressources Utilisées
- [Apprenez à programmer en C++ sur OpenClassrooms](https://openclassrooms.com/fr/courses/1894236-apprenez-a-programmer-en-c)
- [Programmez en orienté objet avec C++ sur OpenClassrooms](https://openclassrooms.com/fr/courses/7137751-programmez-en-oriente-objet-avec-c)
