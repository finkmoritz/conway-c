#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "conway.h"

int cell_state(conway_game* game, int x, int y)
{
    unsigned char *cell_ptr;

    cell_ptr = game->cells + (y * game->width) + x;
    return *cell_ptr & 0x01;
}

void clear_cell(conway_game* game, unsigned int x, unsigned int y)
{
    int xoleft, xoright, yoabove, yobelow;
    unsigned char *cell_ptr = game->cells + y * game->width + x;

    // Calculate the offsets to the eight neighboring cells,
    // accounting for wrapping around at the edges of the cell map
    if (x == 0)
        xoleft = game->width - 1;
    else
        xoleft = -1;
    if (y == 0)
        yoabove = game->width * game->height - game->width;
    else
        yoabove = -game->width;
    if (x == (game->width - 1))
        xoright = -(game->width - 1);
    else
        xoright = 1;
    if (y == (game->height - 1))
        yobelow = -(game->width * game->height - game->width);
    else
        yobelow = game->width;

    *(cell_ptr) &= ~0x01;
    *(cell_ptr + yoabove + xoleft) -= 2;
    *(cell_ptr + yoabove ) -= 2;
    *(cell_ptr + yoabove + xoright) -= 2;
    *(cell_ptr + xoleft) -= 2;
    *(cell_ptr + xoright) -= 2;
    *(cell_ptr + yobelow + xoleft) -= 2;
    *(cell_ptr + yobelow) -= 2;
    *(cell_ptr + yobelow + xoright) -= 2;
}

void destroy(conway_game* game) {
    free(game->cells);
    free(game);
}

conway_game* initialize(int width, int height) {
    srand(time(NULL));

    char* cells = malloc(sizeof(char) * width * height);
    for(int c = 0; c < width * height; ++c) {
        cells[c] = rand() % 2;
    }

    conway_game* game = malloc(sizeof(conway_game));
    game->width = width;
    game->height = height;
    game->cells = cells;

    return game;
}

void print(conway_game* game) {
    for(int h = 0; h < game->height; ++h) {
        for(int w = 0; w < game->width; ++w) {
            printf("%d ", game->cells[h * game->width + w] & 0x01);
        }
        printf("\n");
    }
}


void set_cell(conway_game* game, unsigned int x, unsigned int y)
{
    int xoleft, xoright, yoabove, yobelow;
    unsigned char *cell_ptr = game->cells + y * game->width + x;

    // Calculate the offsets to the eight neighboring cells,
    // accounting for wrapping around at the edges of the cell map
    if (x == 0)
        xoleft = game->width - 1;
    else
        xoleft = -1;
    if (y == 0)
        yoabove = game->width * game->height - game->width;
    else
        yoabove = -game->width;
    if (x == (game->width - 1))
        xoright = -(game->width - 1);
    else
        xoright = 1;
    if (y == (game->height - 1))
        yobelow = -(game->width * game->height - game->width);
    else
        yobelow = game->width;

    *(cell_ptr) |= 0x01;
    *(cell_ptr + yoabove + xoleft) += 2;
    *(cell_ptr + yoabove) += 2;
    *(cell_ptr + yoabove + xoright) += 2;
    *(cell_ptr + xoleft) += 2;
    *(cell_ptr + xoright) += 2;
    *(cell_ptr + yobelow + xoleft) += 2;
    *(cell_ptr + yobelow) += 2;
    *(cell_ptr + yobelow + xoright) += 2;
}
