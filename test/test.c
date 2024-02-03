#include <conway.h>

int main()
{
    conway_game* game_ptr = initialize(3, 3);
    set_cell(game_ptr, 0, 0);
 
    int test_success = cell_state(game_ptr, 0, 0) == 1;

    destroy(game_ptr);
 
    return 1 - test_success;
}
