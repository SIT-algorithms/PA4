#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>

#include <sys/queue.h>

#include "map.h"

struct path_node_t {
	int x;
	int y;

	struct path_node_t* next;
};

struct path_t {
	struct path_node_t* head;
};

void navigate(int num_bodies,
	      struct path_t** paths_per_bodies,
	      struct map_t* map)
{
	// TODO: Fill it out!
}

int main(int argc, char** argv)
{
	if (argc != 2) {
		fprintf(stderr, "Usage: ./navigator <map-path>\n");
		exit(-1);
	}

	char map_path[4096];
	strcpy(map_path, argv[1]);

	struct map_t* map = create_map(map_path);

	int num_bodies = map->num_bodies;
	struct path_t* paths_per_bodies = malloc(sizeof(struct path_t) * num_bodies);

	struct timespec start, stop;

	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);

	navigate(num_bodies, &paths_per_bodies, map);

	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &stop);

	for (int i = 0; i < num_bodies; ++i) {
		printf("body #%d: \n", i);
		struct path_node_t* visitor = paths_per_bodies[i].head;
		assert(visitor);
		printf("[%d,%d]", visitor->x, visitor->y);


		do {
			printf("->[%d,%d]", visitor->x, visitor->y);
			visitor = visitor->next;
		} while (visitor);
	}

	free(paths_per_bodies);
	paths_per_bodies = NULL;

	double result = (stop.tv_sec - start.tv_sec) * 1e6 + (stop.tv_nsec - start.tv_nsec) / 1e3;
	printf("Elapsed time: %lf\n", result);

	destroy_map(map);

	return 0;
}
