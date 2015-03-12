/****************************************************
 * L3 informatique
 * Projet SAI
 *
 * Auteurs :  - Line Pouvaret
 *            - Mickaël Turnel
 *
 * Fichier : main.c
 *
 *****************************************************/

#include <math.h>
#include "GL/gl.h"
#include "GL/glut.h"
#include "maze.h"

#define TAILLE_CUBE 10

void gererClavier(unsigned char touche, int x, int y);
void affichage();
void raffraichissement();

Point obs, vis;

int main(int argc, char* argv[]) {

	if (!init_maze(&maze, 5, 5, 5))
		return EXIT_FAILURE;

	generate_maze(&maze);

	show_maze(&maze);

	obs.x = 0;
	obs.y = 0;
	obs.z = -60;
	vis.x = 0;
	vis.y = 0;
	vis.z = -58;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

	glutInitWindowSize(800, 600);
	glutInitWindowPosition(50, 50);

	glutCreateWindow("CrazyLaby");
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(70, (double)800/(double)600, 1, 800);

	glEnable(GL_DEPTH_TEST);

	glutIdleFunc(raffraichissement);
    glutKeyboardFunc(gererClavier);
	glutDisplayFunc(affichage);


	glutMainLoop();

	return 0;
}

void gererClavier(unsigned char touche, int x, int y){
    if(touche == 27){
        free_maze(&maze);
        exit(EXIT_SUCCESS);
    } else if (touche == 'z') {
        obs.z++;
        vis.z++;
    } else if (touche == 's') {
        obs.z--;
        vis.z--;
    } else if (touche == 'd') {
        obs.x--;
        vis.x--;
    } else if (touche == 'q') {
        obs.x++;
        vis.x++;
    }
}

void raffraichissement() {
    glutPostRedisplay();
}

void affichage(){
    int x,y,z;

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(obs.x,obs.y,obs.z, vis.x, vis.y, vis.z, 0, 1, 0);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBegin(GL_QUADS);

    for(z=0;z<maze.width;z++){
        for(x=0;x<maze.length;x++){
            for(y=0;y<maze.height;y++){
                if (maze.cases[z][x][y].MUR_ARRIERE == 1) {
                    glColor3f(0.9,0.9,0.9);
                    glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE,z*TAILLE_CUBE);
                    glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE);
                    glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE);
                    glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE);
                }
                if (maze.cases[z][x][y].MUR_AVANT == 1) {
                    glColor3f(0.2,0.2,0.2);
                    glVertex3f(x*TAILLE_CUBE,y*TAILLE_CUBE,z*TAILLE_CUBE);
                    glVertex3f(x*TAILLE_CUBE,y*TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE);
                    glVertex3f(x*TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE);
                    glVertex3f(x*TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE);
                }

                if (maze.cases[z][x][y].MUR_GAUCHE == 1) {
                    glColor3f(0.5,0.5,0.5);
                    glVertex3f(x*TAILLE_CUBE,y*TAILLE_CUBE,z*TAILLE_CUBE);
                    glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE,z*TAILLE_CUBE);
                    glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE);
                    glVertex3f(x*TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE);
                }
                if (maze.cases[z][x][y].MUR_DROITE == 1) {
                    glColor3f(0.7,0.5,0.7);
                    glVertex3f(x*TAILLE_CUBE,y*TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE);
                    glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE);
                    glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE);
                    glVertex3f(x*TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE);
                }
                if (maze.cases[z][x][y].MUR_BAS == 1) {
                    glColor3f(0.3,0.5,0.3);
                    glVertex3f(x*TAILLE_CUBE,y*TAILLE_CUBE,z*TAILLE_CUBE);
                    glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE,z*TAILLE_CUBE);
                    glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE);
                    glVertex3f(x*TAILLE_CUBE,y*TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE);
                }
                if (maze.cases[z][x][y].MUR_HAUT == 1) {
                    glColor3f(0.8,0.2,0.6);
                    glVertex3f(x*TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE);
                    glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE);
                    glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE);
                    glVertex3f(x*TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE);
                }
            }
        }
    }

    glEnd();

	glutSwapBuffers();
}
