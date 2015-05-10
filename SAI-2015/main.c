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
void init_variables();
int load_gl_textures();

int main(int argc, char* argv[]) {
	if (!init_maze(&maze, TAILLE_LABY, TAILLE_LABY, TAILLE_LABY)) {
            printf("Erreur lors du chargement du labyrinthe !\n");
        return EXIT_FAILURE;
	}

	generate_maze(&maze);

	show_maze(&maze);

	init_variables();

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

	if (!load_gl_textures())
    {
        printf("Erreur lors du chargement des textures !\n");
        printf("%s\n", SOIL_last_result());
        return EXIT_FAILURE;
    }

    glEnable(GL_TEXTURE_2D);
    glShadeModel(GL_SMOOTH);
    glClearColor(0.0f, 0.0f, 0.0f, 0.5f);
    glClearDepth(1.0f);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glutTimerFunc(1000, dec_timer, 0);

	glutMainLoop();

	return 0;
}

void init_variables() {
    obs.x = TAILLE_CUBE/2;
	obs.y = TAILLE_CUBE/2;
	obs.z = TAILLE_CUBE/2;
	vis.x = 0;
	vis.y = 0;
	vis.z = 1;

	tab_key[DESSUS] = -1;
	tab_key[DESSOUS] = -1;

	timer = 300;
}

int load_gl_textures() {
    /* load an image file directly as a new OpenGL texture */
    texture[0] = SOIL_load_OGL_texture
        (
        "grass.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
        );

    texture[1] = SOIL_load_OGL_texture
        (
        "wall.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
        );

    texture[2] = SOIL_load_OGL_texture
        (
        "floor.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
        );

    if(texture[0] == 0 || texture[1] == 0 || texture[2] == 0)
        return 0;

    return 1;
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

    sol();

    labyrinthe(&maze);

    helico();

    hud();

	glutSwapBuffers();
}

void dec_timer(int value) {
    if (timer > 0) {
        timer--;
        glutTimerFunc(1000, dec_timer, 0);
    }
}
