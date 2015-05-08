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
                    glColor3f(0.4,0.4,0.4);
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
                    glColor3f(0.4,0.4,0.4);
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
                    glColor3f(0.4,0.4,0.4);
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
                glLineWidth(2.0);
                /* On dessine le mur arrière */
                if (maze->cases[z][x][y].MUR_ARRIERE == 1) {
                    glBegin(GL_QUADS);
                        glColor3f(0.4,0.4,0.4);
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
                        glColor3f(0.4,0.4,0.4);
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
                        glColor3f(0.4,0.4,0.4);
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
                            glColor3f(0.4,0.4,0.4);
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
                    mettre_fleche_montee(z, x, y);
                }
                /* On dessine l'indicateur de descente */
                if (maze->cases[z][x][y].MUR_BAS == 0) {
                    mettre_fleche_descente(x, y, z);
                }
            }
        }
    }

    glLineWidth(1.0);
 }

void mettre_fleche_montee(int z, int x, int y) {
    float tx, ty, tz;
    float rotate = -1.0;

    /* On dessinera si possible les indicateurs sur ce mur */
    if (maze.cases[z][x][y].MUR_DROITE == 1) {
        tx = x*TAILLE_CUBE+TAILLE_CUBE/2;
        ty = y*TAILLE_CUBE+TAILLE_CUBE/2;
        tz = z*TAILLE_CUBE+TAILLE_CUBE;
    } else {
        /* Sinon on prendra le mur suivant */
        if (maze.cases[x][y][z].MUR_AVANT == 1) {
            tx = x*TAILLE_CUBE;
            ty = y*TAILLE_CUBE+TAILLE_CUBE/2;
            tz = z*TAILLE_CUBE+TAILLE_CUBE/2;
            rotate = -90.0;
        } else {
            /* etc... */
            if (maze.cases[x][y][z].MUR_GAUCHE == 1) {
                tx = x*TAILLE_CUBE+TAILLE_CUBE/2;
                ty = y*TAILLE_CUBE+TAILLE_CUBE/2;
                tz = z*TAILLE_CUBE;
                rotate = 180.0;
            } else {
                if (maze.cases[x][y][z].MUR_ARRIERE == 1) {
                    tx = x*TAILLE_CUBE+TAILLE_CUBE;
                    ty = y*TAILLE_CUBE+TAILLE_CUBE/2;
                    tz = z*TAILLE_CUBE+TAILLE_CUBE/2;
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
        tx = x*TAILLE_CUBE+TAILLE_CUBE/2;
        ty = y*TAILLE_CUBE+TAILLE_CUBE/2;
        tz = z*TAILLE_CUBE+TAILLE_CUBE;
    } else {
        /* Sinon on prendra le mur suivant */
        if (maze.cases[x][y][z].MUR_AVANT == 1) {
            tx = x*TAILLE_CUBE;
            ty = y*TAILLE_CUBE+TAILLE_CUBE/2;
            tz = z*TAILLE_CUBE+TAILLE_CUBE/2;
            rotate = -90.0;
        } else {
            /* etc... */
            if (maze.cases[x][y][z].MUR_GAUCHE == 1) {
                tx = x*TAILLE_CUBE+TAILLE_CUBE/2;
                ty = y*TAILLE_CUBE+TAILLE_CUBE/2;
                tz = z*TAILLE_CUBE;
                rotate = 180.0;
            } else {
                if (maze.cases[x][y][z].MUR_ARRIERE == 1) {
                    tx = x*TAILLE_CUBE+TAILLE_CUBE;
                    ty = y*TAILLE_CUBE+TAILLE_CUBE/2;
                    tz = z*TAILLE_CUBE+TAILLE_CUBE/2;
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



void helico(){

    /* Coordonnées de base du centre du corps de l'hélico */
    int xH = (maze.width*TAILLE_CUBE)/2;
    int yH = (maze.height*TAILLE_CUBE)+17;
    int zH = (maze.length*TAILLE_CUBE)/2;

    /* Fuselage de l'hélico <=> ellipsoïde de centre xH, yH, zH */
    glPushMatrix();
    glTranslatef(xH,yH,zH);
    glScalef(2.0,3.0,6.0);
    glColor3f(0,0,1);
    gluSphere(gluNewQuadric(), 5.0, 20, 20);
    glPopMatrix();


    glPushMatrix();
    /* Train d'atterrissage */

    /* Mat */

    /* Pales de rotor*/

    /* Queue */

    /* Rotor de Queue */


    glPopMatrix();




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
    int min = timer / 60;
    int sec = timer % 60;
    char time[5];

    sprintf(time, "%d:%d", min, sec);

    glLineWidth(2.0);
    glColor3f(1.0, 0.0, 0.0);
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
