#ifndef MAP_H_
#define MAP_H_



// NOTE: the example of map
/*
10 10      // width and height each
1111111111 // 0 means empty
S000000000 // 1 means filled
1111110011 // S: starting point
0000000011 // E: end point
0000000011
0000111111
1100000000
0000111111
1100111111
000000000E
 */
struct map_t {
	int width;
	int height;

	int num_bodies; // the number of bodies in the map
	
	// TODO: Add more what you want
};

struct map_t* create_map(const char* path);
void destroy_map(struct map_t* map);

#endif // MAP_H_
