#include <stdio.h>
#include <stdlib.h>
#include "game.h"

int main()
{
    game_struct *game = init_game(); // Cree une variable avec la structure game_struct et a qui on lui attribue comme valeur la fonction init_game qui a la meme structure pour plus de proprete
    start_game(game); // on APPELLE la fonction start_game() avec comme parametre game (ainsi que ses variables initialisees precedement)

    free(game);
    //system("pause"); // laisser la console affichee une fois le programme termine !!! (Ne marche que sur Windows) !!!
    return 0;
}
