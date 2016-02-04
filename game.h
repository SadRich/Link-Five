#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

typedef struct game{
    char **board; //Tableau a deux dimensions contenant le plateau de jeu
    char *first_player; //Chaine de caractere contenant le nom du personnage
    char *second_player;
    int board_size_x;
    int board_size_y;
}game_struct;

game_struct* new_game(char *first_player, char *second_player, int board_size_x, int board_size_y);
char** init_board(char **board, int board_size_x, int board_size_y);
void display_board(game_struct *game);
game_struct* init_game();
int start_game(game_struct *game);
int check_p1_diag2(game_struct *game, int x, int y);
int check_p1_diag1(game_struct *game, int x, int y);
int check_p1_row_y(game_struct *game, int x);
int check_p1_row_x(game_struct *game, int y);
int victory_conditions(game_struct *game, int x, int y);
int victory_check(int check_p1_row_x, int check_p1_row_y, int check_p1_diag1, int check_p1_diag2);
#endif // GAME_H_INCLUDED
