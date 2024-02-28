#include "Liste.h"
#include <iostream>

using namespace std;

/**@brief : Constructeur */
Liste::Liste()
{
	_debut = NULL;
}

/**@brief : Destructeur*/
Liste::~Liste()
{
	delete _debut;
}

/**@brief Permet d'ajouter un élément au début de la liste
   @param Forme* p_element : forme à ajouter */
void Liste::AjouterDebut(Forme* p_element)
{
	if (_debut == NULL)
	{
		_debut = new noeud();
		_debut->element = p_element;
		_debut->suivant = NULL;
	}
	else
	{
		noeud* temp = new noeud();
		temp->element = p_element;
		temp->suivant = _debut;

		_debut = temp;
	}
	_taille++;
}

/**@brief Permet d'ajouter un élément à la fin de la liste
   @param Forme* p_element : forme à ajouter */
void Liste::AjouterFin(Forme* p_element)
{
	if (_debut == NULL)
	{
		AjouterDebut(p_element);
	}
	else
	{
		noeud* temp = _debut;
		while (temp->suivant != NULL) {
			temp = temp->suivant;
		}
		temp->suivant = new noeud();
		temp->suivant->element = p_element;
		temp->suivant->suivant = NULL;
		_taille++;
	}
}

/**@brief : Permet d'effacer un élément de la liste
   @param noeud* p_element : noeud à effacer de la liste*/
void Liste::Effacer(noeud* p_element)
{
	noeud* temp = _debut;

	if (p_element == temp) //Si c'est le premier element
	{
		temp->element = temp->suivant->element;
		temp->suivant = temp->suivant->suivant;
	}
	else {
		//si le noeud suivant est celui qu'il faut effacer alors on le remplace par le suivant du suivant pour l'effacer
		while (temp->suivant->element != p_element->element && temp->suivant->suivant != p_element->suivant) {
			temp = temp->suivant;
		}
		temp->suivant = temp->suivant->suivant;
	}
	_taille--;
}

/**@brief : accesseur sur la taille du tableau
   @return taille du tableau */
int Liste::GetTaille()
{
	return _taille;
}

/**@brief : permet d'insérer un noeud dans la liste
   @param noeud* p_noeud : position d'insertion
   @param Forme* p_element : element à inserer dans la liste*/
void Liste::InsererAvant(noeud* p_noeud, Forme* p_element)
{
	noeud* n_loop = _debut;

	while (n_loop->suivant != p_noeud) {
		n_loop = n_loop->suivant;
	}	

	noeud* temp = new noeud();
	temp->element = p_element;
	temp->suivant = n_loop->suivant;
	n_loop->suivant = temp;

	_taille++;
}

/**@brief : permet d'insérer un noeud dans la liste
   @param noeud* p_noeud : position d'insertion
   @param Forme* p_element : element à inserer dans la liste*/
void Liste::InsererApres(noeud* p_noeud, Forme* p_element)
{	
	noeud* n_loop = _debut;

	while (n_loop->suivant != p_noeud->suivant) {
		n_loop = n_loop->suivant;
	}		

	noeud* temp = new noeud();
	temp->element = p_element;
	temp->suivant = n_loop->suivant;
	n_loop->suivant = temp;

	_taille++;
}

/**@brief Permet d'accéder à un élément de la liste à un index donné
   @param int p_index
   @return noeud* élément à l'index passé en paramètre */
noeud* Liste::GetElementAt(int p_index)
{
	if (p_index <= _taille)
	{
		noeud* temp = _debut;
		for (int i = 0; i < p_index; i++)
			temp = temp->suivant;

		return temp;
	}
	else
		return NULL;
}