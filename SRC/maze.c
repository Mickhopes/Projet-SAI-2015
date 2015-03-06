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

int init_maze(Maze *maze, int width, int length, int heigth) {
	int i, j, k;

	maze->width = width;
	maze->length = length;
	maze->heigth = heigth;

	/* Première dimension */
	if ((maze->cases = (Cell***)malloc(width*sizeof(Cell**))) == NULL) {
		return 0;
	}

	for (i = 0; i < width; i++) {
		/* Seconde dimension */
		if ((maze->cases[i] = (Cell**)malloc(length*sizeof(Cell*))) == NULL) {
			return 0;
		}

		for(j = 0; j < length; j++) {
			/* Troisième dimension */
			if ((maze->cases[i][j] = (Cell*)malloc(heigth*sizeof(Cell))) == NULL) {
				return 0;
			}

			for(k = 0; k < heigth; k++) {
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

	/* On regarde les voisins possibles en z */
	if (c->z == 0) {
		tx[nb_voisins] = c->x;
		ty[nb_voisins] = c->y;
		tz[nb_voisins] = c->z+1;
		nb_voisins++;
	} else if (c->z == maze->heigth-1) {
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
	srand(time(NULL));
	Pile p;
	initialiserPile(&p);
	carve_maze(maze, &p, 0, 0, 0);
}

void carve_maze(Maze *maze, Pile *p, int x, int y, int z) {
	Cell *courant = &(maze->cases[x][y][z]);
	Cell *voisin;

	courant->VISITED = 1;
	voisin = random_unvisited_neighbour(maze, courant);
	if (voisin != NULL) {
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
    int x, y, z;

    for(z = 0; z < maze->heigth; z++) {
	    printf("Level %d:\n", z);
	    for(y = 0; y < maze->length; y++) {
            printf("___");
	    }
	    printf("\n");
        for(x = 0; x < maze->width; x++) {
            printf("|");
            for(y = 0; y < maze->length; y++) {
                if (maze->cases[x][y][z].MUR_DROITE == 1) {
                    printf("_");
                } else {
                    printf(" ");
                }
                if (maze->cases[x][y][z].MUR_BAS == 0 && maze->cases[x][y][z].MUR_HAUT == 0) {
                    printf("X");
                } else if (maze->cases[x][y][z].MUR_BAS == 0) {
                    printf("-");
                } else if (maze->cases[x][y][z].MUR_HAUT == 0) {
                    printf("+");
                } else {
                    printf(" ");
                }
                if (maze->cases[x][y][z].MUR_ARRIERE == 1) {
                    printf("|");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }
        printf("\n");
	}
}
