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
    if(tab_key[DESSUS] != -1){
        if(obs.y < tab_key[DESSUS]*TAILLE_CUBE +TAILLE_CUBE/4){
            obs.y += 1;
        }
        else{
            tab_key[DESSUS] = -1;
            a.en_mouvement = 0;
        }

    }
    if(tab_key[DESSOUS] != -1){
        if(obs.y > tab_key[DESSOUS]*TAILLE_CUBE +TAILLE_CUBE/4){
            obs.y -= 1;
        }
        else{
            tab_key[DESSOUS] = -1;
            a.en_mouvement = 0;
        }
    }
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
            //tab_key[DESSUS] = 1;
            deplacerCamera(DESSUS);
            break;
        case 'c':
            //tab_key[DESSOUS] = 1;
            deplacerCamera(DESSOUS);
            break;
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
          //  tab_key[DESSUS] = 0;
            break;
        case 'c':
           // tab_key[DESSOUS] = 0;
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
        if (obs.z > 0 && obs.z < maze.width*TAILLE_CUBE && obs.x > 0 && obs.x < maze.width*TAILLE_CUBE && obs.y > 0 && obs.y < maze.height*TAILLE_CUBE) {
            if (z < maze.height-1 && maze.cases[x][y][z].MUR_HAUT == 0) {
                /* Evite une collision avec le mur du dessus */
                if (obs.z+5 < x*TAILLE_CUBE+TAILLE_CUBE && obs.z-5 > x*TAILLE_CUBE) {
                   tab_key[DESSUS] = z+1;
                   a.x = x;
                   a.y = y;
                   a.z = z;
                   a.en_mouvement = 1;
                }
            }
        }
    } else if (dir == DESSOUS) {
        if (obs.z > 0 && obs.z < maze.width*TAILLE_CUBE && obs.x > 0 && obs.x < maze.width*TAILLE_CUBE && obs.y > 0 && obs.y < maze.height*TAILLE_CUBE) {
            if (z > 0 && maze.cases[x][y][z].MUR_BAS == 0) {
                /* Evite une collision avec le mur du dessous */
                if (obs.x+5 < y*TAILLE_CUBE+TAILLE_CUBE && obs.x-5 > y*TAILLE_CUBE) {
                   tab_key[DESSOUS] = z-1;
                   a.x = x;
                   a.y = y;
                   a.z = z-1;
                   a.en_mouvement = 1;
                }
            }
        }
    }
}

void camera() {
    float vect_x, vect_z/*, vect_y*/;
    Point test;

    test.x = obs.x;
    test.y = obs.y;
    test.z = obs.z;

    vect_x = (obs.x+vis.x) - obs.x;
    vect_z = (obs.z+vis.z) - obs.z;
    /*vect_y = 1;*/

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
       /* test.y += vect_y;
        if(!is_collision(test)){
            obs.y = test.y;
        }*/
    }

    if (tab_key[DESSOUS]) {
       /* test.y -= vect_y;
        if(!is_collision(test)){
            obs.y = test.y;
        }*/
    }

}
