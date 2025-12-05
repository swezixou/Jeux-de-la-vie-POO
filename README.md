# Jeux-de-la-vie-POO
Projet POO - Jeu de la Vie en C++ (Console + SFML)

🎮 Projet : Jeu de la Vie – Implémentation en C++ orienté objet

Auteurs :

Aymen Brahimi

Abdelkarim Laabani

📌 Description du projet

Ce projet implémente le célèbre Jeu de la Vie de Conway en C++, en appliquant strictement les principes de la Programmation Orientée Objet, dont SOLID.
L’application propose deux modes :

Mode console : exécute la simulation et génère les états successifs dans des fichiers .txt.

Mode graphique (SFML) : visualisation animée de la grille, HUD, interactions souris, vitesse variable, et fond animé.

Ce projet a été réalisé dans le cadre de l’UE Programmation Orientée Objet.

🧱 Architecture du projet
PROJECT  
│  
├── application/       → Moteur du jeu (Game), gestion fichiers (FileManager)  
├── domain/            → Logique métier : Cell, AliveCell, DeadCell, Rule, Grid  
├── presentation/      → Rendu console et SFML (ConsoleRenderer, SFMLRenderer)  
├── src/               → Implémentations .cpp  
├── include/           → Fichiers .hpp  
├── data/              → Textures, audio, fichiers initiaux  
└── testuni/           → Tests unitaires

🧠 Application complète des principes SOLID

🎯 S – Single Responsibility
Chaque classe fait une seule chose (Grid gère la grille, Renderer l’affichage, Rule les règles…).

🎯 O – Open / Closed
On peut ajouter des règles (ex : HighLife), des types de cellules, ou même un autre moteur graphique sans toucher au code existant.

🎯 L – Liskov Substitution
Toutes les classes héritées peuvent remplacer leur parent sans casser la logique.

🎯 I – Interface Segregation
Interfaces fines :

Cell → isAlive(), clone()

Rule → apply()

Renderer → render(), handleEvents(), isOpen()

🎯 D – Dependency Inversion
Game dépend de Renderer (abstraction), pas de SFML.
Grid dépend de Rule, pas de ConwayRule.

Résultat : un code propre, modulable, extensible.

🎨 Mode graphique (SFML)
✔ Fonctionnalités

Affichage complet des cellules

HUD dynamique : itération, pause, vitesse

Fond animé (scrolling) + pixel art

Musique SFML (activée par défaut)

Clic souris pour modifier la grille :

🖱️ Gauche → cellule vivante

🖱️ Droite → cellule morte

| Touche | Action        |
| ------ | ------------- |
| Espace | Pause / Play  |
| Entrée | Step          |
| →      | Accélérer     |
| ←      | Ralentir      |
| M      | Mute / Unmute |
| Échap  | Quitter       |

🖥️ Mode console

Charge un fichier ou génère une grille aléatoire

Exécute N itérations

Exporte chaque génération dans un dossier :

<nom_fichier>_out/



Parfait pour les corrections automatiques.

🧪 Tests unitaires

Les tests comparent :

✔ la grille obtenue
✔ la grille attendue (fichier .txt)

Commande :

<img width="647" height="155" alt="{457AF3F4-99D0-4C8E-82D5-1B3BF56BD2C2}" src="https://github.com/user-attachments/assets/b4abebbf-6233-46d4-a1c1-27dea7dffe28" />



Diff affiché en cas d’erreur ➝ ligne/colonne exacte.

⚙️ Compilation & Exécution
🔧 Compiler

<img width="1110" height="246" alt="{671A2624-9AD8-465C-BD7B-AACE459EA149}" src="https://github.com/user-attachments/assets/5db31e91-333c-4c08-acf9-c5c92070c9cf" />


▶️ Lancer
./bin/game_of_life

🧹 Nettoyer

<img width="628" height="56" alt="{4283F375-5C0B-45A4-89E2-1F75697E3840}" src="https://github.com/user-attachments/assets/cab4f109-16d7-4c49-b4eb-7ffc1ffeea48" />


⚠️ Makefile : Linux & Windows

Dans le Makefile :

# Sous Linux :
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

# Sous Windows (MinGW) :
# SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lopengl32 -lfreetype -lsfml-audio


👉 Décommenter la version Windows si vous compilez sous MinGW.

🏁 Conclusion

Ce projet illustre :

une architecture robuste

une maîtrise avancée de la POO

une application rigoureuse de SOLID

un rendu graphique complet et interactif

un système de test fiable

Il est facilement extensible : grille torique, obstacles, nouveaux patterns, multithreading…
un système de tests fiable et automatisé.

Le code est entièrement documenté et conçu pour être facilement extensible.
