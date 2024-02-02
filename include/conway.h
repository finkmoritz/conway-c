#ifndef CONWAY_H_
#define CONWAY_H_

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
 
/* Holds all information needed for the Game of Life. */
typedef struct conway_game {
    int width;
    int height;
    char* cells;
} conway_game;

/* Free memory allocated by this object. */
void destroy(conway_game* game);

/* Randomly initialize a Game of Life. */
conway_game* initialize(int width, int height);

/* Print the cell map for this Game of Life. */
void print(conway_game* game);

#endif // CONWAY_H_