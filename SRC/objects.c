/****************************************************
 * L3 informatique
 * Projet SAI
 *
 * Auteurs :  - Line Pouvaret
 *            - Mickaël Turnel
 *
 * Fichier : objects.c
 *
 *****************************************************/

 #include "objects.h"

 void labyrinthe(Maze *maze) {
     int x, y, z;

     glLineWidth(2.0);

    /* Sol */
    for(z = 0; z < maze->width; z++) {
        for(x = 0; x < maze->length; x++) {
            if (maze->cases[z][x][0].MUR_BAS == 1) {
                glBegin(GL_QUADS);
                    glColor3f(0.3,0.5,0.3);
                    glVertex3f(x*TAILLE_CUBE,0,z*TAILLE_CUBE);
                    glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,0,z*TAILLE_CUBE);
                    glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,0,z*TAILLE_CUBE+TAILLE_CUBE);
                    glVertex3f(x*TAILLE_CUBE,0,z*TAILLE_CUBE+TAILLE_CUBE);
                glEnd();

                glBegin(GL_LINE_LOOP);
                    glColor3f(0, 0, 0);
                    glVertex3f(x*TAILLE_CUBE,0,z*TAILLE_CUBE);
                    glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,0,z*TAILLE_CUBE);
                    glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,0,z*TAILLE_CUBE+TAILLE_CUBE);
                    glVertex3f(x*TAILLE_CUBE,0,z*TAILLE_CUBE+TAILLE_CUBE);
                glEnd();
            }
        }
    }

    /* Face gauche du batiment */
    for(x = 0; x < maze->length; x++) {
        for(y = 0; y < maze->height; y++) {
            if (maze->cases[0][x][y].MUR_GAUCHE == 1) {
                glBegin(GL_QUADS);
                    glColor3f(0.5,0.5,0.5);
                    glVertex3f(x*TAILLE_CUBE,y*TAILLE_CUBE,0);
                    glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE,0);
                    glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,0);
                    glVertex3f(x*TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,0);
                glEnd();

                glBegin(GL_LINE_LOOP);
                    glColor3f(0, 0, 0);
                    glVertex3f(x*TAILLE_CUBE,y*TAILLE_CUBE,0);
                    glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE,0.);
                    glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,0);
                    glVertex3f(x*TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,0);
                glEnd();
            }
        }
    }

    /* Face avant du batiment */
    for(z = 0; z < maze->width; z++) {
        for(y = 0; y < maze->height; y++) {
            if (maze->cases[z][0][y].MUR_AVANT == 1) {
                glBegin(GL_QUADS);
                    glColor3f(0.2,0.2,0.2);
                    glVertex3f(0,y*TAILLE_CUBE,z*TAILLE_CUBE);
                    glVertex3f(0,y*TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE);
                    glVertex3f(0,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE);
                    glVertex3f(0,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE);
                glEnd();

                glBegin(GL_LINE_LOOP);
                    glColor3f(0, 0, 0);
                    glVertex3f(0,y*TAILLE_CUBE,z*TAILLE_CUBE);
                    glVertex3f(0,y*TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE);
                    glVertex3f(0,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE);
                    glVertex3f(0,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE);
                glEnd();
            }
        }
    }

    for(z = 0; z < maze->width; z++){
        for(x = 0; x < maze->length; x++){
            for(y = 0; y < maze->height; y++){
                /* On dessine le mur arrière */
                if (maze->cases[z][x][y].MUR_ARRIERE == 1) {
                    glBegin(GL_QUADS);
                        glColor3f(0.9,0.9,0.9);
                        glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE,z*TAILLE_CUBE);
                        glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE);
                        glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE);
                        glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE);
                    glEnd();

                    glBegin(GL_LINE_LOOP);
                        glColor3f(0, 0, 0);
                        glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE,z*TAILLE_CUBE);
                        glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE);
                        glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE);
                        glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE);
                    glEnd();
                }
                /* On dessine de mur de droite */
                if (maze->cases[z][x][y].MUR_DROITE == 1) {
                    glBegin(GL_QUADS);
                        glColor3f(0.7,0.5,0.7);
                        glVertex3f(x*TAILLE_CUBE,y*TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE);
                        glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE);
                        glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE);
                        glVertex3f(x*TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE);
                    glEnd();

                    glBegin(GL_LINE_LOOP);
                        glColor3f(0, 0, 0);
                        glVertex3f(x*TAILLE_CUBE,y*TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE);
                        glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE);
                        glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE);
                        glVertex3f(x*TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE);
                    glEnd();
                }
                /* On dessine le mur du dessus tout le temps sauf si l'utilisateur de déplace
                 * entre deux niveaux
                 */
                if (a.x != z || a.y != x || a.z != y) {
                    glBegin(GL_QUADS);
                        glColor3f(0.8,0.2,0.6);
                        glVertex3f(x*TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE);
                        glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE);
                        glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE);
                        glVertex3f(x*TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE);
                    glEnd();

                    glBegin(GL_LINE_LOOP);
                        glColor3f(0, 0, 0);
                        glVertex3f(x*TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE);
                        glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE);
                        glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE);
                        glVertex3f(x*TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE);
                    glEnd();
                } else {
                    if (a.en_mouvement == 0) {
                        glBegin(GL_QUADS);
                            glColor3f(0.8,0.2,0.6);
                            glVertex3f(x*TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE);
                            glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE);
                            glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE);
                            glVertex3f(x*TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE);
                        glEnd();

                        glBegin(GL_LINE_LOOP);
                            glColor3f(0, 0, 0);
                            glVertex3f(x*TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE);
                            glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE);
                            glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE);
                            glVertex3f(x*TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE);
                        glEnd();
                    }
                }
                /* On dessine l'indicateur de montée */
                if (maze->cases[z][x][y].MUR_HAUT == 0) {
                    fleche_montee(z, x, y);
                }
                /* On dessine l'indicateur de descente */
                if (maze->cases[z][x][y].MUR_BAS == 0) {
                    fleche_descente(z, x, y);
                }
            }
        }
    }

    glLineWidth(1.0);
 }

void fleche_montee(int x, int y, int z) {
    int tx, ty, tz;
    /* On dessinera si possible les indicateurs sur ce mur */
    if (maze.cases[z][x][y].MUR_DROITE == 1) {
        tz = x*TAILLE_CUBE+TAILLE_CUBE;
        tx = y*TAILLE_CUBE+TAILLE_CUBE/2;
        ty = z*TAILLE_CUBE+TAILLE_CUBE/2;

        glBegin(GL_QUADS);
            glColor3f(0,1,0);
            glVertex3f(tz-0.01,tx-1.5,ty-3);
            glVertex3f(tz-0.01,tx-1.5,ty);
            glVertex3f(tz-0.01,tx+1.5,ty);
            glVertex3f(tz-0.01,tx+1.5,ty-3);
        glEnd();

        glBegin(GL_QUADS);
            glColor3f(0,1,0);
            glVertex3f(tz-1.01,tx-1.5,ty-3);
            glVertex3f(tz-1.01,tx-1.5,ty);
            glVertex3f(tz-1.01,tx+1.5,ty);
            glVertex3f(tz-1.01,tx+1.5,ty-3);
        glEnd();

        glBegin(GL_QUADS);
            glColor3f(0,1,0);
            glVertex3f(tz-0.01,tx-1.5,ty-3);
            glVertex3f(tz-1.01,tx-1.5,ty-3);
            glVertex3f(tz-1.01,tx-1.5,ty);
            glVertex3f(tz-0.01,tx-1.5,ty);
        glEnd();

        glBegin(GL_QUADS);
            glColor3f(0,1,0);
            glVertex3f(tz-0.01,tx-1.5,ty-3);
            glVertex3f(tz-1.01,tx-1.5,ty-3);
            glVertex3f(tz-1.01,tx+1.5,ty-3);
            glVertex3f(tz-0.01,tx+1.5,ty-3);
        glEnd();

        glBegin(GL_QUADS);
            glColor3f(0,1,0);
            glVertex3f(tz-0.01,tx+1.5,ty-3);
            glVertex3f(tz-1.01,tx+1.5,ty-3);
            glVertex3f(tz-1.01,tx+1.5,ty);
            glVertex3f(tz-0.01,tx+1.5,ty);
        glEnd();

        glBegin(GL_QUADS);
            glColor3f(0,1,0);
            glVertex3f(tz-0.01,tx-1.5,ty);
            glVertex3f(tz-1.01,tx-1.5,ty);
            glVertex3f(tz-1.01,tx+1.5,ty);
            glVertex3f(tz-0.01,tx+1.5,ty);
        glEnd();
    } else {
        /* Sinon on prendra le mur suivant */
        if (maze.cases[x][y][z].MUR_AVANT == 1) {

        } else {
            /* etc... */
            if (maze.cases[x][y][z].MUR_GAUCHE == 1) {

            } else {
                if (maze.cases[x][y][z].MUR_ARRIERE == 1) {

                }
            }
        }
    }
}

void fleche_descente(int x, int y, int z) {

}
