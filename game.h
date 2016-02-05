#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

typedef struct game{
    char **board; //Tableau a deux dimensions contenant le plateau de jeu
    char *first_player; //Chaine de caractere contenant le nom du personnage
    char *second_player;
    int board_size_x;
    int board_size_y;
    int force;
}game_struct;

game_struct* new_game(char *first_player, char *second_player, int board_size_x, int board_size_y);
char** init_board(char **board, int board_size_x, int board_size_y);
void display_board(game_struct *game);
game_struct* init_game();
int start_game(game_struct *game);

int check(game_struct *game);
int check_p1_x(int x, int y, game_struct *game);
int check_p1_y(int x, int y, game_struct *game);
int check_p1_diag1(int x, int y, game_struct *game);
int check_p1_diag2(int x, int y, game_struct *game);
int check_p2_x(int x, int y, game_struct *game);
int check_p2_y(int x, int y, game_struct *game);
int check_p2_diag1(int x, int y, game_struct *game);
int check_p2_diag2(int x, int y, game_struct *game);
game_struct* play_again(game_struct *game);

int power(int number, int power);
int is_integer(char *string);
int string_length(char *string);
int string_to_integer(char *string);




#endif // GAME_H_INCLUDED
