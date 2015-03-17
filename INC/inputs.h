/****************************************************
 * L3 informatique
 * Projet SAI
 *
 * Auteurs :  - Line Pouvaret
 *            - Mickaël Turnel
 *
 * Fichier : inputs.h
 *
 *****************************************************/

#ifndef _INPUTS_
#define _INPUTS_

extern int pointeur;

void raffraichissement();
void gererClavier(unsigned char touche, int x, int y);
void vMotion(int x, int y);
void deplacerCamera(int dir);

#endif /* _INPUTS */
