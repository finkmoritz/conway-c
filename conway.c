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
void destroy(conway_game* game) {
    free(game->cells);
    free(game);
}

/* Randomly initialize a Game of Life. */
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

/* Print the cell map for this Game of Life. */
void print(conway_game* game) {
    for(int h = 0; h < game->height; ++h) {
        for(int w = 0; w < game->width; ++w) {
            printf("%d ", game->cells[h * game->width + w] & 0x01);
        }
        printf("\n");
    }
}

int main()
{
    conway_game* game_ptr = initialize(8, 8);
    print(game_ptr);
    destroy(game_ptr);
 
    return 0;
}
