#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "conway.h"

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
