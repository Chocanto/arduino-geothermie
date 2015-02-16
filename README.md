Compiler le projet
==================

Dépendances
-----------

La compilation du projet nécessite l'installation des bibliothèques suivantes :

* git
* cmake
* libgtest-dev
* libmysqlcppconn-dev
* libboost-dev
* arduino
* libboost-dev

Compiler le serveur
-------------------

### Compiler gtest

* `cd /usr/src/gtest`
* `sudo cmake .`
* `sudo make`
* `sudo mv libg* /usr/lib/`

### Compiler le serveur

* `cd server/`
* `cmake .`
* `make`

Compiler le framework arduino
---------------------------

### Télécharger/mettre à jour les sources restantes

* `git submodule init`
* `git submodule update`

### Compiler le framework

* `cd arduino`
* `mkdir build`
* `cd build`
* `cmake ..`
* `make`

Installer le binaire dans l'arduino
===================================

* `make upload`

Configurer le serveur
=====================

Copiez le fichier `config.json.example` vers `config.json` puis éditez le
en paramétrant les valeurs disponibles.

Lancer le serveur
=================

Lancer `./bin/server` dans un terminal.

Tester le projet
================

Le projet est livré avec une suite de tests unitaires.
Pour les executer :

* `cd test/bin/`
* `ctest`

Pour avoir l'affichage détaillé d'un test l'executer seul :

`./le_test`
