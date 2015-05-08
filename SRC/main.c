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

#include "inputs.h"
#include "maze.h"
#include "objects.h"

int timer;

void affichage();
void dec_timer(int value);

int main(int argc, char* argv[]) {
	if (!init_maze(&maze, TAILLE_LABY, TAILLE_LABY, TAILLE_LABY))
		return EXIT_FAILURE;

	generate_maze(&maze);

	show_maze(&maze);

	obs.x = TAILLE_CUBE/2;
	obs.y = TAILLE_CUBE/4;
	obs.z = TAILLE_CUBE/2;
	vis.x = 0;
	vis.y = 0;
	vis.z = 1;

	timer = 300;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition(50, 50);

	glutCreateWindow("CrazyLaby");
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(70, (double)WIDTH/(double)HEIGHT, 1, 800);

	glEnable(GL_DEPTH_TEST);

	glutIdleFunc(raffraichissement);
    glutKeyboardFunc(gererClavier);
    glutKeyboardUpFunc(relacherClavier);
    glutMotionFunc(vMotion);
    glutPassiveMotionFunc(vMotion);
	glutDisplayFunc(affichage);

	glutTimerFunc(1000, dec_timer, 0);

	glutMainLoop();

	return 0;
}

void affichage() {
    camera();

    if (0 == 1) {
        printf("\nTu as réussi ! Bravo !\n");
        free_maze(&maze);
        exit(EXIT_SUCCESS);
    }

    if (timer <= 0) {
        printf("\nTu as mis trop de temps !\n");
        free_maze(&maze);
        exit(EXIT_SUCCESS);
    }

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(obs.x,obs.y,obs.z, obs.x+vis.x, obs.y+vis.y, obs.z+vis.z, 0, 1, 0);

    glutSetCursor(GLUT_CURSOR_CROSSHAIR);
    glutWarpPointer(WIDTH/2, HEIGHT/2);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/* Sol */
	glBegin(GL_QUADS);
	    glColor3f(0,0.4,0);
	    glVertex3f(-(TAILLE_CUBE*maze.length),-0.1,-(TAILLE_CUBE*maze.width));
	    glVertex3f((TAILLE_CUBE*maze.length)+(TAILLE_CUBE*maze.length),-0.1,-(TAILLE_CUBE*maze.width));
	    glVertex3f((TAILLE_CUBE*maze.length)+(TAILLE_CUBE*maze.length),-0.1,(TAILLE_CUBE*maze.width)+(TAILLE_CUBE*maze.width));
	    glVertex3f(-(TAILLE_CUBE*maze.length),-0.1,(TAILLE_CUBE*maze.width)+(TAILLE_CUBE*maze.width));
	glEnd();

	glBegin(GL_LINE_LOOP);
	    glColor3f(0, 0, 0);
	    glVertex3f(-(TAILLE_CUBE*maze.length),-0.1,-(TAILLE_CUBE*maze.width));
	    glVertex3f((TAILLE_CUBE*maze.length)+(TAILLE_CUBE*maze.length),-0.1,-(TAILLE_CUBE*maze.width));
	    glVertex3f((TAILLE_CUBE*maze.length)+(TAILLE_CUBE*maze.length),-0.1,(TAILLE_CUBE*maze.width)+(TAILLE_CUBE*maze.width));
	    glVertex3f(-(TAILLE_CUBE*maze.length),-0.1,(TAILLE_CUBE*maze.width)+(TAILLE_CUBE*maze.width));
	glEnd();

    helico();
    labyrinthe(&maze);
    hud();

	glutSwapBuffers();
}

void dec_timer(int value) {
    if (timer > 0) {
        timer--;
        glutTimerFunc(1000, dec_timer, 0);
    }
}
