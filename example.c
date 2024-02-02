#include "conway.h"

int main()
{
    conway_game* game_ptr = initialize(8, 8);
    print(game_ptr);
    destroy(game_ptr);
 
    return 0;
}
