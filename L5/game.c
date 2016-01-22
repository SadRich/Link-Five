#include <stdio.h>
#include <stdlib.h>


typedef struct game{
    char **board;
    char* first_player;
    char* second_player;
}game_struct;

int input_board_size_x(int size_x)
{
    int board_size_x;
    printf("Définissez le nombre de colonnes pour le repère (min = 10 et max = 20):\n");
    do{
        scanf("%d", &board_size_x);
        if(board_size_x >= 10 || board_size_x <= 20){
            printf("Nombre de colonnes: %d", board_size_x);
        }
        else{
            printf("Valeur invalide, veuillez entrer à nouveau une valeur pour définir le nombre de colonnes:\n");
        }
    }while(board_size_x < 10 || board_size_x > 20);
    return board_size_x;
}

int input_board_size_y(int size_y)
{
    int board_size_y;
    printf("Définissez le nombre de lignes pour le repère (min = 10 et max = 20):\n");
    do{
        scanf("%d", &board_size_y);
        if(board_size_y >= 10 || board_size_y <= 20){
            printf("Nombre de colonnes: %d", board_size_y);
        }
        else{
            printf("Valeur invalide, veuillez entrer à nouveau une valeur pour définir le nombre de lignes:\n");
        }
    }while(board_size_y < 10 || board_size_y > 20);
    return board_size_y;
}

char** init_board(char **board, int board_size_x, int board_size_y)
{
    board = malloc(board_size_y * sizeof(char));
    int i;
    for(i = 0; i < board_size_y; i++)
    {
        board[i] = malloc(board_size_x * sizeof(char));
    }
    return board;
}

game_struct* new_game(char* first_player, char* second_player)
{
    game_struct* game = malloc(sizeof(game_struct));
    game->first_player = first_player;
    game->second_player = second_player;
    int i, j;

    game->board = init_board(game->board);
    for(i = 0; i < board_size_y; i++){
        for(j = 0; j < board_size_x; j++){
            game->board[i][j] = '0';
        }
    }
    printf("game initialized\n");

    return game;
}

game_struct* init_game(){
    char *first_player, *second_player;
    first_player = malloc(100 * sizeof(char));
    second_player = malloc(100 * sizeof(char));

    printf("Bienvenue dans le jeu Link Five.\nPour commencer, veuillez saisir le pseudo des deux joueurs.\n");
    printf("Joueur 1 : ");
    scanf("%s", first_player);
    printf("\nJoueur 2 : ");
    scanf("%s", second_player);

    game_struct *game = new_game(first_player, second_player);
    printf("\n\n");

    return game;
}

void display_board(char **board)
{
    int i, j;
    printf("  0 1 2 3 4 5 6 7 8 9\n");
    for(i = 0; i < board_size_y; i++) {
        printf("%i ", i);
        for (j = 0; j < board_size_x; j++){
            if(board[i][j]=='X'){
                printf("X");
            }
            else if(board[i][j]=='O'){
                printf("O");
            }
            else{
                printf("-");
            }
            printf(" ");
        }
        printf("\n");
    }

}

int input_y()
{
    int y = -1;
    do{
        printf("Entrez l'ordonnée : ");
        scanf("%d", &y);
        if (y < 0 || y > board_size_y - 1){
            printf("Ordonnée non existante dans le repère, veuillez saisir une nouvelle ordonnée\n");
        }
        int c;
        while ( ((c = getchar()) != '\n') && c != EOF)
        {
        };
    }while(y < 0 || y >9);
    return y;
}

int input_x()
{
    int x = -1;
    do{
        printf("Entrez l'abscisse : ");
        scanf("%d", &x);
        if (x < 0 || x > board_size_x - 1){
            printf("Ordonnée non existante dans le repère, veuillez saisir une nouvelle abscisse\n");
        }
        int c;
        while ( ((c = getchar()) != '\n') && c != EOF)
        {
        };
    }while(x < 0 || x >9);
    return x;
}

int check_coordinates(int x, int y, char **board)
{
    if (board[y][x] == 'X' || board[y][x] == 'O'){
        return 0;
    }
    return 1;
}

int input_coordinates(int *x, int *y, game_struct *game){
    int valid_coordinates = 0;
    do {
        *y = input_y();
        *x = input_x();
        if (check_coordinates(*x, *y, game->board) == 0){
            valid_coordinates = 0;
        }else{
            valid_coordinates = 1;
        }
    } while(valid_coordinates == 0);
    return valid_coordinates;
}

int start_game(game_struct *game)
{
    display_board(game->board);

    printf("%s, jouez votre pion en entrant les coordonnées ordonnée abscisse\n", game->first_player);
    int x = -1, y = -1;
    if(input_coordinates(&x, &y, game)){
        game->board[x][y] = 'X';
    }

    display_board(game->board);
    printf("%s, jouez votre pion en entrant les coordonnées ordonnée abscisse\n", game->second_player);
    if(input_coordinates(&x, &y, game)){
        game->board[x][y] = 'O';
    }

    display_board(game->board);
    return 0;
}

/*int put_piece(int x, int y, char piece, game_struct *game)
{
    if(game->board[x][y] == NULL){
        game->board[x][y] = piece;
        return 1;
    }
    else
    {
            return 0;
    }
}*/
