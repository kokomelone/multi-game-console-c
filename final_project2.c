#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct player {
    char name[20];
    int position;
    int moves;
    char symbol;
} player;


char matrix[3][3];

void init_matrix(void);

void disp_matrix(void);

void get_player_move(void);

void get_computer_move(void);

void get_player1_move(void);

char check(void);

void play_tic_tac_toe();
            
int dice();

void UpdatedBoard();

void save_game(player players[], int NumPlayers);

int load_game(player players[], int *NumPlayers);

void log_results(player winner);

void play_snakes_and_ladders();

int main() {
    int choice;
    printf("--------------ARCADE MANIA---------------\n");
    printf("WELCOME!!!!!!\n");
    printf("Press 1 to play Snakes And Ladders!!!!!!\n");
    printf("Press 2 to play Tic Tac Toe!!!!!!\n");
    scanf("%d", &choice);
    if (choice == 1) {
        play_snakes_and_ladders();
    } else if (choice == 2) {
        play_tic_tac_toe();
    } else {
        printf("ERROR NEW GAMES UNDER WORK\n");
    }
    return 0;
}

void init_matrix(void) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix[i][j] = ' ';
        }
    }
}

void disp_matrix(void) {
    for (int t = 0; t < 3; t++) {
        printf(" %c | %c | %c ", matrix[t][0], matrix[t][1], matrix[t][2]);
        printf("\n---|---|---\n");
    }
    printf("\n");
}

void get_player_move(void) {
    int x, y;
    printf("Enter X,Y coordinates for your move: ");
    scanf("%d %d", &x, &y);
    x--; y--;
    if (matrix[x][y] != ' ') {
        printf("Invalid move, try again.\n");
        get_player_move();
    } else {
        matrix[x][y] = 'X';
    }
}

void get_computer_move(void) {
    { int i, j;

    for (j = 0; j < 3; j++) {
    int count_O = 0, count_space = 0, row = -1; 
    for (i = 0; i < 3; i++) {
        if (matrix[i][j] == 'O')
            count_O++;
        else if (matrix[i][j] == ' ')
        {
            count_space++;
            row = i;
        }
    }

    if (count_O == 2 && count_space == 1) {
        matrix[row][j] = 'O'; 
        return;
    }
}

    if (matrix[1][1] == ' '){

       matrix[1][1] = 'O';
    }
    else if (matrix[2][0] == ' ' && (matrix[1][1] == 'O' && matrix[0][2] != 'X')){

        matrix[2][0] = 'O';
    }
    else if ((matrix[2][2] == ' ') && (matrix[1][1] == 'O' && matrix[0][0] != 'X')){

        matrix[2][2] = 'O';
    }

   else{
        for (i = 0; i < 3; i++){
         for (j = 0; j < 3; j++){
                if (matrix[i][j] == ' ')

                    break;}
            if (matrix[i][j] == ' ')

                break;}
 if (i * j == 9){

         printf("draw\n");
        exit(0);}
else
 matrix[i][j] = 'O';
    }
}
}

void get_player1_move(void) {
    int x, y;
    printf("Player 2, enter X,Y coordinates for your move: ");
    scanf("%d %d", &x, &y);
    x--; y--;
   if (matrix[x][y] != ' ') {
        printf("Invalid move, try again.\n");
        get_player1_move();
    }
   else {
        matrix[x][y] = 'O';
    }
}


char check(void) {
    for (int i = 0; i < 3; i++) {
        if (matrix[i][0] == matrix[i][1] && matrix[i][1] == matrix[i][2]) return matrix[i][0];
    }
    for (int i = 0; i < 3; i++) {
        if (matrix[0][i] == matrix[1][i] && matrix[1][i] == matrix[2][i]) return matrix[0][i];
    }
    if (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2]){
     return matrix[0][0];
    }
    if (matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0]){
       return matrix[0][2];
    }
    return ' ';
}

void play_tic_tac_toe(){
    char done;
    int ch;

    printf("This is the game of Tic Tac Toe.\n");
    printf("Enter 1 to play against computer 2 to play against your friend\n");
    scanf("%d", &ch);
    if (ch == 1){
        printf("You will be playing against the computer.\n");
        done = ' ';
        init_matrix();

        while (done == ' '){

            disp_matrix();
            get_player_move();
            done = check();
       if (done != ' '){
            break;}
      get_computer_move();
       done = check();
        }

        disp_matrix();

        if (done == 'X'){
      printf("                YOU WON!!!!!!!!!       \n");
      }
     else{
            printf("                YOU LOST!!!!!!!!!      \n");
            }

    }
    if (ch == 2){

        done = ' ';
         init_matrix();

        while (done == ' '){

            disp_matrix();
            get_player_move();
            done = check();
            if (done != ' '){
                break;
            }
            disp_matrix();
            get_player1_move();
            done = check();}
            disp_matrix();
       if (done == 'X'){
                printf("               PLAYER1 WON!!!!!!!!!       \n");
                }
            else{
                printf("                PLAYER2 WON!!!!!!!!!      \n");
                }
       }
}

int dice() {
    return (rand() % 6) + 1;
}

void UpdatedBoard(player *players, int NumPlayers) {
    char board[101][4]; 

    for (int i = 1; i <= 100; i++) {
        sprintf(board[i], "%3d", i);
    }

    for (int i = 0; i < NumPlayers; i++) {
        int position = players[i].position;
        if (position <= 100) {
            board[position][0] = players[i].symbol;  
        }
    }

    printf("Updated Game Board:\n");

    for (int i = 100; i >= 91; i--) printf("%s ", board[i]);
    printf("\n");
    for (int i = 81; i <= 90; i++) printf("%s ", board[i]);
    printf("\n");
    for (int i = 80; i >= 71; i--) printf("%s ", board[i]);
    printf("\n");
    for (int i = 61; i <= 70; i++) printf("%s ", board[i]);
    printf("\n");
    for (int i = 60; i >= 51; i--) printf("%s ", board[i]);
    printf("\n");
    for (int i = 41; i <= 50; i++) printf("%s ", board[i]);
    printf("\n");
    for (int i = 40; i >= 31; i--) printf("%s ", board[i]);
    printf("\n");
    for (int i = 21; i <= 30; i++) printf("%s ", board[i]);
    printf("\n");
    for (int i = 20; i >= 11; i--) printf("%s ", board[i]);
    printf("\n");
    for (int i = 1; i <= 10; i++) printf("%s ", board[i]);
    printf("\n");
}
  

void save_game(player players[], int NumPlayers) {
    FILE *file = fopen("save_game.txt", "w");
    if (!file) return;
    fprintf(file, "%d\n", NumPlayers);
    for (int i = 0; i < NumPlayers; i++) {
        fprintf(file, "%s %d %d\n", players[i].name, players[i].position, players[i].moves);
    }
    fclose(file);
}

int load_game(player players[], int *NumPlayers) {
    FILE *file = fopen("save_game.txt", "r");
    if (!file) return 0;
    fscanf(file, "%d\n", NumPlayers);
    for (int i = 0; i < *NumPlayers; i++) {
        fscanf(file, "%s %d %d\n", players[i].name, &players[i].position, &players[i].moves);
    }
    fclose(file);
    return 1;
}

void log_results(player winner) {
    FILE *file = fopen("game_results.txt", "a");
    if (!file) return;
    fprintf(file, "Winner: %s, Moves: %d\n", winner.name, winner.moves);
    fclose(file);
}

void play_snakes_and_ladders() {
    int choose, NumPlayers;
    player players[4];
    int snake_start[8] = {99, 95, 89, 66, 54, 43, 40, 27};
    int snake_end[8] = {41, 77, 53, 45, 31, 18, 3, 5};
    int ladders_start[7] = {4, 13, 33, 42, 50, 62, 74};
    int ladders_end[7] = {25, 46, 49, 63, 69, 81, 92};
    int anotherturn = 0;
    

    srand(time(0));
    printf("Press 1 to read rules, 2 to load a saved game, or 3 to start a new game\n");
    scanf("%d", &choose);
    getchar();

    if(choose == 1){
           printf("Rules->\n");
        printf("\nInstructions:\n");
    printf("- Each player rolls the dice and moves forward by the rolled number.\n");
    printf("- If you land on the bottom of a ladder, you'll climb to the top.\n");
    printf("- If you land on a snake's head, you'll slide down to its tail.\n");
    printf("- The first player to reach square 100 wins the game.\n");
    printf("LETSSSS GOOOOOOOOOO!!!!!!!\n");

    choose = 3;
    }

    if (choose == 2 && !load_game(players, &NumPlayers)) {
        printf("No saved game found. Starting a new game.\n");
        choose = 3;
    }

    if (choose == 3) {
        printf("\nEnter number of players (1 to 4): ");
        scanf("%d", &NumPlayers);
        getchar();

         if(NumPlayers > 4){
            printf("ERRORRRRR ONLY FOUR OF YOU CAN PLAY SORRY, PLEASE CHOOSE BETWEEN 2 TO 4\n");
            return;
        }

        for (int i = 0; i < NumPlayers; i++) {
            printf("Enter name for player %d: ", i + 1);
            fgets(players[i].name, 20, stdin);
            players[i].name[strcspn(players[i].name, "\n")] = '\0';
            players[i].position = 1;
            players[i].moves = 0;

            printf("enter initial/symbol you want to display\n");
            scanf(" %c", &players[i].symbol);
            getchar();
        }
    }

    for(int i = 0; i<NumPlayers; i++){
     printf("Game Board:\n");
    printf("100  99  98  97  96  95  94  93  92  91\n");
    printf(" 81  82  83  84  85  86  87  88  89  90\n");
    printf(" 80  79  78  77  76  75  74  73  72  71\n");
    printf(" 61  62  63  64  65  66  67  68  69  70\n");
    printf(" 60  59  58  57  56  55  54  53  52  51\n");
    printf(" 41  42  43  44  45  46  47  48  49  50\n");
    printf(" 40  39  38  37  36  35  34  33  32  31\n");
    printf(" 21  22  23  24  25  26  27  28  29  30\n");
    printf(" 20  19  18  17  16  15  14  13  12  11\n");
    printf("  1   2   3   4   5   6   7   8   9  10\n");
    }

    while (1) {
        for (int i = 0; i < NumPlayers; i++) {
            printf("%s's turn, press enter to roll the dice or type 'save' to save the game\n", players[i].name);
            char input[10];
            fgets(input, 10, stdin);
            if (strncmp(input, "save", 4) == 0) {
                save_game(players, NumPlayers);
                printf("Game saved successfully!\n");
                return;
            }

            do{
            int roll = dice();
            printf("You rolled a %d\n", roll);
            if (roll == 6){
                anotherturn = 1;
            } else{
                anotherturn = 0;
            }
            if(players[i].position + roll > 100){
            printf("nahhhhh stop, you need %d to win, try again\n", 100 - players[i].position);
          }else {
            players[i].position += roll;
            players[i].moves++;
          }
       

            for (int j = 0; j < 8; j++) {
                if (players[i].position == snake_start[j]) {
                    players[i].position = snake_end[j];
                }
            }
            for (int j = 0; j < 7; j++) {
                if (players[i].position == ladders_start[j]) {
                    players[i].position = ladders_end[j];
                }
            }

           UpdatedBoard(players, NumPlayers);

            printf("%s is now at position %d\n", players[i].name, players[i].position);
            if (players[i].position == 100) {
                printf("Congratulations %s! You won the game in %d moves!\n", players[i].name, players[i].moves);
                log_results(players[i]);
                return;
            }
            if (anotherturn == 1){
                printf("YESSSS %s GOT A 6!!!!!, YOU GET ONE MORE CHANCE\n", players[i].name);
            }
            } while(anotherturn);
        }
    }
}