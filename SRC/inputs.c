/****************************************************
 * L3 informatique
 * Projet SAI
 *
 * Auteurs :  - Line Pouvaret
 *            - Mickaël Turnel
 *
 * Fichier : inputs.c
 *
 *****************************************************/

#include "inputs.h"
#include "maze.h"
#include "collision.h"

int pointeur;

void raffraichissement() {
    glutPostRedisplay();
}

void gererClavier(unsigned char touche, int x, int y) {
    switch(touche) {
        case 27:
            free_maze(&maze);
            exit(EXIT_SUCCESS);
        case 'z':
            tab_key[HAUT] = 1;
            break;
        case 's':
            tab_key[BAS] = 1;
            break;
        case 'd':
            tab_key[DROITE] = 1;
            break;
        case 'q':
            tab_key[GAUCHE] = 1;
            break;
        case 32:
            deplacerCamera(DESSUS);
            break;
        case 'c':
            deplacerCamera(DESSOUS);
            break;
        case 'o':
            pointeur = pointeur == 1 ? 0 : 1;
        default:
            break;
    }
}

void relacherClavier(unsigned char touche, int x, int y) {
    switch(touche) {
        case 'z':
            tab_key[HAUT] = 0;
            break;
        case 's':
            tab_key[BAS] = 0;
            break;
        case 'd':
            tab_key[DROITE] = 0;
            break;
        case 'q':
            tab_key[GAUCHE] = 0;
            break;
        case 32:
            tab_key[DESSUS] = 0;
            break;
        case 'c':
            tab_key[DESSOUS] = 0;
            break;
        default:
            break;
    }
}

void vMotion(int x, int y) {
    float angle;

    souris.x += 1.5*((float)x - WIDTH/2);

	while(souris.x > 6480)
		souris.x -= 6480;
	while(souris.x < -6480)
		souris.x += 6480;


	angle = (souris.x * 90) / WIDTH/2;

	vis.x = cos(angle * M_PI / 180);
	vis.z = sin(angle * M_PI / 180);

	souris.y -= 1.5*((float)y - HEIGHT/2);

	if(souris.y < -(HEIGHT/2)-359)
		souris.y = -(HEIGHT/2)-359;

	if(souris.y > (HEIGHT/2)+359)
		souris.y = (HEIGHT/2)+359;

	angle = (souris.y * 90) / HEIGHT/2;

	vis.y = sin(angle * M_PI / 180);
}

void deplacerCamera(int dir) {
    int x, y, z;

    x = obs.z / TAILLE_CUBE;
    y = obs.x / TAILLE_CUBE;
    z = obs.y / TAILLE_CUBE;

    if (dir == HAUT) {
        /* On regarde la position du vecteur de vision */
        if (vis.z == 1 && x < maze.width-1 && maze.cases[x][y][z].MUR_DROITE == 0) {
            obs.z += TAILLE_CUBE;
        }
        if (vis.z == -1 && x > 0 && maze.cases[x][y][z].MUR_GAUCHE == 0) {
            obs.z -= TAILLE_CUBE;
        }
        if (vis.x == 1 && y < maze.length-1 && maze.cases[x][y][z].MUR_ARRIERE == 0) {
            obs.x += TAILLE_CUBE;
        }
        if (vis.x == -1 && y > 0 && maze.cases[x][y][z].MUR_AVANT == 0) {
            obs.x -= TAILLE_CUBE;
        }
    } else if (dir == BAS) {
        /* On regarde la position du vecteur de vision */
        if (vis.z == 1 && x > 0 && maze.cases[x][y][z].MUR_GAUCHE == 0) {
            obs.z -= TAILLE_CUBE;
        }
        if (vis.z == -1 && x < maze.width-1 && maze.cases[x][y][z].MUR_DROITE == 0) {
            obs.z += TAILLE_CUBE;
        }
        if (vis.x == 1 && y > 0 && maze.cases[x][y][z].MUR_AVANT == 0) {
            obs.x -= TAILLE_CUBE;
        }
        if (vis.x == -1 && y < maze.length-1 && maze.cases[x][y][z].MUR_ARRIERE == 0) {
            obs.x += TAILLE_CUBE;
        }
    } else if (dir == DROITE) {
        if (vis.z == 1) {
            vis.z = 0;
            vis.x = -1;
        } else if (vis.z == -1) {
            vis.z = 0;
            vis.x = 1;
        } else if (vis.x == 1) {
            vis.x = 0;
            vis.z = 1;
        } else if (vis.x == -1) {
            vis.x = 0;
            vis.z = -1;
        }
    } else if (dir == GAUCHE) {
        if (vis.z == 1) {
            vis.z = 0;
            vis.x = 1;
        } else if (vis.z == -1) {
            vis.z = 0;
            vis.x = -1;
        } else if (vis.x == 1) {
            vis.x = 0;
            vis.z = -1;
        } else if (vis.x == -1) {
            vis.x = 0;
            vis.z = 1;
        }
    } else if (dir == DESSUS) {
        if (z < maze.height-1 && maze.cases[x][y][z].MUR_HAUT == 0) {
            obs.y += TAILLE_CUBE;
        }
    } else if (dir == DESSOUS) {
        if (z > 0 && maze.cases[x][y][z].MUR_BAS == 0) {
            obs.y -= TAILLE_CUBE;
        }
    }
}

void camera() {
    float vect_x, vect_z;
    Point test;

    test.x = obs.x;
    test.y = obs.y;
    test.z = obs.z;

    vect_x = (obs.x+vis.x) - obs.x;
    vect_z = (obs.z+vis.z) - obs.z;

    if (tab_key[HAUT]) {
        test.x += vect_x;
		test.z += vect_z;

		if (!is_collision(test)) {
            obs.x = test.x;
            obs.z = test.z;
		}
    }

    if (tab_key[BAS]) {
        test.x -= vect_x;
		test.z -= vect_z;

		if (!is_collision(test)) {
            obs.x = test.x;
            obs.z = test.z;
		}
    }

    if (tab_key[DROITE]) {
        test.x -= vect_z;
		test.z += vect_x;

		if (!is_collision(test)) {
            obs.x = test.x;
            obs.z = test.z;
		}
    }

    if (tab_key[GAUCHE]) {
        test.x += vect_z;
		test.z -= vect_x;

		if (!is_collision(test)) {
            obs.x = test.x;
            obs.z = test.z;
		}
    }

    if (tab_key[DESSUS]) {
        deplacerCamera(DESSUS);
    }

    if (tab_key[DESSOUS]) {
        deplacerCamera(DESSOUS);
    }
}
