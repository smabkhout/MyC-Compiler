# Compilateur MyC vers PCode

## Description
Ce projet consiste en la réalisation d'un compilateur pour un langage impératif "MyC", qui génère du code intermédiaire **PCode**.
 Le compilateur est développé en utilisant Flex pour l'analyse lexicale et Bison pour l'analyse syntaxique.

## Fonctionnalités implémentées

### Types INT et FLOAT
*** Gestion des constantes et opérations entières avec LOADI, ADDI, MULTI, etc.
*** Gestion des flottants et conversions automatiques INT vers FLOAT.
*** Détection d'erreurs : conversion FLOAT → INT interdite

### Variables globales 
*** Déclaration et utilisation des variables globales avec gestion d'offsets.
*** Gestion dans la table des symboles avec type et offset
*** Vérifications des variables déclarées, compatibilité des types

### Structures de contrôle
*** Instructions conditionnelles if et if-else
*** Boucles while avec gestion d'étiquettes
*** Imbrication des structures de contrôle
*** Génération de labels False_n, End_n, StartLoop_n, EndLoop_0

### Booléens paresseux 
*** Évaluation paresseuse des opérateurs && et ||
*** Génération de code avec branchements conditionnels
*** Labels spécifiques pour l'évaluation paresseuse

### Sous-blocs et variables locales
Utilisation de  la fonction "aff_func" pour :
*** Vérification de la déclaration des variables avant toute utilisation
*** Accès différencié aux variables globales (LOADI) et locales (LOADBP + SHIFT)
*** Gestion hiérarchique de la portée via le depth des blocs
*** Génération de l'instruction STORE pour finaliser l'écriture en mémoire


### Declaration des fonctions et appels
*** Déclaration des fonctions uniquement au niveau global (interdiction dans les blocs)
*** Ajout du nom de fonction dans la table des symboles avec profondeur 0
*** Traitement des paramètres avec numérotation des offsets negatif et en ordre décroissant
*** Génération des valeurs de retour par défaut selon le type de fonction
*** Appel de fonctions avec CALL, sauvegarde et restauration du BP
*** Nettoyage de la pile avec DROP après l'appel


## Exemple et Tests
Le répertoire MyC/ExempleTest contient une suite complète de tests conçus pour valider progressivement
chaque fonctionnalité du compilateur. Chaque test cible un aspect spécifique du langage MyC, permettant
de vérifier l'avancement du projet depuis les expressions arithmétiques de base jusqu'à la gestion avancée 
des fonctions récursives mutuellements.
