/****************************************************
 * L3 informatique
 * Projet SAI
 *
 * Auteurs :  - Line Pouvaret
 *            - Mickaël Turnel
 *
 * Fichier : pile.h
 *
 *****************************************************/

#ifndef _PILE_
#define _PILE_

#include "struct.h"

void initialiserPile(Pile *p);

void empilerCell(Pile *p, Cell *e);

void depiler(Pile *p);

void vider(Pile *p);

int estVide(Pile *p);

Element* accederSommet(Pile *p);

#endif /* _PILE_ */
