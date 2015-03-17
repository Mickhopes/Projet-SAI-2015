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

    /* Sol */
    for(z = 0; z < maze->width; z++) {
        for(x = 0; x < maze->length; x++) {
            glBegin(GL_QUADS);
                glColor3f(0.3,0.5,0.3);
                glVertex3f(x*TAILLE_CUBE,0,z*TAILLE_CUBE);
                glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,0,z*TAILLE_CUBE);
                glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,0,z*TAILLE_CUBE+TAILLE_CUBE);
                glVertex3f(x*TAILLE_CUBE,0,z*TAILLE_CUBE+TAILLE_CUBE);
            glEnd();

            glBegin(GL_LINE_LOOP);
                glColor3f(0, 0, 0);
                glVertex3f(x*TAILLE_CUBE,0.05,z*TAILLE_CUBE);
                glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,0.05,z*TAILLE_CUBE);
                glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,0.05,z*TAILLE_CUBE+TAILLE_CUBE);
                glVertex3f(x*TAILLE_CUBE,0.05,z*TAILLE_CUBE+TAILLE_CUBE);
                glVertex3f(x*TAILLE_CUBE,-0.05,z*TAILLE_CUBE+TAILLE_CUBE);
                glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,-0.05,z*TAILLE_CUBE+TAILLE_CUBE);
                glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,-0.05,z*TAILLE_CUBE);
                glVertex3f(x*TAILLE_CUBE,-0.05,z*TAILLE_CUBE);
            glEnd();
        }
    }

    /* Face gauche du batiment */
    for(x = 0; x < maze->length; x++) {
        for(y = 0; y < maze->height; y++) {
            glBegin(GL_QUADS);
                glColor3f(0.5,0.5,0.5);
                glVertex3f(x*TAILLE_CUBE,y*TAILLE_CUBE,0);
                glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE,0);
                glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,0);
                glVertex3f(x*TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,0);
            glEnd();

            glBegin(GL_LINE_LOOP);
                glColor3f(0, 0, 0);
                glVertex3f(x*TAILLE_CUBE,y*TAILLE_CUBE,0.05);
                glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE,0.05);
                glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,0.05);
                glVertex3f(x*TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,0.05);
                glVertex3f(x*TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,-0.05);
                glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,-0.05);
                glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE,-0.05);
                glVertex3f(x*TAILLE_CUBE,y*TAILLE_CUBE,-0.05);
            glEnd();
        }
    }

    /* Face avant du batiment */
    for(z = 0; z < maze->width; z++) {
        for(y = 0; y < maze->height; y++) {
            glBegin(GL_QUADS);
                glColor3f(0.2,0.2,0.2);
                glVertex3f(0,y*TAILLE_CUBE,z*TAILLE_CUBE);
                glVertex3f(0,y*TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE);
                glVertex3f(0,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE);
                glVertex3f(0,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE);
            glEnd();

            glBegin(GL_LINE_LOOP);
                glColor3f(0, 0, 0);
                glVertex3f(0.05,y*TAILLE_CUBE,z*TAILLE_CUBE);
                glVertex3f(0.05,y*TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE);
                glVertex3f(0.05,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE);
                glVertex3f(0.05,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE);
                glVertex3f(-0.05,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE);
                glVertex3f(-0.05,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE);
                glVertex3f(-0.05,y*TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE);
                glVertex3f(-0.05,y*TAILLE_CUBE,z*TAILLE_CUBE);
            glEnd();
        }
    }

    for(z = 0; z < maze->width; z++){
        for(x = 0; x < maze->length; x++){
            for(y = 0; y < maze->height; y++){
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
                        glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE+0.05,y*TAILLE_CUBE,z*TAILLE_CUBE);
                        glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE+0.05,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE);
                        glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE+0.05,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE);
                        glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE+0.05,y*TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE);
                        glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE-0.05,y*TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE);
                        glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE-0.05,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE);
                        glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE-0.05,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE);
                        glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE-0.05,y*TAILLE_CUBE,z*TAILLE_CUBE);
                    glEnd();
                }
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
                        glVertex3f(x*TAILLE_CUBE,y*TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE+0.05);
                        glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE+0.05);
                        glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE+0.05);
                        glVertex3f(x*TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE+0.05);
                        glVertex3f(x*TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE-0.05);
                        glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE-0.05);
                        glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE-0.05);
                        glVertex3f(x*TAILLE_CUBE,y*TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE-0.05);
                    glEnd();
                }
                if (maze->cases[z][x][y].MUR_HAUT == 1) {
                    glBegin(GL_QUADS);
                        glColor3f(0.8,0.2,0.6);
                        glVertex3f(x*TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE);
                        glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE);
                        glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE);
                        glVertex3f(x*TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE);
                    glEnd();

                    glBegin(GL_LINE_LOOP);
                        glColor3f(0, 0, 0);
                        glVertex3f(x*TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE+0.05,z*TAILLE_CUBE);
                        glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE+0.05,z*TAILLE_CUBE);
                        glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE+0.05,z*TAILLE_CUBE+TAILLE_CUBE);
                        glVertex3f(x*TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE+0.05,z*TAILLE_CUBE+TAILLE_CUBE);
                        glVertex3f(x*TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE-0.05,z*TAILLE_CUBE+TAILLE_CUBE);
                        glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE-0.05,z*TAILLE_CUBE+TAILLE_CUBE);
                        glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE-0.05,z*TAILLE_CUBE);
                        glVertex3f(x*TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE-0.05,z*TAILLE_CUBE);
                    glEnd();
                }
            }
        }
    }
 }
