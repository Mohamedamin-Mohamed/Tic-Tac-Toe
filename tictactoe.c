#include <stdio.h>
#include <stdlib.h>

//this function prints the updated characters in the board
void printBoard(char board [ ]);

// this function prints a prompt for player X or O
int getInput(char player);

//this function initializes the board
void initBoard();

//array to store the characters
char board[9];
const unsigned short BOARD_SIZE = 9;

int main() {
    initBoard();
    char currentPlayer = 'X';
    while (1) {
        //clearScreen();
        //pass the reference of the array to printBoard function
        printBoard(board);
        int index = getInput(currentPlayer);

        if (index == 9) {
            printf("Goodbye!\n");
            exit(0);
        }

        board[index] = currentPlayer;
        if (currentPlayer == 'X')
            currentPlayer = 'O';
        else
            currentPlayer = 'X';
}
}

// this function prints a Tic-Tac-Toe board
void printBoard(char board [ ]) {
    int j=0, f=3;
     printf("\n\n**************************\n\n");

     //loop to print the characters of the board
    for (int i = 0; i < 3; i++) {
    printf(" %c | %c | %c \n",board[j], board[j+1], board[j+2]);
    //loop for printing the dash lines
    if (f>=j) {
        printf("-----------\n");
    }
    j=j+3;
    }
}

int getInput(char player) {
    char sposition[3];
    printf("\n\n**************************\n");
    printf("%c's turn!\nWhere would you like to go?\nPlease enter 0 through 8, or press 9 to quit.\n>", player);
    fgets(sposition, 3, stdin);

    // convert the string to an int
    int position = atoi(sposition);
    return position;
}

void initBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i] = '0' + i;
    }
}
