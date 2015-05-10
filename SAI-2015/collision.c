/****************************************************
 * L3 informatique
 * Projet SAI
 *
 * Auteurs :  - Line Pouvaret
 *            - Mickaël Turnel
 *
 * Fichier : collision.c
 *
 *****************************************************/

 #include "collision.h"
 #include "maze.h"

int is_collision(Point p) {
    int x, y, z;

    /* On regarde d'abords si on est dans le labyrinthe sinon il n'y a pas de collision pour l'instant */
    if (p.z > 0 && p.z <= maze.width*TAILLE_CUBE && p.x > 0 && p.x <= maze.length*TAILLE_CUBE && p.y > 0 && p.y <= maze.height*TAILLE_CUBE) {
        x = p.z / TAILLE_CUBE;
        y = p.x / TAILLE_CUBE;
        z = p.y / TAILLE_CUBE;

        if (maze.cases[x][y][z].MUR_AVANT == 1 && p.x-5 < y*TAILLE_CUBE) {
            return 1;
        }
        if (maze.cases[x][y][z].MUR_ARRIERE == 1 && p.x+5 > y*TAILLE_CUBE+TAILLE_CUBE) {
            return 1;
        }
        if (maze.cases[x][y][z].MUR_GAUCHE == 1 && p.z-5 < x*TAILLE_CUBE) {
            return 1;
        }
        if (maze.cases[x][y][z].MUR_DROITE == 1 && p.z+5 > x*TAILLE_CUBE+TAILLE_CUBE) {
            return 1;
        }
        if (maze.cases[x][y][z].MUR_BAS == 1 && p.y-5 < z*TAILLE_CUBE) {
            return 1;
        }
        if (maze.cases[x][y][z].MUR_HAUT == 1 && p.y+5 > z*TAILLE_CUBE+TAILLE_CUBE) {
            return 1;
        }

        return 0;
    } else if (p.y > maze.height*TAILLE_CUBE && p.y <= maze.height*TAILLE_CUBE+TAILLE_CUBE) {
        if (p.x-5 < 0 || p.x+5 > maze.length*TAILLE_CUBE) {
            return 1;
        }
        if (p.z-5 < 0 || p.z+5 > maze.width*TAILLE_CUBE) {
            return 1;
        }

        return 0;
    } else if (p.y > 0 && p.y <= TAILLE_CUBE) {
        if (p.x-5 < -(TAILLE_CUBE*maze.length) || p.x+5 > (TAILLE_CUBE*maze.length)*2) {
            return 1;
        }
        if (p.z-5 < -(TAILLE_CUBE*maze.width) || p.z+5 > (TAILLE_CUBE*maze.width)*2) {
            return 1;
        }

        return 0;
    }

    return 0;
}
