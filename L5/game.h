#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

typedef struct game{
    char **board;
    char* first_player;
    char* second_player;
}game_struct;

game_struct* new_game(char* first_player, char* second_player);
char** init_board(char **board);
void display_board(char **board);
game_struct* init_game();
int start_game(game_struct *game);

#endif // GAME_H_INCLUDED
