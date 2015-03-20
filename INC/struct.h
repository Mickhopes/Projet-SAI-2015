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

#define HAUT 0
#define BAS 1
#define DROITE 2
#define GAUCHE 3
#define DESSUS 4
#define DESSOUS 5

#define TAILLE_CUBE 30

typedef struct Point {
	float x;
	float y;
	float z;
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

Point obs, vis, souris;

int tab_key[6];

#endif /* _STRUCT_ */
