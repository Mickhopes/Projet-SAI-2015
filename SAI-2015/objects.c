/****************************************************
 * L3 informatique
 * Projet SAI
 *
 * Auteurs :  - Line Pouvaret
 *            - Micka�l Turnel
 *
 * Fichier : objects.c
 *
 *****************************************************/

 #include "objects.h"

 void sol() {
    glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	glBegin(GL_QUADS);
	    glColor3f(1.0,1.0,1.0);
	    glTexCoord2f(0.0, 0.0); glVertex3f(-(TAILLE_CUBE*maze.length),-0.1,-(TAILLE_CUBE*maze.width));
	    glTexCoord2f(100.0, 0.0); glVertex3f((TAILLE_CUBE*maze.length)+(TAILLE_CUBE*maze.length),-0.1,-(TAILLE_CUBE*maze.width));
	    glTexCoord2f(100.0, 100.0); glVertex3f((TAILLE_CUBE*maze.length)+(TAILLE_CUBE*maze.length),-0.1,(TAILLE_CUBE*maze.width)+(TAILLE_CUBE*maze.width));
	    glTexCoord2f(0.0, 100.0); glVertex3f(-(TAILLE_CUBE*maze.length),-0.1,(TAILLE_CUBE*maze.width)+(TAILLE_CUBE*maze.width));
	glEnd();


    /* On fait les grilles */
	glBindTexture(GL_TEXTURE_2D, texture[3]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

    glBegin(GL_QUADS);
	    glColor3f(1.0,1.0,1.0);
	    glTexCoord2f(0.0, 0.0); glVertex3f(-(TAILLE_CUBE*maze.length),-0.1,-(TAILLE_CUBE*maze.width));
	    glTexCoord2f(100.0, 0.0); glVertex3f((TAILLE_CUBE*maze.length)+(TAILLE_CUBE*maze.length),-0.1,-(TAILLE_CUBE*maze.width));
	    glTexCoord2f(100.0, 1.0); glVertex3f((TAILLE_CUBE*maze.length)+(TAILLE_CUBE*maze.length),-0.1+TAILLE_CUBE,-(TAILLE_CUBE*maze.width));
	    glTexCoord2f(0.0, 1.0); glVertex3f(-(TAILLE_CUBE*maze.length),-0.1+TAILLE_CUBE,-(TAILLE_CUBE*maze.width));
	glEnd();

	glBegin(GL_QUADS);
	    glColor3f(1.0,1.0,1.0);
	    glTexCoord2f(0.0, 0.0); glVertex3f(-(TAILLE_CUBE*maze.length),-0.1,-(TAILLE_CUBE*maze.width));
	    glTexCoord2f(100.0, 0.0); glVertex3f(-(TAILLE_CUBE*maze.length),-0.1,(TAILLE_CUBE*maze.width)+(TAILLE_CUBE*maze.width));
	    glTexCoord2f(100.0, 1.0); glVertex3f(-(TAILLE_CUBE*maze.length),-0.1+TAILLE_CUBE,(TAILLE_CUBE*maze.width)+(TAILLE_CUBE*maze.width));
	    glTexCoord2f(0.0, 1.0); glVertex3f(-(TAILLE_CUBE*maze.length),-0.1+TAILLE_CUBE,-(TAILLE_CUBE*maze.width));
	glEnd();

	glBegin(GL_QUADS);
	    glColor3f(1.0,1.0,1.0);
	    glTexCoord2f(0.0, 0.0); glVertex3f(-(TAILLE_CUBE*maze.length),-0.1,(TAILLE_CUBE*maze.width)+(TAILLE_CUBE*maze.width));
	    glTexCoord2f(100.0, 0.0); glVertex3f((TAILLE_CUBE*maze.length)+(TAILLE_CUBE*maze.length),-0.1,(TAILLE_CUBE*maze.width)+(TAILLE_CUBE*maze.width));
	    glTexCoord2f(100.0, 1.0); glVertex3f((TAILLE_CUBE*maze.length)+(TAILLE_CUBE*maze.length),-0.1+TAILLE_CUBE,(TAILLE_CUBE*maze.width)+(TAILLE_CUBE*maze.width));
	    glTexCoord2f(0.0, 1.0); glVertex3f(-(TAILLE_CUBE*maze.length),-0.1+TAILLE_CUBE,(TAILLE_CUBE*maze.width)+(TAILLE_CUBE*maze.width));
	glEnd();

	glBegin(GL_QUADS);
	    glColor3f(1.0,1.0,1.0);
	    glTexCoord2f(0.0, 0.0); glVertex3f((TAILLE_CUBE*maze.length)+(TAILLE_CUBE*maze.length),-0.1,-(TAILLE_CUBE*maze.width));
	    glTexCoord2f(100.0, 0.0); glVertex3f((TAILLE_CUBE*maze.length)+(TAILLE_CUBE*maze.length),-0.1,(TAILLE_CUBE*maze.width)+(TAILLE_CUBE*maze.width));
	    glTexCoord2f(100.0, 1.0); glVertex3f((TAILLE_CUBE*maze.length)+(TAILLE_CUBE*maze.length),-0.1+TAILLE_CUBE,(TAILLE_CUBE*maze.width)+(TAILLE_CUBE*maze.width));
	    glTexCoord2f(0.0, 1.0); glVertex3f((TAILLE_CUBE*maze.length)+(TAILLE_CUBE*maze.length),-0.1+TAILLE_CUBE,-(TAILLE_CUBE*maze.width));
	glEnd();
 }

 void labyrinthe(Maze *maze) {
    int x, y, z;

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[2]);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

    /* Sol */
    for(z = 0; z < maze->width; z++) {
        for(x = 0; x < maze->length; x++) {
            if (maze->cases[z][x][0].MUR_BAS == 1) {
                glBegin(GL_QUADS);
                    glColor3f(1.0,1.0,1.0);
                    glTexCoord2f(0.0, 0.0); glVertex3f(x*TAILLE_CUBE,0,z*TAILLE_CUBE);
                    glTexCoord2f(1.0, 0.0); glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,0,z*TAILLE_CUBE);
                    glTexCoord2f(1.0, 1.0); glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,0,z*TAILLE_CUBE+TAILLE_CUBE);
                    glTexCoord2f(0.0, 1.0); glVertex3f(x*TAILLE_CUBE,0,z*TAILLE_CUBE+TAILLE_CUBE);
                glEnd();
            }
        }
    }

    glBindTexture(GL_TEXTURE_2D, texture[1]);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

    /* Face gauche du batiment */
    for(x = 0; x < maze->length; x++) {
        for(y = 0; y < maze->height; y++) {
            if (maze->cases[0][x][y].MUR_GAUCHE == 1) {
                glBegin(GL_QUADS);
                    glColor3f(1.0,1.0,1.0);
                    glTexCoord2f(0.0, 0.0); glVertex3f(x*TAILLE_CUBE,y*TAILLE_CUBE,0);
                    glTexCoord2f(1.0, 0.0); glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE,0);
                    glTexCoord2f(1.0, 1.0); glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,0);
                    glTexCoord2f(0.0, 1.0); glVertex3f(x*TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,0);
                glEnd();
            }
        }
    }

    glBindTexture(GL_TEXTURE_2D, texture[1]);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

    /* Face avant du batiment */
    for(z = 0; z < maze->width; z++) {
        for(y = 0; y < maze->height; y++) {
            if (maze->cases[z][0][y].MUR_AVANT == 1) {
                glBegin(GL_QUADS);
                    glColor3f(1.0,1.0,1.0);
                    glTexCoord2f(0.0, 0.0); glVertex3f(0,y*TAILLE_CUBE,z*TAILLE_CUBE);
                    glTexCoord2f(1.0, 0.0); glVertex3f(0,y*TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE);
                    glTexCoord2f(1.0, 1.0); glVertex3f(0,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE);
                    glTexCoord2f(0.0, 1.0); glVertex3f(0,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE);
                glEnd();
            }
        }
    }

    for(z = 0; z < maze->width; z++){
        for(x = 0; x < maze->length; x++){
            for(y = 0; y < maze->height; y++){
                glEnable(GL_TEXTURE_2D);
                /* On dessine le mur arri�re */
                if (maze->cases[z][x][y].MUR_ARRIERE == 1) {
                    glBindTexture(GL_TEXTURE_2D, texture[1]);
                    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
                    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

                    glBegin(GL_QUADS);
                        glColor3f(1.0,1.0,1.0);
                        glTexCoord2f(0.0, 0.0); glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE,z*TAILLE_CUBE);
                        glTexCoord2f(0.0, 1.0); glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE);
                        glTexCoord2f(1.0, 1.0); glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE);
                        glTexCoord2f(1.0, 0.0); glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE);
                    glEnd();
                }
                /* On dessine de mur de droite */
                if (maze->cases[z][x][y].MUR_DROITE == 1) {
                    glBindTexture(GL_TEXTURE_2D, texture[1]);
                    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
                    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

                    glBegin(GL_QUADS);
                        glColor3f(1.0,1.0,1.0);
                        glTexCoord2f(0.0, 0.0); glVertex3f(x*TAILLE_CUBE,y*TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE);
                        glTexCoord2f(1.0, 0.0); glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE);
                        glTexCoord2f(1.0, 1.0); glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE);
                        glTexCoord2f(0.0, 1.0); glVertex3f(x*TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE);
                    glEnd();
                }
                /* On dessine le mur du dessus tout le temps sauf si l'utilisateur de d�place
                 * entre deux niveaux
                 */
                glBindTexture(GL_TEXTURE_2D, texture[2]);
                glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
                glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

                if (a.x != z || a.y != x || a.z != y) {
                    glBegin(GL_QUADS);
                        glColor3f(1.0,1.0,1.0);
                        glTexCoord2f(0.0, 0.0); glVertex3f(x*TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE);
                        glTexCoord2f(1.0, 0.0); glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE);
                        glTexCoord2f(1.0, 1.0); glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE);
                        glTexCoord2f(0.0, 1.0); glVertex3f(x*TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE);
                    glEnd();
                } else {
                    if (a.en_mouvement == 0) {
                        glBegin(GL_QUADS);
                            glColor3f(1.0,1.0,1.0);
                            glTexCoord2f(0.0, 0.0); glVertex3f(x*TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE);
                            glTexCoord2f(1.0, 0.0); glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE);
                            glTexCoord2f(1.0, 1.0); glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE);
                            glTexCoord2f(0.0, 1.0); glVertex3f(x*TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE);
                        glEnd();
                    }
                }
                /* On dessine l'indicateur de mont�e */
                if (maze->cases[z][x][y].MUR_HAUT == 0) {
                    glDisable(GL_TEXTURE_2D);
                    mettre_fleche_montee(x, y, z);
                }
                /* On dessine l'indicateur de descente */
                if (maze->cases[z][x][y].MUR_BAS == 0) {
                    glDisable(GL_TEXTURE_2D);
                    mettre_fleche_descente(x, y, z);
                }
            }
        }
    }

    /* Puis on fait les grilles sur le toit */
    glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[3]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

    glBegin(GL_QUADS);
	    glColor3f(1.0,1.0,1.0);
	    glTexCoord2f(0.0, 0.0); glVertex3f(0,TAILLE_CUBE*maze->height,0);
	    glTexCoord2f(20.0, 0.0); glVertex3f(0,TAILLE_CUBE*maze->height,TAILLE_CUBE*maze->width);
	    glTexCoord2f(20.0, 1.0); glVertex3f(0,TAILLE_CUBE*maze->height+TAILLE_CUBE,TAILLE_CUBE*maze->width);
	    glTexCoord2f(0.0, 1.0); glVertex3f(0,TAILLE_CUBE*maze->height+TAILLE_CUBE,0);
	glEnd();

	glBegin(GL_QUADS);
	    glColor3f(1.0,1.0,1.0);
	    glTexCoord2f(0.0, 0.0); glVertex3f(0,TAILLE_CUBE*maze->height,0);
	    glTexCoord2f(20.0, 0.0); glVertex3f(TAILLE_CUBE*maze->length,TAILLE_CUBE*maze->height,0);
	    glTexCoord2f(20.0, 1.0); glVertex3f(TAILLE_CUBE*maze->length,TAILLE_CUBE*maze->height+TAILLE_CUBE,0);
	    glTexCoord2f(0.0, 1.0); glVertex3f(0,TAILLE_CUBE*maze->height+TAILLE_CUBE,0);
	glEnd();

	glBegin(GL_QUADS);
	    glColor3f(1.0,1.0,1.0);
	    glTexCoord2f(0.0, 0.0); glVertex3f(TAILLE_CUBE*maze->length,TAILLE_CUBE*maze->height,0);
	    glTexCoord2f(20.0, 0.0); glVertex3f(TAILLE_CUBE*maze->length,TAILLE_CUBE*maze->height,TAILLE_CUBE*maze->width);
	    glTexCoord2f(20.0, 1.0); glVertex3f(TAILLE_CUBE*maze->length,TAILLE_CUBE*maze->height+TAILLE_CUBE,TAILLE_CUBE*maze->width);
	    glTexCoord2f(0.0, 1.0); glVertex3f(TAILLE_CUBE*maze->length,TAILLE_CUBE*maze->height+TAILLE_CUBE,0);
	glEnd();

	glBegin(GL_QUADS);
	    glColor3f(1.0,1.0,1.0);
	    glTexCoord2f(0.0, 0.0); glVertex3f(0,TAILLE_CUBE*maze->height,TAILLE_CUBE*maze->width);
	    glTexCoord2f(20.0, 0.0); glVertex3f(TAILLE_CUBE*maze->length,TAILLE_CUBE*maze->height,TAILLE_CUBE*maze->width);
	    glTexCoord2f(20.0, 1.0); glVertex3f(TAILLE_CUBE*maze->length,TAILLE_CUBE*maze->height+TAILLE_CUBE,TAILLE_CUBE*maze->width);
	    glTexCoord2f(0.0, 1.0); glVertex3f(0,TAILLE_CUBE*maze->height+TAILLE_CUBE,TAILLE_CUBE*maze->width);
	glEnd();
 }

void mettre_fleche_montee(int x, int y, int z) {
    float tx, ty, tz;
    float rotate = -1.0;

    /* On dessinera si possible les indicateurs sur ce mur */
    if (maze.cases[z][x][y].MUR_DROITE == 1) {
        tx = x*TAILLE_CUBE+TAILLE_CUBE/2-TAILLE_CUBE/4;
        ty = y*TAILLE_CUBE+TAILLE_CUBE/2;
        tz = z*TAILLE_CUBE+TAILLE_CUBE;
    } else {
        /* Sinon on prendra le mur suivant */
        if (maze.cases[z][x][y].MUR_AVANT == 1) {
            tx = x*TAILLE_CUBE;
            ty = y*TAILLE_CUBE+TAILLE_CUBE/2;
            tz = z*TAILLE_CUBE+TAILLE_CUBE/2-TAILLE_CUBE/4;
            rotate = -90.0;
        } else {
            /* etc... */
            if (maze.cases[z][x][y].MUR_GAUCHE == 1) {
                tx = x*TAILLE_CUBE+TAILLE_CUBE/2+TAILLE_CUBE/4;
                ty = y*TAILLE_CUBE+TAILLE_CUBE/2;
                tz = z*TAILLE_CUBE;
                rotate = 180.0;
            } else {
                if (maze.cases[z][x][y].MUR_ARRIERE == 1) {
                    tx = x*TAILLE_CUBE+TAILLE_CUBE;
                    ty = y*TAILLE_CUBE+TAILLE_CUBE/2;
                    tz = z*TAILLE_CUBE+TAILLE_CUBE/2+TAILLE_CUBE/4;
                    rotate = 90.0;
                }
            }
        }
    }

    glPushMatrix();
    glTranslatef(tx, ty, tz);
    if (rotate != -1.0) {
        glRotatef(rotate, 0, 1.0, 0);
    }
    fleche_montee();
    glPopMatrix();
}

void mettre_fleche_descente(int x, int y, int z) {
    float tx, ty, tz;
    float rotate = -1.0;

    /* On dessinera si possible les indicateurs sur ce mur */
    if (maze.cases[z][x][y].MUR_DROITE == 1) {
        tx = x*TAILLE_CUBE+TAILLE_CUBE/2+TAILLE_CUBE/4;
        ty = y*TAILLE_CUBE+TAILLE_CUBE/2;
        tz = z*TAILLE_CUBE+TAILLE_CUBE;
    } else {
        /* Sinon on prendra le mur suivant */
        if (maze.cases[z][x][y].MUR_AVANT == 1) {
            tx = x*TAILLE_CUBE;
            ty = y*TAILLE_CUBE+TAILLE_CUBE/2;
            tz = z*TAILLE_CUBE+TAILLE_CUBE/2+TAILLE_CUBE/4;
            rotate = -90.0;
        } else {
            /* etc... */
            if (maze.cases[z][x][y].MUR_GAUCHE == 1) {
                tx = x*TAILLE_CUBE+TAILLE_CUBE/2-TAILLE_CUBE/4;
                ty = y*TAILLE_CUBE+TAILLE_CUBE/2;
                tz = z*TAILLE_CUBE;
                rotate = 180.0;
            } else {
                if (maze.cases[z][x][y].MUR_ARRIERE == 1) {
                    tx = x*TAILLE_CUBE+TAILLE_CUBE;
                    ty = y*TAILLE_CUBE+TAILLE_CUBE/2;
                    tz = z*TAILLE_CUBE+TAILLE_CUBE/2-TAILLE_CUBE/4;
                    rotate = 90.0;
                }
            }
        }
    }

    glPushMatrix();
    glTranslatef(tx, ty, tz);
    if (rotate != -1.0) {
        glRotatef(rotate, 0, 1.0, 0);
    }
    fleche_descente();
    glPopMatrix();
}

void fleche_montee() {
    glBegin(GL_QUADS);
        glColor3f(0,1,0);
        glVertex3f(-1.5,-3,-1);
        glVertex3f(-1.5,0,-1);
        glVertex3f(1.5,0,-1);
        glVertex3f(1.5,-3,-1);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0,1,0);
        glVertex3f(-1.5,-3,-0.1);
        glVertex3f(-1.5,-3,-1);
        glVertex3f(-1.5,0,-1);
        glVertex3f(-1.5,0,-0.1);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0,1,0);
        glVertex3f(1.5,-3,-0.1);
        glVertex3f(1.5,-3,-1);
        glVertex3f(1.5,0,-1);
        glVertex3f(1.5,0,-0.1);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0,1,0);
        glVertex3f(-1.5,-3,-0.1);
        glVertex3f(-1.5,-3,-1);
        glVertex3f(1.5,-3,-1);
        glVertex3f(1.5,-3,-0.1);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0,1,0);
        glVertex3f(-2.5,0,-1);
        glVertex3f(2.5,0,-1);
        glVertex3f(0,3,-1);
        glVertex3f(0,3,-1);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0,1,0);
        glVertex3f(-2.5,0,-1);
        glVertex3f(-2.5,0,-0.1);
        glVertex3f(2.5,0,-0.1);
        glVertex3f(2.5,0,-1);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0,1,0);
        glVertex3f(-2.5,0,-1);
        glVertex3f(0,3,-1);
        glVertex3f(0,3,-0.1);
        glVertex3f(-2.5,0,-0.1);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0,1,0);
        glVertex3f(2.5,0,-1);
        glVertex3f(0,3,-1);
        glVertex3f(0,3,-0.1);
        glVertex3f(2.5,0,-0.1);
    glEnd();
}

void fleche_descente() {
    glBegin(GL_QUADS);
        glColor3f(0,1,0);
        glVertex3f(-1.5,0,-1);
        glVertex3f(-1.5,3,-1);
        glVertex3f(1.5,3,-1);
        glVertex3f(1.5,0,-1);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0,1,0);
        glVertex3f(-1.5,0,-0.1);
        glVertex3f(-1.5,0,-1);
        glVertex3f(-1.5,3,-1);
        glVertex3f(-1.5,3,-0.1);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0,1,0);
        glVertex3f(1.5,0,-0.1);
        glVertex3f(1.5,0,-1);
        glVertex3f(1.5,3,-1);
        glVertex3f(1.5,3,-0.1);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0,1,0);
        glVertex3f(-1.5,3,-0.1);
        glVertex3f(-1.5,3,-1);
        glVertex3f(1.5,3,-1);
        glVertex3f(1.5,3,-0.1);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0,1,0);
        glVertex3f(-2.5,0,-1);
        glVertex3f(2.5,0,-1);
        glVertex3f(0,-3,-1);
        glVertex3f(0,-3,-1);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0,1,0);
        glVertex3f(-2.5,0,-1);
        glVertex3f(-2.5,0,-0.1);
        glVertex3f(2.5,0,-0.1);
        glVertex3f(2.5,0,-1);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0,1,0);
        glVertex3f(-2.5,0,-1);
        glVertex3f(0,-3,-1);
        glVertex3f(0,-3,-0.1);
        glVertex3f(-2.5,0,-0.1);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0,1,0);
        glVertex3f(2.5,0,-1);
        glVertex3f(0,-3,-1);
        glVertex3f(0,-3,-0.1);
        glVertex3f(2.5,0,-0.1);
    glEnd();
}



void helico(int xH, int yH, int zH){
    glDisable(GL_TEXTURE_2D);

    /* Fuselage de l'h�lico <=> ellipso�de de centre xH, yH, zH */

    glPushMatrix();
    glTranslatef(xH,yH,zH);
    glScalef(2.0,1.5,3.0);
    glColor3f(0.15,0.25,0.45);
    gluSphere(gluNewQuadric(), 5.0, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(xH,yH,zH);
    /* Train d'atterrissage */

    float l = 1, h = 3, e = 1;
    float xabs = 3.5, yabs = 6+h, zabs = 6;

    glColor3f(0.06,0.3,0.55);
    para_rect(-xabs,-yabs,-zabs,-xabs+l,-yabs+h, -zabs+e);
    para_rect(xabs,-yabs,-zabs,xabs+l,-yabs+h,-zabs+e);
    para_rect(-xabs,-yabs,+zabs,-xabs+l,-yabs+h,zabs+e);
    para_rect(xabs,-yabs,zabs,xabs+l,-yabs+h,zabs+e);


    h = 1, e = 25;
    yabs +=h,zabs +=e/2;

    glColor3f(0.15,0.25,0.55);
    para_rect(-xabs,-yabs,-zabs,-xabs+l,-yabs+h,zabs);
    para_rect(xabs,-yabs,-zabs,xabs+l,-yabs+h,zabs);

    /* Mat */
    h = 2.5,e = 1;
    xabs = l/2,yabs=4+h,zabs = e/2;

    glColor3f(0.35,0.35,0.35);
    para_rect(-xabs,yabs,-zabs,xabs,yabs+h,zabs);

    /* Pales de rotor*/

    glPushMatrix();
    glRotatef(angle_rotor, 0.0,yH,0.0);

    h = 0.2, e = 50;
    yabs+=2.5,zabs = e/2;

    glColor3f(0.4,0.4,0.4);
    para_rect(-xabs,yabs,-zabs,xabs,yabs+h,zabs);
    l = e, e = 1;
    xabs = zabs,zabs = 0.5;
    para_rect(-xabs,yabs,-zabs,xabs,yabs+h,zabs);

    glPopMatrix();


    /* Queue */

    l = 1, h = 1, e = 20;
    xabs = l/2,yabs = h/2, zabs = 14;

    glColor3f(0.06,0.3,0.55);
    para_rect(-xabs,-yabs,zabs,xabs,yabs,zabs+e);

    h = 2.5,e = 1;
    zabs += 19;

    glColor3f(0.06,0.3,0.55);
    para_rect(-xabs,yabs,zabs,xabs,yabs+h,zabs+e);

    glPopMatrix();

    /* Rotor de Queue */

    glPushMatrix();
    glTranslatef(-0.5,2.5,33.5);
    glTranslatef(xH,yH,zH);
    glRotatef(angle_rotor_queue,1.0,0.0,0.0);


    glColor3f(0.4,0.4,0.4);


    l = 0.2, h = 6, e = 0.7;
    xabs = l/2,yabs = h/2, zabs = e/2;

    para_rect(-xabs,-yabs,-zabs,xabs,yabs,zabs);

    l = 0.2, h = 0.7, e = 6;
    xabs = l/2,yabs = h/2,zabs = e/2 ;

    para_rect(-xabs,-yabs,-zabs,xabs,yabs,zabs);

    glPopMatrix();
}


/* Fonction qui dessine un parall�l�pip�de rectangle � partir de 2 points */
void para_rect(float x1, float y1, float z1, float x2, float y2, float z2){

    /* Face avant */
    glBegin(GL_QUADS);
    glVertex3f(x1,y1,z1);
    glVertex3f(x2,y1,z1);
    glVertex3f(x2,y2,z1);
    glVertex3f(x1,y2,z1);
    glEnd();

    /* Face arri�re */
    glBegin(GL_QUADS);
    glVertex3f(x1,y1,z2);
    glVertex3f(x2,y1,z2);
    glVertex3f(x2,y2,z2);
    glVertex3f(x1,y2,z2);
    glEnd();

    /* Face gauche */
    glBegin(GL_QUADS);
    glVertex3f(x1,y1,z1);
    glVertex3f(x1,y2,z1);
    glVertex3f(x1,y2,z2);
    glVertex3f(x1,y1,z2);
    glEnd();

    /* Face droite */
    glBegin(GL_QUADS);
    glVertex3f(x2,y1,z1);
    glVertex3f(x2,y2,z1);
    glVertex3f(x2,y2,z2);
    glVertex3f(x2,y1,z2);
    glEnd();

    /* Face dessous */
    glBegin(GL_QUADS);
    glVertex3f(x1,y1,z1);
    glVertex3f(x2,y1,z1);
    glVertex3f(x2,y1,z2);
    glVertex3f(x1,y1,z2);
    glEnd();

    /* Face dessus */
    glBegin(GL_QUADS);
    glVertex3f(x1,y2,z1);
    glVertex3f(x2,y2,z1);
    glVertex3f(x2,y2,z2);
    glVertex3f(x1,y2,z2);
    glEnd();
}

void hud(){
        // HUD - Always Last Thing!

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0, WIDTH, 0,HEIGHT, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();


    /* TIMER */
    int i;
    int min = 0;
    int sec = 0;

    if (timer > 0) {
        min = timer / 60;
        sec = timer % 60;
    }

    char time[6];

    sprintf(time, "%02d:%02d", min,sec);

    glLineWidth(3.0);

    if (timer > 0) {
        glColor3f(0.0, 1.0, 0.0);
    } else {
        glColor3f(1.0, 0.0, 0.0);
    }

    glTranslated(10, HEIGHT-37, 0);
    glScalef(0.3, 0.3, 0.0);
    for(i = 0; i < 5; i++) {
        glutStrokeCharacter(GLUT_STROKE_ROMAN, time[i]);
    }
    glLineWidth(1.0);

    glLoadIdentity();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
}

