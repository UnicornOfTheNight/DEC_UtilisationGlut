#pragma once
#include <iostream>
#include "Forme.h"

struct noeud
{
	Forme* element;
	noeud* suivant;
};

class Liste
{
public:
	Liste();
	~Liste();

	void AjouterDebut(Forme* element);
	void AjouterFin(Forme* element);
	void Effacer(noeud* element);
	int GetTaille();
	void InsererAvant(noeud* noeud, Forme* element);
	void InsererApres(noeud* noeud, Forme* element);
	noeud* GetElementAt(int index);


private:
	noeud* _debut;
	int _taille = 0;
};

