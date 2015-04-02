/****************************************************
 * L3 informatique
 * Projet SAI
 *
 * Auteurs :  - Line Pouvaret
 *            - Micka�l Turnel
 *
 * Fichier : objects.h
 *
 *****************************************************/

#ifndef _OBJECTS_
#define _OBJECTS_

#include "struct.h"
#include "maze.h"

void labyrinthe(Maze *maze);
void fleche_montee(int x, int y, int z);
void fleche_descente(int x, int y, int z);

#endif /* _OBJECTS_ */
