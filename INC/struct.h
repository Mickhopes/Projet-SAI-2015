/****************************************************
 * L3 informatique
 * Projet SAI
 *
 * Auteurs :  - Line Pouvaret
 *            - Mickaël Turnel
 *
 * Fichier : struct.h
 *
 *****************************************************/

#ifndef _STRUCT_
#define _STRUCT_

typedef struct Point {
	int x;
	int y;
	int z;
}Point;

typedef struct Cell {
	int x, y, z;
	int MUR_HAUT;
	int MUR_BAS;
	int MUR_GAUCHE;
	int MUR_DROITE;
	int MUR_AVANT;
	int MUR_ARRIERE;
	int VISITED;
}Cell;

typedef struct Element {
	Cell *cell;
	struct Element *suivant;
}Element;

typedef struct Pile {
	int nb_elem;
	Element *debut;
	Element *sommet;
}Pile;

typedef struct Maze {
	int width, length, height;
	Cell*** cases;
}Maze;

#endif /* _STRUCT_ */
