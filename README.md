# Jeux-de-la-vie-POO
Projet POO - Jeu de la Vie en C++ (Console + SFML)

🎮 Projet : Jeu de la Vie – Implémentation en C++ orienté objet

Auteurs :

Aymen Brahimi

Abdelkarim Labaani

📌 Description du projet

Ce projet implémente le célèbre Jeu de la Vie de Conway en C++, en appliquant strictement les principes de la Programmation Orientée Objet, dont SOLID.
L’application propose deux modes :

Mode console : exécute la simulation et génère les états successifs dans des fichiers .txt.

Mode graphique (SFML) : visualisation animée de la grille, HUD, interactions souris, vitesse variable, et fond animé.

Ce projet a été réalisé dans le cadre de l’UE Programmation Orientée Objet.

🧱 Architecture générale du projet

Le code est structuré selon une architecture en couches permettant une séparation claire des responsabilités :

PROJECT  
│  
├── application/       → Moteur du jeu (Game), gestion fichiers (FileManager)  
├── domain/            → Logique métier : Cell, AliveCell, DeadCell, Rule, Grid  
├── presentation/      → Rendu console et SFML (ConsoleRenderer, SFMLRenderer)  
├── src/               → Implémentations .cpp  
├── include/           → Fichiers .hpp  
├── data/              → Textures, audio, fichiers initiaux  
└── testuni/           → Tests unitaires


Cette organisation respecte pleinement le principe SRP (Single Responsibility Principle).

🧠 Principes SOLID appliqués
✔ S — Single Responsibility

Chaque classe a une responsabilité unique :

Grid gère les cellules

Rule applique la règle d’évolution

Renderer gère l’affichage

Game orchestre la simulation

FileManager lit/écrit les fichiers

✔ O — Open / Closed

Ajouter une règle (HighLifeRule) ou un renderer (SDLRenderer) ne nécessite aucune modification du code existant.

✔ L — Liskov Substitution

Toutes les classes dérivées (AliveCell, ConsoleRenderer, etc.) peuvent remplacer leur classe mère sans comportement inattendu.

✔ I — Interface Segregation

Interfaces minimales :

Cell → isAlive(), clone()

Rule → apply()

Renderer → render(), handleEvents(), isOpen()

✔ D — Dependency Inversion

Les classes de haut niveau dépendent d’abstractions et non d’implémentations :

Game utilise Renderer*

Grid utilise Rule*

🎨 Fonctionnalités du mode graphique (SFML)

Affichage animé de la grille

Fond animé (scrolling)

HUD dynamique (vitesse, état pause, numéro d’itération)

Musique de fond

Clic gauche/droit pour créer ou supprimer une cellule

Contrôles :

ESPACE → pause

Entrée → itération étape par étape

Flèche droite → accélérer

Flèche gauche → ralentir

🧪 Tests unitaires

Un système de test compare automatiquement :

la grille obtenue après N itérations

la grille attendue fournie dans un fichier .txt

Commande :

make test


Les résultats indiquent clairement si une différence existe (ligne, colonne).

▶️ Compilation & Exécution
🔧 Compilation générale
make

🖥️ Lancer le programme
./bin/game_of_life


L’utilisateur choisit ensuite :

le mode (console / graphique)

le type d’initialisation (fichier / aléatoire)

le nombre d’itérations

🔄 Nettoyer
make clean

📂 Exemples de fichiers d’entrée

Format :

5 10
0 0 1 0 0 0 0 0 0 0
0 0 0 1 0 0 0 0 0 0
0 1 1 1 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0

🏁 Conclusion

Ce projet démontre :

une maîtrise avancée de la programmation orientée objet en C++,

une application rigoureuse des principes SOLID,

une architecture modulaire, extensible et propre,

un rendu graphique complet grâce à SFML,

un système de tests fiable et automatisé.

Le code est entièrement documenté et conçu pour être facilement extensible.
