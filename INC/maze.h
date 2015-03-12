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
#include "struct.h"
#include "pile.h"

/* variable labyrinthe */
Maze maze;

/* Initialisation du labyrinthe labyrinthe */
int init_maze(Maze *maze, int width, int length, int height);

/* Libération du labyrinthe */
void free_maze(Maze *maze);

/* Fonctions nécesaires à la génération du labyrinthe */
Cell* random_unvisited_neighbour(Maze *maze, Cell *c);
void remove_walls(Cell *c, Cell *v);

/* Génération du labyrinthe */
void generate_maze(Maze *maze);
void carve_maze(Maze *maze, Pile *p, int x, int y, int z);

/* Affichage du labyrinthe */
void show_maze(Maze *maze);

#endif /* _MAZE_ */
