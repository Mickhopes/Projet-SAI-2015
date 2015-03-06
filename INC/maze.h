/****************************************************
 * L3 informatique
 * Projet SAI
 *
 * Auteurs :  - Line Pouvaret
 *            - Mickaël Turnel
 *
 * Fichier : maze.h
 *
 *****************************************************/

#ifndef _MAZE_
#define _MAZE_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 

/* Structure pour la génération du labyrinthe */
typedef struct Cell {
	int MUR_HAUT;
	int MUR_BAS;
	int MUR_GAUCHE;
	int MUR_DROITE;
	int MUR_AVANT;
	int MUR_ARRIERE;
	int VISITED;
}Cell;

typedef struct Maze {
	int width, length, heigth;
	Cell*** cases;
}Maze;


/* variable labyrinthe */
Maze maze;

/* Initialisation du labyrinthe labyrinthe */
int init_maze(Maze *maze, int width, int length, int heigth);

/* Libération du labyrinthe */
void free_maze(Maze *maze);

/* Génération du labyrinthe */
void generate_maze(Maze *maze);
Cell* random_unvisited_neighbour(Maze *maze, Cell *c, int x, int y, int z);
void carve_maze(Maze *maze, Pile *p, int x, int y, int z);

#endif /* _MAZE_ */