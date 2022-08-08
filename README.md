# IRC

## Introduction

Irc est un projet consistant à monter un serveur temps réel permetant aux clients qui y sont connectés de communiquer entre eux.

## Contraintes

Le but du projet étant défini penchons nous maintenant sur les contraintes du projet. 
Les serveurs IRC doivent répondre aux normes <a href="http://abcdrfc.free.fr/rfc-vf/rfc1459.html">RCF 1459</a>

## Comment ca marche ?

La norme RCF a pour but de poser les règles de communication entre les serveurs IRC et les clients IRC.
Ainsi, cette norme s'organise autour d'un set de commandes permettentant d'effectuer des actions sur le serveur.
A chacune de ces commandes le serveur IRC devra agir en conséquant puis faire remonter le succès ou pas de la réalistation de la commande via des codes d'erreur (ERR_X) ou des codes réponse (RPL_X).

## To do list

_ Terminer la connexion client
_ Deconnexion client
_ Spliter de commande
_ Parser de commande
_ Client
	- > Reponse
_ Implementer les commandes 
	_ Auth
		- USER 
		- NICK
		- PASS 
		_ DIE
		_ QUIT
	_ Server
		_ WHO 
		_ LIST
		_ HELP
	_ Chat
		_ PRIVMSG
		_ NOTICE
		_ JOIN
		_ WHO (D)
		_ KICK
		_ PART



## Notre organisation

Une fois la norme RCF décortiqué deux grandes parties dans ce projet sont mises en evidence.

### Partie 1 : Mise en place d'un réseau

Log 1 : On parvient a lancer un socket ! 
Log 2 : On parvient a capter une nouvelle connexion !
Executez : c++ srcs/main.cpp srcs/network/Server.cpp srcs/Utils.cpp 
puis  ./a.out "20" "password"

En cours...

### Partie 2 : Mise en place des commandes

En cours...

## Créateurs

Tbillion & Grosendo