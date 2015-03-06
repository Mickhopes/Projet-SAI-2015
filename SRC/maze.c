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

void generate_maze(Maze *maze) {
	srand(time(NULL));
	Pile p;
	initialiserPile(&p);
	carve_maze(maze, &p, 0, 0, 0);
}

Cell* random_unvisited_neighbour(Maze *maze, int x, int y, int z) {
	int tx[6], ty[6], tz[6];
	int nb_voisins, all_visited, i, r;
	
	nb_voisins = 0;
	
	/* On regarde les voisins possibles en x */
	if (x == 0) {
		tx[nb_voisins] = x+1;
		ty[nb_voisins] = y;
		tz[nb_voisins] = z;
		nb_voisins++;
	} else if (x == maze->width-1) {
		tx[nb_voisins] = x-1;
		ty[nb_voisins] = y;
		tz[nb_voisins] = z;
		nb_voisins++;
	} else {
		tx[nb_voisins] = x+1;
		ty[nb_voisins] = y;
		tz[nb_voisins] = z;
		tx[nb_voisins+1] = x-1;
		ty[nb_voisins+1] = y;
		tz[nb_voisins+1] = z;
		nb_voisins = nb_voisins+2;
	}
	
	/* On regarde les voisins possible en y */
	if (y == 0) {
		tx[nb_voisins] = x;
		ty[nb_voisins] = y+1;
		tz[nb_voisins] = z;
		nb_voisins++;
	} else if (y == maze->length-1) {
		tx[nb_voisins] = x;
		ty[nb_voisins] = y-1;
		tz[nb_voisins] = z;
		nb_voisins++;
	} else {
		tx[nb_voisins] = x;
		ty[nb_voisins] = y+1;
		tz[nb_voisins] = z;
		tx[nb_voisins+1] = x;
		ty[nb_voisins+1] = y-1;
		tz[nb_voisins+1] = z;
		nb_voisins = nb_voisins+2;
	}
	
	/* On regarde les voisins possibles en z */
	if (z == 0) {
		tx[nb_voisins] = x;
		ty[nb_voisins] = y;
		tz[nb_voisins] = z+1;
		nb_voisins++;
	} else if (z == maze->heigth-1) {
		tx[nb_voisins] = x;
		ty[nb_voisins] = y;
		tz[nb_voisins] = z-1;
		nb_voisins++;
	} else {
		tx[nb_voisins] = x;
		ty[nb_voisins] = y;
		tz[nb_voisins] = z+1;
		tx[nb_voisins+1] = x;
		ty[nb_voisins+1] = y;
		tz[nb_voisins+1] = z-1;
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

void carve_maze(Maze *maze, Pile *p, int x, int y, int z) {
	maze->cases[x][y][z].VISITED = 1;
	
}