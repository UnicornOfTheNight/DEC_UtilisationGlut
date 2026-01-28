# 🧊 DEC Utilisation GLUT (OpenGL)

![Language](https://img.shields.io/badge/Language-C%2B%2B-blue)
![Library](https://img.shields.io/badge/Library-OpenGL%20%2F%20GLUT-green)
![License](https://img.shields.io/badge/License-MIT-blue)

Ce dépôt contient des exercices et expérimentations réalisés dans le cadre du cursus **DEC**, visant à maîtriser la bibliothèque **GLUT** (OpenGL Utility Toolkit) pour la création d'applications graphiques 3D.

## 📖 Description

L'objectif de ce projet est de comprendre le pipeline graphique de base d'OpenGL (souvent en mode immédiat ou "Legacy OpenGL") à travers l'interface simplifiée de GLUT.
Il permet d'appréhender les concepts fondamentaux de la 3D :
* Le système de coordonnées (X, Y, Z).
* Les transformations matricielles (Rotation, Translation, Mise à l'échelle).
* La boucle de rendu (`MainLoop`).
* La gestion des événements (Clavier/Souris).

## 🚀 Fonctionnalités & Démos

Le projet inclut plusieurs démonstrations techniques :

* **Création de fenêtre** : Initialisation d'un contexte OpenGL via `glutInit`.
* **Primitives 3D** : Affichage de formes simples (Cubes, Sphères, et la célèbre *Utah Teapot* `glutSolidTeapot`).
* **Caméra** : Positionnement de la caméra virtuelle avec `gluLookAt`.
* **Éclairage (Lighting)** : Mise en place de sources de lumière simples et de matériaux basiques.
* **Interactions** : Rotation ou déplacement des objets via les touches du clavier.

## 🛠 Prérequis Techniques

Pour compiler et exécuter ce projet, vous avez besoin de :

1.  **Compilateur C++** (GCC ou MSVC via Visual Studio).
2.  **Bibliothèques OpenGL** (généralement incluses dans les drivers graphiques).
3.  **Bibliothèque GLUT ou FreeGLUT** : Installer via NuGet dans Visual Studio (`nupengl.core`) ou lier les fichiers `.lib` et `.dll`.

## 💻 Installation & Compilation

### Sous Visual Studio (Windows)
1.  Clonez le dépôt :
    ```bash
    git clone [https://github.com/UnicornOfTheNight/DEC_UtilisationGlut.git](https://github.com/UnicornOfTheNight/DEC_UtilisationGlut.git)
    ```
2.  Ouvrez le fichier solution `.sln`.
3.  Assurez-vous que les dépendances (NuGet ou Linker) pour GLUT sont configurées.
4.  Compilez et lancez (`F5`).

## 🎮 Commandes (Contrôles)

| Touche | Action |
| :--- | :--- |
| **Flèches** | Faire tourner l'objet / Bouger la caméra |
| **Z / S** | Zoom Avant / Arrière |
| **F1** | Changer le mode d'affichage (Fil de fer / Plein) |
| **Echap** | Quitter l'application |

*(Ces commandes sont données à titre indicatif, référez-vous au code source `keyboardFunc` pour les détails exacts)*

## 🧠 Concepts Abordés

* `glBegin()` / `glEnd()` : Dessin de vertex.
* `glPushMatrix()` / `glPopMatrix()` : Gestion de la pile de matrices pour isoler les transformations.
* `glutIdleFunc()` : Gestion de l'animation (temps réel).
* `glutReshapeFunc()` : Gestion du redimensionnement de la fenêtre.

## 👤 Auteur

* **UnicornOfTheNight** - *Étudiant DEC*

---
*Projet réalisé à des fins pédagogiques.*
