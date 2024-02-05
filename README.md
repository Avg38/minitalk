# minitalk
Le projet Minitalk est un exercice de programmation en langage C dans le cadre du cursus de l'école 42. L'objectif de ce projet est de créer un système de communication simple entre un client et un serveur en utilisant les signaux UNIX.

## Description
Le projet consiste en deux programmes : un serveur et un client. Le serveur est chargé d'écouter les signaux envoyés par le client, tandis que le client envoie des signaux au serveur pour transmettre des données. Le protocole de communication est basé sur l'utilisation des signaux `SIGUSR1` et `SIGUSR2`.

## Fonctionnalités
Le serveur affiche son PID lors de son démarrage.
Le client prend en argument le PID du serveur.
Le client envoie des données textuelles au serveur en convertissant chaque caractère en une séquence de signaux.
Le serveur reçoit les signaux, les interprète et affiche les données reçues.
## Compilation
Pour compiler le projet, utilisez le Makefile fourni. Exécutez la commande suivante dans le répertoire racine du projet :
```bash
make
```
Cela générera les exécutables `client` et `serveur`.
## Utilisation
Lancez le serveur en exécutant `./serveur`. Notez le PID affiché.
Lancez le client en spécifiant le PID du serveur comme argument : `./client <PID_SERVEUR>`.
Le client est prêt à envoyer des données au serveur. Suivez les instructions affichées pour entrer des données.
## Exemple
```bash
$ ./serveur
Serveur PID: 12345
```
```bash
$ ./client 12345
Entrez votre message : Hello, Minitalk!
```
```bash
Serveur: Hello, Minitalk!
```