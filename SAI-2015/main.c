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
float angle_rotor, angle_rotor_queue;

void affichage();
void dec_timer(int value);
void init_variables();
int load_gl_textures();

int main(int argc, char* argv[]) {
	if (!init_maze(&maze, TAILLE_LABY_X, TAILLE_LABY_Y, TAILLE_LABY_Z)) {
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

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glutTimerFunc(1000, dec_timer, 0);

	glutMainLoop();

	return 0;
}

void init_variables() {
    obs.x = TAILLE_CUBE/2;
	obs.y = TAILLE_CUBE/2;
	obs.z = -TAILLE_CUBE-(TAILLE_CUBE/2);
	vis.x = 0;
	vis.y = 0;
	vis.z = 0;

	helico_pos.x = (maze.length*TAILLE_CUBE)/2;
	helico_pos.y = (maze.height*TAILLE_CUBE)+11;
	helico_pos.z = (maze.width*TAILLE_CUBE)/2;

	angle_rotor = 0.0;
	angle_rotor_queue = 45.0;

    tab_key[HAUT] = 0;
	tab_key[BAS] = 0;
	tab_key[GAUCHE] = 0;
	tab_key[DROITE] = 0;
	tab_key[DESSUS] = -1;
	tab_key[DESSOUS] = -1;

	timer = TIMER;
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

    texture[3] = SOIL_load_OGL_texture
        (
        "fence.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
        );

    if(texture[0] == 0 || texture[1] == 0 || texture[2] == 0 || texture[3] == 0)
        return 0;

    return 1;
}

void affichage() {
    camera();

    /* largeur = helico_pos.x +- 10
     * longueur = helico_pos.z - 18.5 && helico_pos.z + 35
     * hauteur = helico_pos.y + 7.5 && helico_pos.y - 9
     * Ici on vérifie que l'utilisateur est arrivé sur l'hélico ou pas */
    if (obs.x >= helico_pos.x-10 && obs.x <= helico_pos.x+10 && obs.y >= helico_pos.y-9 && obs.y <= helico_pos.y+7.5 && obs.z >= helico_pos.z-18.5 && obs.z <= helico_pos.z+35) {
        printf("\nTu as reussi ! Bravo !\n");
        free_maze(&maze);
        exit(EXIT_SUCCESS);
    }

    if (timer <= -5) {
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

    helico(helico_pos.x, helico_pos.y, helico_pos.z);

    hud();

	glutSwapBuffers();
}

void dec_timer(int value) {
    if (timer > -5) {
        timer--;
        glutTimerFunc(1000, dec_timer, 0);
    }
}
