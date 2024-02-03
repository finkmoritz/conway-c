#ifndef CONWAY_H_
#define CONWAY_H_

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
 
/* Holds all information needed for the Game of Life. */
typedef struct conway_game {
    unsigned int width;
    unsigned int height;
    char* cells;
} conway_game;

/* Returns cell state (1=on or 0=off). */
int cell_state(conway_game* game, int x, int y);

/* Turns an on-cell off, decrementing the on-neighbor count for the
   eight neighboring cells. */
void clear_cell(conway_game* game, unsigned int x, unsigned int y);

/* Free memory allocated by this object. */
void destroy(conway_game* game);

/* Randomly initialize a Game of Life. */
conway_game* initialize(int width, int height);

/* Print the cell map for this Game of Life. */
void print(conway_game* game);

/* Turns an off-cell on, incrementing the on-neighbor count for the
   eight neighboring cells. */
void set_cell(conway_game* game, unsigned int x, unsigned int y);

#endif // CONWAY_H_