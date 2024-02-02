#include <stdlib.h>
#include <stdio.h>
#include <time.h>
 

typedef struct conway_game {
    int width;
    int height;
    char* cells;
} conway_game;

void print(conway_game* game) {
    for(int h = 0; h < game->height; ++h) {
        for(int w = 0; w < game->width; ++w) {
            printf("%d ", game->cells[h * game->width + w] & 0x01);
        }
        printf("\n");
    }
}

conway_game* initialize(int width, int height) {
    srand(time(NULL));

    char* cells = malloc(sizeof(char) * width * height);
    for(int c = 0; c < width * height; ++c) {
        cells[c] = (rand() % 2 == 0) ? 0x00 : 0x01;
    }

    conway_game* game = malloc(sizeof(conway_game));
    game->width = width;
    game->height = height;
    game->cells = cells;

    return game;
}

void destroy(conway_game* game) {
    free(game->cells);
    free(game);
}

int main()
{
    conway_game* game_ptr = initialize(8, 8);
    print(game_ptr);
    destroy(game_ptr);
 
    return 0;
}
