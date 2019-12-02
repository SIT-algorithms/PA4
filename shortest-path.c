#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

void get_shortest_path(struct path_t* path, struct map_t* map)
{
	// TODO: Fill it out!
}

int main(int argc, char** argv)
{
	if (argc != 2) {
		fprintf(stderr, "Usage: ./shortest-path <map-path>\n");
		exit(-1);
	}

	char map_path[4096];
	strcpy(map_path, argv[1]);

	struct map_t* map = create_map(map_path);

	struct path_t the_shortest_path;

	get_shortest_path(&the_shortest_path, map);

	struct path_node_t* visitor = the_shortest_path.head;
	assert(visitor);
	printf("[%d,%d]", visitor->x, visitor->y);


	do {
		printf("->[%d,%d]", visitor->x, visitor->y);
		visitor = visitor->next;
	} while (visitor);

	destroy_map(map);

	return 0;
}
