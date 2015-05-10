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

void sol();
void labyrinthe(Maze *maze);
void mettre_fleche_montee(int x, int y, int z);
void mettre_fleche_descente(int x, int y, int z);
void fleche_montee();
void fleche_descente();
void helico(int xH, int yH, int zH);
void para_rect(float x1, float y1, float z1, float x2, float y2, float z2);
void hud();

#endif /* _OBJECTS_ */
