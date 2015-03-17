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
    float vect_x, vect_z;

    vect_x = (obs.x+vis.x) - obs.x;
    vect_z = (obs.z+vis.z) - obs.z;

    if(touche == 27){
        free_maze(&maze);
        exit(EXIT_SUCCESS);
    } else if (touche == 'z') {
        obs.x += vect_x;
		obs.z += vect_z;
    } else if (touche == 's') {
        obs.x -= vect_x;
		obs.z -= vect_z;
    } else if (touche == 'd') {
        obs.x -= vect_z;
		obs.z += vect_x;
    } else if (touche == 'q') {
        obs.x += vect_z;
		obs.z -= vect_x;
    } else if (touche == 'y') {
        vis.x = 1;
        vis.y = 0;
        vis.z = 0;
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
