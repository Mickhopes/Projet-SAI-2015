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
	int tx, ty, tz, n, t[3];
	int v = 0;

	/* On regarde si un des voisins est non visité avant d'en rechercher un aléatoirement */
	/*if (x == 0) {
		if ()
	}*/

	do {
		/* On choisit x en surveillant les bornes */
		t[0] = x;
		if (x == 0) {
			t[1] = x+1;
			n = 2;
		} else if (x == maze->width-1) {
			t[1] = x-1;
			n = 2;
		} else {
			t[1] = x-1;
			t[2] = x+1;
			n = 3;
		}
		tx = t[rand()%n];

		/* On choisit y en surveillant les bornes */
		t[0] = y;
		if (y == 0) {
			t[1] = y+1;
			n = 2;
		} else if (y == maze->length-1) {
			t[1] = y-1;
			n = 2;
		} else {
			t[1] = y-1;
			t[2] = y+1;
			n = 3;
		}
		ty = t[rand()%n];

		/* On choisit z en surveillant les bornes */
		t[0] = z;
		if (z == 0) {
			t[1] = z+1;
			n = 2;
		} else if (x == maze->heigth-1) {
			t[1] = z-1;
			n = 2;
		} else {
			t[1] = z-1;
			t[2] = z+1;
			n = 3;
		}
		tz = t[rand()%n];
	} while(maze->cases[tx][ty][tz].VISITED == 1);

	return &(maze->cases[tx][ty][tz]);
}

void carve_maze(Maze *maze, Pile *p, int x, int y, int z) {
	maze->cases[x][y][z].VISITED = 1;
	
}