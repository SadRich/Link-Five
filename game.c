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

    for(i = 0; i < board_size_y; i++){ // on cree le reste de la grille de depart represente par des "-" pour les coordonnees vides
        for(j = 0; j < board_size_x; j++){
            board[i][j] = '-';
        }
    }
    return board;
}

game_struct* new_game(char *first_player, char *second_player, int board_size_x, int board_size_y) // sert uniquement a la fonction init_game
{
    game_struct* game = malloc(sizeof(game_struct));
    game->first_player = first_player; // first player est vide mais on lui rajoute la valeur de first player (celle de init_game)
    game->second_player = second_player;

    game->board = init_board(game->board, board_size_x, board_size_y); // on va initialiser le tableau avec la fonction init_board

    game->board_size_x = board_size_x; // on attribue la nouvelle valeur a la variable
    game->board_size_y = board_size_y;



    printf("game initialized\n");

    return game; // on retourne toutes les valeurs ci dessus pour toutes les variables de la structure game
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
        while(!check_board_size_x){ // !x = tant que la variable est egale a 0
            check_board_size_x = scanf("%d", &board_size_x); // s'íl y a un probleme avec la fonction scanf, celle-ci retourne la valeur 0. sinon, elle retourne la valeur 1. On stocke donc cette valeur afin d'etre sur que board_size_x contient bien la valeur qui a ete saisie par l'utilisateur. (ça marche comme ça, c'est la doc de scanf)
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

    game_struct *game = new_game(first_player, second_player, board_size_x, board_size_y); // on recupere les variables avec leurs valeurs pour la structure game (qui ont ete initialisees dans la fonction new_game)
    printf("\n\n");


    return game; // on retourne game qui a pris les valeurs de new_game pour init_game qui va elle etre ensuite attribuee a la variable "game" dans le main
}

void display_board(game_struct *game) // ici on affiche le tableau qu'on avait initialise dans init_board
{
    int i, j;
    printf("   ");
    for(i = 1; i < game->board_size_x+1; i++){ // on cree la premiere ligne avec la numerotation de l'abscisse
        if(i < 10){
            printf(" %i ", i);
        }
        else{
            printf("%i ", i);
        }

    }
    printf("\n");
    for(i = 0; i < game->board_size_y; i++) {
        if(i < 9){ // on cree la numerotation de l'ordonnee
            printf(" %i ", i+1); // pour la numerotation a 1 chiffre, on ajoute un espace en premier pour ne pas que tout soit decale
        }
        else{
            printf("%i ", i+1); // si il y a 2 chiffres, il n'y a pas besoin d'espace
        }
        for (j = 0; j < game->board_size_x; j++){ // on affiche le repere
            if(game->board[i][j]=='X'){ // si l'emplacement contient un pion X, on remet la meme chose (on va rappeler la fonction apres chaque tour joue donc c'est necessaire)
                printf(" X");
            }
            else if(game->board[i][j]=='O'){
                printf(" O");
            }
            else{
                printf(" %c", game->board[i][j]); // si il n'y a pas de pions joue a l'emplacement, on affiche "-" (board[i][j] = "-" dans init_board)
            }
            printf(" "); // on met un espace pour delimiter les cases
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
        if (y < 0 || y > game->board_size_y){
            printf("Ordonnee non existante dans le repere, veuillez saisir une nouvelle ordonnee\n");
        }
        int c;
        while ( ((c = getchar()) != '\n') && c != EOF)
        {
        };
    }while(y < 0 || y > game->board_size_y);
    return y;
}

int input_x(game_struct *game) // demande a l'utilisateur de saisir une valeur, qui est ensuite verifiee
{
    int x = -1;
    do{
        printf("Entrez l'abscisse : ");
        int check_x = 0;
        while(!check_x){
            check_x = scanf("%d", &x);
        }
        if (x < 0 || x > game->board_size_x){
            printf("Ordonnee non existante dans le repere, veuillez saisir une nouvelle abscisse\n");
        }

        int c;
        while ( ((c = getchar()) != '\n') && c != EOF) // getchar() va prendre ce qui a ete saisie et l'efface (donc rien n'est attribue a la variable). Si on rajoute != '/n' il va seulement prendre les elements saisie apres un retour a la ligne.
        { // EOF = End Of File => Fin du buffer. Du coup, on met && != EOF ce qui veut dire que la boucle va continuer a effacer les elements saisis apres "\n" jusqu'a la fin du buffer.
        }; // si on ne met pas cette boucle, le joueur pourra saisir par exemple "hahah\nlolol" dans le premier scanf donc "lolol" sera automatiquement recupere par le prochain scanf sans demander a l'utilisateur de saisir une valeur.
    }while(x < 0 || x > game->board_size_x);
    return x;
}

int check_coordinates(int x, int y, char **board) // verifie que qu'il n'y a pas de pions joue a l'emplacement choisi
{
    if (board[y-1][x-1] == 'X' || board[y-1][x-1] == 'O'){ // si il y a deja un pion joue a l'emplacement, on retourne 0, si c'est vide on retourne 1. On compare avec board[y-1][x-1] car notre tableau commence a 1 alors que le tableau du programme commence a 0.
        return 0;
    }
    return 1;
}

int input_coordinates(int *x, int *y, game_struct *game){
    int valid_coordinates = 0;
    do {
        *x = input_x(game); // on demande au joueur de saisir une valeur pour l'abscisse et on verifie sa validite avec la fonction input_x
        *y = input_y(game);

        if (check_coordinates(*x, *y, game->board) == 0){ // si l'emplacement contient un pion joue...
            valid_coordinates = 0;
        }
        else{
            valid_coordinates = 1;
        }
    } while(valid_coordinates == 0); // tant que l'emplacement contient un pion joue, on redemande au joueur de saisir une valeur
    return valid_coordinates; // si les coordonnees sont valides, on retourne 1
}

int start_game(game_struct *game) // on DEFINIT la fonction start_game qui va utiliser la STRUCTURE "game" (avec ses variables ET SES VALEURS)
{
    while(1){
        display_board(game); // on APPELLE la fonction display_board qui va afficher le tableau avec la variable game

        printf("%s, jouez votre pion en entrant les coordonnees abscisse ordonnee\n", game->first_player);
        int x = -1, y = -1; // on initialise x et y par defaut avec une valeur hors du tableau donc -1 (0 fait partie du tableau) car si x et y
        if(input_coordinates(&x, &y, game)){ // si les coordonnees rentrees par le joueur sont valides (input_coordinates = 1), on place alors son pion
            game->board[y-1][x-1] = 'X'; // on place le pion a l'emplacement board[y-1][x-1] car le repere commence a 1 alors que l'indice d'un tableau commence a 0
        }
        printf("x : %i, y : %i\n", x, y);
        display_board(game);// on re-affiche le repere avec le pion joue

        printf("%s, jouez votre pion en entrant les coordonnees abscisse ordonnee\n", game->second_player);
        if(input_coordinates(&x, &y, game)){
            game->board[y-1][x-1] = 'O';
        }
        printf("x : %i, y : %i\n", x, y);
    }
    return 0;
}

int victory_conditions(game, int board_size_x, int board_size_y, char **board, char *first_player)
{
    for(i=0; i < game->board_size_x + 1; i++){
        if(!victory_check_p1_x(int board_size_x, int board_size_y, char **board){
           return 1;
        }
        else{
            return 0;
        }
    }
}

int victory_check_p1_x(game_struct *game)
{
    int i = 0;
    int in_row_X = 0;
    for(i=0; i < board_size_x + 1; i++){
        if(game->board[i][y] == 'X'){
            in_row_X = in_row_X+1;
        }
        if(in_row_X >= 5){
            break;
        }
        else{
            in_row_X = 0;
        }
        i = i+1;
    }
    if(in_row_X >= 5){
        return 1;
    }
    else{
        return 0;
    }
}
