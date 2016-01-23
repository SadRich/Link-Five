#include <stdio.h>
#include <stdlib.h>


typedef struct game{ // Creation d'une structure
    char **board; //Tableau a deux dimensions contenant le plateau de jeu
    char *first_player; //Chaine de caractere contenant le nom du personnage
    char *second_player;
    int board_size_x;
    int board_size_y;
}game_struct; //nommage du type qui sera declare plus tard

/*int input_board_size_x(int size_x)
{
    int board_size_x;
    printf("Definissez le nombre de colonnes pour le repere (min = 10 et max = 20):\n");
    do{
        scanf("%d", &board_size_x);
        if(board_size_x >= 10 || board_size_x <= 20){
            printf("Nombre de colonnes: %d", board_size_x);
        }
        else{
            printf("Valeur invalide, veuillez entrer a nouveau une valeur pour definir le nombre de colonnes:\n");
        }
    }while(board_size_x < 10 || board_size_x > 20);
    return board_size_x;
}

int input_board_size_y(int size_y)
{
    int board_size_y;
    printf("Definissez le nombre de lignes pour le repere (min = 10 et max = 20):\n");
    do{
        scanf("%d", &board_size_y);
        if(board_size_y >= 10 || board_size_y <= 20){
            printf("Nombre de colonnes: %d", board_size_y);
        }
        else{
            printf("Valeur invalide, veuillez entrer a nouveau une valeur pour definir le nombre de lignes:\n");
        }
    }while(board_size_y < 10 || board_size_y > 20);
    return board_size_y;
}*/

char** init_board(char **board, int board_size_x, int board_size_y)
{
    board = malloc(board_size_y * sizeof(char*)); // Creation d'un tableau a une dimension
    int i, j;
    for(i = 0; i < board_size_y; i++) // Parcours de chaque cellule du tableau pour creer des tableaux
    {
       *(board + i) = malloc(board_size_x * sizeof(char*)); // "*(board + i" equivaut a "board[i]" => on creer les tableaux dans les cellules
    }

    for(i = 0; i < board_size_y; i++){
        for(j = 0; j < board_size_x; j++){
            board[i][j] = '0';
        }
    }
    return board;
}

game_struct* new_game(char *first_player, char *second_player, int board_size_x, int board_size_y) // sert uniquement a la fonction init_game
{
    printf("new_game");
    game_struct* game = malloc(sizeof(game_struct));
    game->first_player = first_player; // first player est vide mais on lui rajoute la valeur de first player dans init_game
    game->second_player = second_player;

    game->board = init_board(game->board, board_size_x, board_size_y); // on va initialiser le tableau avec la fonction init_board

    game->board_size_x = board_size_x;
    game->board_size_y = board_size_y;



    printf("game initialized\n");

    return game;
}

game_struct* init_game(){
    char *first_player, *second_player;
    first_player = malloc(100 * sizeof(char)); // tableau a 100 caracteres
    second_player = malloc(100 * sizeof(char));

    printf("Bienvenue dans le jeu Link Five.\nPour commencer, veuillez saisir le pseudo des deux joueurs.\n");

    printf("Joueur 1 : ");
    int check_first_player = 0;
    while(!check_first_player) {
        check_first_player = scanf("%s", first_player); // va etre utilise dans la fonction new_game
    }

    printf("\nJoueur 2 : ");
    int check_second_player = 0;
    while(!check_second_player){
        check_second_player = scanf("%s", second_player);
    } // va etre utilise dans la fonction new_game

    int board_size_x;
    printf("Definissez le nombre de colonnes pour le repere (min = 10 et max = 20):\n");
    do{
        int check_board_size_x = 0;
        while(!check_board_size_x){
            check_board_size_x = scanf("%d", &board_size_x);
        }

        if(board_size_x >= 10 && board_size_x <= 20){
            printf("Nombre de colonnes: %d\n", board_size_x);
        }
        else{
            printf("Valeur invalide, veuillez entrer a nouveau une valeur pour definir le nombre de colonnes:\n");
        }
    }while(board_size_x < 10 || board_size_x > 20);

    int board_size_y;
    printf("Definissez le nombre de lignes pour le repere (min = 10 et max = 20):\n");
    do{
        int check_board_size_y = 0;
        while(!check_board_size_y){
            check_board_size_y = scanf("%d", &board_size_y);
        }
        if(board_size_y >= 10 && board_size_y <= 20){
            printf("Nombre de lignes: %d\n", board_size_y);
        }
        else{
            printf("Valeur invalide, veuillez entrer a nouveau une valeur pour definir le nombre de lignes:\n");
        }
    }while(board_size_y < 10 || board_size_y > 20);

    game_struct *game = new_game(first_player, second_player, board_size_x, board_size_y);
    printf("\n\n");


    return game;
}

void display_board(game_struct *game)
{
    int i, j;
    printf("   ");
    for(i = 1; i < game->board_size_x+1; i++){
        if(i < 10){
            printf(" %i ", i);
        }
        else{
            printf("%i ", i);
        }

    }
    printf("\n");
    for(i = 0; i < game->board_size_y; i++) {
        if(i < 9){
            printf(" %i ", i+1);
        }
        else{
            printf("%i ", i+1);
        }
        for (j = 0; j < game->board_size_x; j++){
            if(game->board[i][j]=='X'){
                printf(" X");
            }
            else if(game->board[i][j]=='O'){
                printf(" O");
            }
            else{
                printf(" -");
            }
            printf(" ");
        }
        printf("\n");
    }

}

int input_y(game_struct *game)
{
    int y = -1;
    do{
        printf("Entrez l'ordonnee : ");
        int check_y = 0;
        while(!check_y){
            check_y = scanf("%d", &y);
        }
        if (y < 0 || y > game->board_size_y - 1){
            printf("Ordonnee non existante dans le repere, veuillez saisir une nouvelle ordonnee\n");
        }
        int c;
        while ( ((c = getchar()) != '\n') && c != EOF)
        {
        };
    }while(y < 0 || y >9);
    return y;
}

int input_x(game_struct *game)
{
    int x = -1;
    do{
        printf("Entrez l'abscisse : ");
        int check_x = 0;
        while(!check_x){
            check_x = scanf("%d", &x);
        }

        if (x < 0 || x > game->board_size_x - 1){
            printf("Ordonnee non existante dans le repere, veuillez saisir une nouvelle abscisse\n");
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
        *x = input_x(game);
        *y = input_y(game);

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
    display_board(game);

    printf("%s, jouez votre pion en entrant les coordonnees ordonnee abscisse\n", game->first_player);
    int x = -1, y = -1;
    if(input_coordinates(&x, &y, game)){
        game->board[y-1][x-1] = 'X';
    }
    printf("x : %i, y : %i\n", x, y);

    display_board(game);
    printf("%s, jouez votre pion en entrant les coordonnees ordonnee abscisse\n", game->second_player);
    if(input_coordinates(&x, &y, game)){
        game->board[y-1][x-1] = 'O';
    }

    display_board(game);
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
