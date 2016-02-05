#include <stdio.h>
#include <stdlib.h>
#include "game.h"

int main()
{
    // compteur du nombre de victoires pour les scores
    int count_p1_victories = 0, count_p2_victories = 0;
    game_struct *game = init_game(); // Cree une variable avec la structure game_struct et a qui on lui attribue comme valeur la fonction init_game qui a la meme structure pour plus de proprete

    int replay = 0; // variable booleenne pour savoir si le joueur veut rejouer
    do{
        // play again est une fonction qui a pour but de réinitialiser le board en le vidant prealablement
        if(count_p1_victories > 0 || count_p2_victories > 0)
            game = play_again(game);
        int player_number = start_game(game); // on APPELLE la fonction start_game() avec comme parametre game (ainsi que ses variables initialisees precedement)
        if(player_number == 1)
            count_p1_victories++;
        else
            count_p2_victories++;

        printf("Fin de la partie :\n");
        printf("%s a %d victoires\n", game->first_player, count_p1_victories);
        printf("%s a %d victoires\n", game->second_player, count_p2_victories);

        printf("Voulez-vous rejouer (1 pour oui, 2 pour non)?\n");
        scanf("%d", &replay);
    }while(replay == 1);

    free(game);
    //system("pause"); // laisser la console affichee une fois le programme termine !!! (Ne marche que sur Windows) !!!
    return 0;
}
