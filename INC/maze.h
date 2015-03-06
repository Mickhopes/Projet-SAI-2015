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
int init_maze(Maze *maze, int width, int length, int heigth);

/* Libération du labyrinthe */
void free_maze(Maze *maze);

/* Génération du labyrinthe */
void generate_maze(Maze *maze);
Cell* random_unvisited_neighbour(Maze *maze, int x, int y, int z);
void carve_maze(Maze *maze, Pile *p, int x, int y, int z);

#endif /* _MAZE_ */