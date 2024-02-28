#include "Forme.h"

/**@brief constructeur*/
Forme::Forme() {
	_type = Sphere;
	_taille = 0.0f;
	Point p = Point();
	p.x = 0;
	p.y = 0;
	p.z = 0;
	_point = p;
	Couleur c = Couleur();
	c.B = 0;
	c.R = 0;
	c.G = 0;
	_couleur = c;
	Point r = Point();
	r.x = 0;
	r.y = 0;
	_resolution = r;
}

/**@brief surcharge constructeur*/
Forme::Forme(TypeForme p_type, Point p_Position, Point p_Resolution, Couleur p_Couleur, float p_taille)
{
	_type = p_type;
	_point = p_Position;
	_couleur = p_Couleur;
	_resolution = p_Resolution;
	_taille = p_taille;
}

/**@brief destructeur */
Forme::~Forme() {
}

/** Les accesseurs */
Couleur Forme::getCouleur() {
	return _couleur;
}

Point Forme::getPoint() {
	return _point;
}

TypeForme Forme::getType() {
	return _type;
}

Point Forme::getResolution() {
	return _resolution;
}

float Forme::getTaille() {
	return _taille;
}