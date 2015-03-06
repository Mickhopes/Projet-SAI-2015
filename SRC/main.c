#include "maze.h"

int main(int argc, char* argv[]) {

	if (! init_maze(&maze, 5, 5, 5) )
		return EXIT_FAILURE;

	printf("%d\n", maze.cases[0][0][0].MUR_HAUT);

	free_maze(&maze);

	return 0;
}