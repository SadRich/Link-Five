#include <stdio.h>
#include <stdlib.h>
#include "game.h"

int main(int argc, char **argv)
{
    game_struct *game = init_game(); // Cree une variable avec la structure game_struct et a qui on lui attribue comme valeur la fonction init_game
    start_game(game);

    free(game);
    system("pause");
    return 0;
}
