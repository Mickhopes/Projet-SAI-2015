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

int pointeur;

void raffraichissement() {
    glutPostRedisplay();
}

void gererClavier(unsigned char touche, int x, int y){
    /*float vect_x, vect_z;

    vect_x = (obs.x+vis.x) - obs.x;
    vect_z = (obs.z+vis.z) - obs.z;*/

    if(touche == 27){
        free_maze(&maze);
        exit(EXIT_SUCCESS);
    } else if (touche == 'z') {
        /*obs.x += vect_x;
		obs.z += vect_z;*/
        deplacerCamera(0);
    } else if (touche == 's') {
        /*obs.x -= vect_x;
		obs.z -= vect_z;*/
        deplacerCamera(1);
    } else if (touche == 'd') {
        /*obs.x -= vect_z;
		obs.z += vect_x;*/
        deplacerCamera(2);
    } else if (touche == 'q') {
        /*obs.x += vect_z;
		obs.z -= vect_x;*/
        deplacerCamera(3);
    } else if (touche == 32) {
        deplacerCamera(4);
    } else if (touche == 'c') {
        deplacerCamera(5);
    } else if (touche == 'y') {
        /*vis.x = 1;
        vis.y = 0;
        vis.z = 0;*/
    } else if (touche == 'o') {
        pointeur = pointeur == 1 ? 0 : 1;
    }
}

void vMotion(int x, int y) {
    float angle;
    float tx = (float)x - WIDTH/2;

	angle = (tx * 90) / WIDTH/2;

	vis.x = cos(angle * M_PI / 180);

	printf("x: %.2d\n", x);
}

/* 
 * 0: aller en avant
 * 1: aller en arrière
 * 2: tourner à droite
 * 3: tourner à gauche
 * 4: aller en haut
 * 5: aller en bas
 */ 
void deplacerCamera(int dir) {
    int x, y, z;

    x = obs.z / TAILLE_CUBE;
    y = obs.x / TAILLE_CUBE;
    z = obs.y / TAILLE_CUBE;

    /* On se déplace devant */
    if (dir == 0) {
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
    }
    /* On se déplace en arrière */
    else if (dir == 1) {
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
    }
    /* On se tourne a droite */
    else if (dir == 2) {
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
    }
    /* On se tourne a gauche */
    else if (dir == 3) {
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
    }
    /* On se déplace en haut */
    else if (dir == 4) {
        if (z < maze.height-1 && maze.cases[x][y][z].MUR_HAUT == 0) {
            obs.y += TAILLE_CUBE;
        }
    }
    /* On se déplace en bas */
    else if (dir == 5) {
        if (z > 0 && maze.cases[x][y][z].MUR_BAS == 0) {
            obs.y -= TAILLE_CUBE;
        }
    }
}