// NOEL TP1.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include <iostream>
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <glut.h>
#include <stdio.h>
#include "Forme.h"
#include "Liste.h"

using namespace std;

Liste* maListe = new Liste();
Forme* f = new Forme();

void Init_OpenGL() //permet d'initialiser le fond d'écran
{
    glClearColor(0.5, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void Display_Objects()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();

    for (int i = 0; i < maListe->GetTaille(); i++) //parcours de la liste de formes saisies par l'utilisateur
    {
        f = maListe->GetElementAt(i)->element;

        glTranslatef(f->getPoint().x, f->getPoint().y, f->getPoint().z); //position
        glColor3f(f->getCouleur().R, f->getCouleur().G, f->getCouleur().B); //couleur

        switch (f->getType()) //Selon le type on affiche la forme correspondante
        {
        case Sphere:
            glutSolidSphere(f->getTaille(), f->getResolution().x, f->getResolution().y);
            break;

        case Cone:
            glutSolidCone(1, f->getTaille(), f->getResolution().x, f->getResolution().y);
            break;

        case Theiere:
            glutSolidTeapot(f->getTaille());
            break;

        default:
            glutSolidSphere(f->getTaille(), f->getResolution().x, f->getResolution().y);
            break;
        }
    }
    glPopMatrix();
    glutSwapBuffers();

}

void Reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(-0.3, 0.5, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}


int main(int argc, char** argv)
{
    bool continuer = true;
        
    Point pos = Point();
    pos.x = 0;
    pos.y = 0;
    pos.z = 0;

    Point resolution = Point();
    resolution.x = 15;
    resolution.y = 15;

    Couleur couleur = Couleur();
    couleur.R = 1;
    couleur.G = 0;
    couleur.B = 0;

    int choix = 1;
    int taille = 0;

    do {
        //on demande tous les paramètre à l'utilisateur
        cout << "Type de forme : \n1 - Theiere\n2 - Sphere\n3 - Cone\nVotre choix : ";
        cin >> choix;

        cout << "Entre une position : \nX : ";
        cin >> pos.x;

        cout << "Y : ";
        cin >> pos.y;

        cout << "Z : ";
        cin >> pos.z;

        cout << "Entrez une couleur RGB :\nR : ";
        cin >> couleur.R;

        cout << "G : ";
        cin >> couleur.G;

        cout << "B : ";
        cin >> couleur.B;

        cout << "Entrez la taille : ";
        cin >> taille;

        if (choix != 1) //pas de résolution pour les sphères
        {
            cout << "Entrez la resolution : \nX : ";
            cin >> resolution.x;

            cout << "Y : ";
            cin >> resolution.y;
        }


        switch (choix) //on remplit la liste selon la forme et les paramètres choisis
        {
        case 1:
            maListe->AjouterFin(new Forme(Theiere, pos, resolution, couleur, taille));
            break;
        case 2:
            maListe->AjouterFin(new Forme(Sphere, pos, resolution, couleur, taille));
            break;
        case 3:
            maListe->AjouterFin(new Forme(Cone, pos, resolution, couleur, taille));
            break;
        default:
            maListe->AjouterFin(new Forme(Theiere, pos, resolution, couleur, taille));
            break;
        }

        int c = 0;
        //on propose à l'utilisateur de continuer
        cout << "Voulez-vous continuer ?\n1 - OUI\n2 - NON\nVotre choix : ";
        cin >> c;
        (c == 1) ? continuer = true : continuer = false;

    } while (continuer);

    //On dessine la fenetre avec les formes
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1280, 720);
    glutInitWindowPosition(250, 50);
    Init_OpenGL();
    glutCreateWindow("Maeva NOEL - TP1");
    glutDisplayFunc(Display_Objects);
    glutReshapeFunc(Reshape);
    glutMainLoop();

    return 0;
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
