/****************************************************
 * L3 informatique
 * Projet SAI
 *
 * Auteurs :  - Line Pouvaret
 *            - Mickaël Turnel
 *
 * Fichier : maze.c
 *
 *****************************************************/

#include "maze.h"

int level;

int init_maze(Maze *maze, int width, int length, int height) {
	int i, j, k;

	maze->width = width;
	maze->length = length;
	maze->height = height;

	/* Première dimension */
	if ((maze->cases = (Cell***)malloc(width*sizeof(Cell**))) == NULL) {
		return 0;
	}

	for(i = 0; i < width; i++) {
		/* Seconde dimension */
		if ((maze->cases[i] = (Cell**)malloc(length*sizeof(Cell*))) == NULL) {
			return 0;
		}

		for(j = 0; j < length; j++) {
			/* Troisième dimension */
			if ((maze->cases[i][j] = (Cell*)malloc(height*sizeof(Cell))) == NULL) {
				return 0;
			}

			for(k = 0; k < height; k++) {
				/* On initialise tous les murs à 1 */
				maze->cases[i][j][k].MUR_HAUT = 1;
				maze->cases[i][j][k].MUR_BAS = 1;
				maze->cases[i][j][k].MUR_GAUCHE = 1;
				maze->cases[i][j][k].MUR_DROITE = 1;
				maze->cases[i][j][k].MUR_AVANT = 1;
				maze->cases[i][j][k].MUR_ARRIERE = 1;
				maze->cases[i][j][k].VISITED = 0;
				maze->cases[i][j][k].x = i;
				maze->cases[i][j][k].y = j;
				maze->cases[i][j][k].z = k;
			}
		}
	}

	return 1;
}

void free_maze(Maze *maze) {
	int i, j;
	for(i = 0; i < maze->width; i++) {
		for(j = 0; j < maze->length; j++) {
			free(maze->cases[i][j]);
		}
		free(maze->cases[i]);
	}
	free(maze->cases);
}

Cell* random_unvisited_neighbour(Maze *maze, Cell *c) {
	int tx[6], ty[6], tz[6];
	int nb_voisins, all_visited, i, r;

	nb_voisins = 0;

	/* On regarde les voisins possibles en x */
	if (c->x == 0) {
		tx[nb_voisins] = c->x+1;
		ty[nb_voisins] = c->y;
		tz[nb_voisins] = c->z;
		nb_voisins++;
	} else if (c->x == maze->width-1) {
		tx[nb_voisins] = c->x-1;
		ty[nb_voisins] = c->y;
		tz[nb_voisins] = c->z;
		nb_voisins++;
	} else {
		tx[nb_voisins] = c->x+1;
		ty[nb_voisins] = c->y;
		tz[nb_voisins] = c->z;
		tx[nb_voisins+1] = c->x-1;
		ty[nb_voisins+1] = c->y;
		tz[nb_voisins+1] = c->z;
		nb_voisins = nb_voisins+2;
	}

	/* On regarde les voisins possible en y */
	if (c->y == 0) {
		tx[nb_voisins] = c->x;
		ty[nb_voisins] = c->y+1;
		tz[nb_voisins] = c->z;
		nb_voisins++;
	} else if (c->y == maze->length-1) {
		tx[nb_voisins] = c->x;
		ty[nb_voisins] = c->y-1;
		tz[nb_voisins] = c->z;
		nb_voisins++;
	} else {
		tx[nb_voisins] = c->x;
		ty[nb_voisins] = c->y+1;
		tz[nb_voisins] = c->z;
		tx[nb_voisins+1] = c->x;
		ty[nb_voisins+1] = c->y-1;
		tz[nb_voisins+1] = c->z;
		nb_voisins = nb_voisins+2;
	}

	/* Si on a parcouru CASES_MIN cases et qu'on a pas déjà STAIRS_MAX passerelles entre deux niveaux */
    if(count[level] >= CASES_MIN && stairs[level] < STAIRS_MAX){
        /* On regarde les voisins possibles en z */
        if (c->z == 0) {
            tx[nb_voisins] = c->x;
            ty[nb_voisins] = c->y;
            tz[nb_voisins] = c->z+1;
            nb_voisins++;
        } else if (c->z == maze->height-1) {
            tx[nb_voisins] = c->x;
            ty[nb_voisins] = c->y;
            tz[nb_voisins] = c->z-1;
            nb_voisins++;
        } else {
            tx[nb_voisins] = c->x;
            ty[nb_voisins] = c->y;
            tz[nb_voisins] = c->z+1;
            tx[nb_voisins+1] = c->x;
            ty[nb_voisins+1] = c->y;
            tz[nb_voisins+1] = c->z-1;
            nb_voisins = nb_voisins+2;
        }
    }

	/* On regarde si tous les voisins ont été visité */
	all_visited = 0;
	for(i = 0; i < nb_voisins; i++) {
		if (maze->cases[tx[i]][ty[i]][tz[i]].VISITED == 1) {
			all_visited++;
		}
	}

	/* Tous les voisins de la cases (x,y,z) ont été visité */
	if (all_visited == nb_voisins) {
		return NULL;
	}

	/* On sait qu'il y a un voisin non visité alors on prends les coordonées aléatoirement jusqu'a tombé sur un */
	do {
		r = rand()%nb_voisins;
	} while(maze->cases[tx[r]][ty[r]][tz[r]].VISITED == 1);

    /* la case c courante est en dessous de la case random */
    if(c->z == tz[r]-1){
        //count[level] = 0;
        stairs[level]++;
        level++;
    }
    else if(c->z == tz[r]+1){
        //count[level] = 0;
        level--;
    }

	return &(maze->cases[tx[r]][ty[r]][tz[r]]);
}

void remove_walls(Cell *c, Cell *v) {
	/* Si le voisin de c est à gauche ou à droite */
	if (v->x == c->x+1) {
		v->MUR_GAUCHE = 0;
		c->MUR_DROITE = 0;
	} else if (v->x == c->x-1){
		c->MUR_GAUCHE = 0;
		v->MUR_DROITE = 0;
	}

	/* Si le voisin de c est devant ou derrière */
	if (v->y == c->y+1) {
		v->MUR_AVANT = 0;
		c->MUR_ARRIERE = 0;
	} else if (v->y == c->y-1){
		c->MUR_AVANT = 0;
		v->MUR_ARRIERE = 0;
	}

	/* Si le voisin de c est au dessus ou en dessous */
	if (v->z == c->z+1) {
		v->MUR_BAS = 0;
		c->MUR_HAUT = 0;
	} else if (v->z == c->z-1){
		c->MUR_BAS = 0;
		v->MUR_HAUT = 0;
	}
}

void generate_maze(Maze *maze) {
    int i;
    level = 0;

	srand(time(NULL));

    /* On initialise nos tableaux */
    for(i = 0;i<TAILLE_LABY;i++){
        count[i] = 0;
        stairs[i] = 0;
    }

	/* On initialise la pile qui va servir à stocker nos chemins dans le labyrinthe */
	Pile p;
	initialiserPile(&p);

	/* On lance l'algorithme récursif à partir de notre case initiale */
	carve_maze(maze, &p, 0, 0, 0);

	/* On enlève les murs nécessaires au batiment */
	maze->cases[0][0][0].MUR_GAUCHE = 0;
	maze->cases[maze->width-1][maze->length-1][maze->height-1].MUR_HAUT = 0;
}

void carve_maze(Maze *maze, Pile *p, int x, int y, int z) {
	Cell *courant = &(maze->cases[x][y][z]);
	Cell *voisin;

    /* On met notre cellule courante visitée */
	courant->VISITED = 1;

	/* On essaie de récupérer un voisin non visité */
	voisin = random_unvisited_neighbour(maze, courant);

	/* Si il en existe, on empile la cellule actuelle, on supprime les murs entre celle ci et sa cellule voisine
     * et on rappelle notre fonction avec la cellule voisine
     * Sinon si notre pile est non vide on la dépile et on rappelle notre fonction avec le sommet de la pile
     */
	if (voisin != NULL) {
	    /* on avance d'une case */
	    count[level]++;
		empilerCell(p, courant);
		remove_walls(courant, voisin);
		carve_maze(maze, p, voisin->x, voisin->y, voisin->z);
	} else {
		if (!estVide(p)) {
			voisin = accederSommet(p)->cell;
			depiler(p);
			carve_maze(maze, p, voisin->x, voisin->y, voisin->z);
		}
	}
}

void show_maze(Maze *maze) {
    int x, y, z, i;

    for(z = 0; z < maze->height; z++) {
	    printf("Level %d:\n", z);
	    for(y = 0; y < maze->length; y++) {
            printf("____");
	    }
	    printf("\n");
        for(x = 0; x < maze->width; x++) {
            printf("|");
            for(y = 0; y < maze->length; y++) {
        		if (maze->cases[x][y][z].MUR_BAS == 0 && maze->cases[x][y][z].MUR_HAUT == 0) {
                    printf("  x");
                } else if (maze->cases[x][y][z].MUR_BAS == 0) {
                    printf("  -");
                } else if (maze->cases[x][y][z].MUR_HAUT == 0) {
                    printf("  +");
                } else {
                    printf("   ");
                }
                if (maze->cases[x][y][z].MUR_ARRIERE == 1) {
                    printf("|");
                } else {
                    printf(" ");
                }
            }
            printf("\n|");
            for(y = 0; y < maze->length; y++) {
        		if (maze->cases[x][y][z].MUR_DROITE == 1) {
                    printf("___");
                } else {
                    printf("   ");
                }
                if (maze->cases[x][y][z].MUR_ARRIERE == 1) {
                    printf("|");
                } else {
                    printf("_");
                }
            }
            printf("\n");
        }
        printf("\n");
	}

	for(i = 0;i<TAILLE_LABY;i++){
        printf("%d %d\n", count[i], stairs[i]);
	}
}
