#include <stdio.h>
#include <stdlib.h>
#include "game.h"

int main()
{
    game_struct *game = init_game();
    start_game(game);

    system("pause");
    return 0;
}
