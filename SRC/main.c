#include "maze.h"

int main(int argc, char* argv[]) {

	if (! init_maze(&maze, 5, 5, 5) )
		return EXIT_FAILURE;

	generate_maze(&maze);

	show_maze(&maze);

	free_maze(&maze);

	return 0;
}