/****************************************************
 * L3 informatique
 * Projet SAI
 *
 * Auteurs :  - Line Pouvaret
 *            - Mickaël Turnel
 *
 * Fichier : objects.h
 *
 *****************************************************/

#ifndef _OBJECTS_
#define _OBJECTS_

#include "struct.h"
#include "maze.h"

void labyrinthe(Maze *maze);
void mettre_fleche_montee(int x, int y, int z);
void mettre_fleche_descente(int x, int y, int z);
void fleche_montee();
void fleche_descente();
void helico();

#endif /* _OBJECTS_ */
