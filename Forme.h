#pragma once
enum TypeForme
{
	Theiere,
	Cone,
	Sphere
};

struct Point
{
	int x;
	int y;
	int z;
};

struct Couleur
{
	float R, G, B;
};

class Forme
{
private:
	Couleur _couleur;
	Point _point;
	Point _resolution;
	TypeForme _type;
	float _taille;
public:
	Forme();
	Forme(TypeForme p_type, Point p_Position, Point p_Resolution, Couleur p_Couleur, float p_taille);
	~Forme();
	Couleur getCouleur();
	Point getPoint();
	TypeForme getType();
	Point getResolution();
	float getTaille();
};

