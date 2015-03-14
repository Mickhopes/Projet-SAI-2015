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

#include "GL/gl.h"
#include "GL/glut.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600

#define TAILLE_CUBE 20

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

Point obs, vis;

#endif /* _STRUCT_ */
