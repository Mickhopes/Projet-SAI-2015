/****************************************************
 * L3 informatique
 * Projet SAI
 *
 * Auteurs :  - Line Pouvaret
 *            - Mickaël Turnel
 *
 * Fichier : pile.c
 *
 *****************************************************/

#include "pile.h"

void initialiserPile(Pile *p) {
	p->nb_elem = 0;
	p->debut = NULL;
	p->sommet = NULL;
}

void empilerCell(Pile *p, Cell *c) {
  Element *e = malloc(sizeof(Element));
  e->cell = c;
  e->suivant = NULL;

  if (p->debut == NULL) 
  {
    p->debut = e;
  }
  else
  {
    (p->sommet)->suivant = e;
  }
  p->sommet = e;
  p->nb_elem++;
}

void depiler(Pile *p) {
  Element *courant, *precedent;
  if (p->debut != NULL)
  {
    courant = p->debut;
    precedent = NULL;
    while(courant != NULL)
    {
      precedent = courant;
      courant = precedent->suivant;
    }
    if (precedent != NULL)
    {
      free(precedent->suivant);
      precedent->suivant = NULL;
      p->sommet = precedent;
      p->nb_elem--;
    }
  }
}

void vider(Pile *p) {
  Element *c, *s;
  if (p->debut != NULL) {
    c = NULL;
    s = p->debut;
    while(s != NULL)
    {
      c = s;
      s = s->suivant;
      free(c);
    }
    initialiserPile(p);
  }
}

int estVide(Pile *p) {
  if (p->debut == NULL)
   {
      return 1;
   }
  return 0;
}

Element* accederSommet(Pile *p) {
  return p->sommet;
}