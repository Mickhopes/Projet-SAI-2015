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

int main(int argc, char* argv[]) {

	if (!init_maze(&maze, 5, 5, 5))
		return EXIT_FAILURE;

	generate_maze(&maze);

	show_maze(&maze);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);



	// On fixe la taille de la fenêtre
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(50, 50);

	glutCreateWindow("CrazyLaby");
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glEnable(GL_DEPTH_TEST);
    glutKeyboardFunc(gererClavier);
	// On définit la fonction qui servira à l'affichage de la fenêtre
	glutDisplayFunc(affichage);

	// Puis on lance le tout
	glutMainLoop();

	return 0;
}

void gererClavier(unsigned char touche, int x, int y){
    if(touche == 'q'){
        free_maze(&maze);
        exit(EXIT_SUCCESS);
    }
}

void affichage(){
    int x,y,z;

    // On multiplie la matrice orthogonale à la matrice identité que l'on charge dans la matrice de projection
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-60, 60, -60, 60, 60, 120);
	gluLookAt(-20,0,-60, 0, 0, 0, 0, 1, 0);

	// On fait un reset de l'écran
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBegin(GL_QUADS);
    for(z=0;z<maze.width;z++){
        for(x=0;x<maze.length;x++){
            for(y=0;y<maze.heigth;y++){

                if(maze.cases[z][x][y].MUR_ARRIERE == 1) {
                    glColor3f(0.9,0.9,0.9);
                    glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE,z*TAILLE_CUBE);
                    glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE);
                    glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE);
                    glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE);
                }
                if(maze.cases[z][x][y].MUR_AVANT == 1){
                    glColor3f(0.2,0.2,0.2);
                    glVertex3f(x*TAILLE_CUBE,y*TAILLE_CUBE,z* TAILLE_CUBE);
                    glVertex3f(x*TAILLE_CUBE,y*TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE);
                    glVertex3f(x*TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE);
                    glVertex3f(x*TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE);
                }

                if(maze.cases[z][x][y].MUR_GAUCHE == 1){
                    glColor3f(0.5,0.5,0.5);
                    glVertex3f(x*TAILLE_CUBE,y*TAILLE_CUBE,z* TAILLE_CUBE);
                    glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE,z*TAILLE_CUBE);
                    glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE);
                    glVertex3f(x*TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE);
                }
                if(maze.cases[z][x][y].MUR_DROITE == 1){
                    glColor3f(0.7,0.5,0.7);
                    glVertex3f(x*TAILLE_CUBE,y*TAILLE_CUBE,z* TAILLE_CUBE+TAILLE_CUBE);
                    glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE);
                    glVertex3f(x*TAILLE_CUBE+TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE);
                    glVertex3f(x*TAILLE_CUBE,y*TAILLE_CUBE+TAILLE_CUBE,z*TAILLE_CUBE+TAILLE_CUBE);
                }

            }
        }
    }


    glEnd();

	// On envoie le tout au buffer d'affichage
	glutSwapBuffers();
}
