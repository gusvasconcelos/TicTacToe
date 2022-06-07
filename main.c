#include <stdio.h>

int turn;

void reset(int board[][3]);
void display(int board[][3]);
void play(int board[][3]);
int checkAvailable(int board[][3], int line, int column);
int checkLine(int board[][3]);
int checkColumn(int board[][3]);
int checkDiagonal(int board[][3]);
int checkEmpate(int board[][3]);
int checkEnd(int board[][3], int turn);
void move(int board[][3]);

int main() {

    int board[3][3],
    continuePlay;

    do {
        turn = 1;
        continuePlay = menu();

        if (continuePlay == 1)
            play(board);
    } while (continuePlay);

    reset(board);
    display(board);

    return 0;
}

int menu() {
    int inputUser;

    printf("\t\tTicTacToe by Gustavo Vasconcelos.\n\n");
    printf("1 - to Play.\n");
    printf("0- to Leave.\n");
    printf(">>> ");
    scanf("%d", &inputUser);

    switch (inputUser) {
        case 1:
        case 0:
            break;
        default:
            system("cls" || "clear");
            printf("Option invalidates. Try again!\n");
    }

    return inputUser;
}

void reset(int board[][3]) {
    for (int i=0; i < 3; i++) {
        for (int j=0; j < 3; j++) {
            board[i][j] = 0;
        }
    }
}

void display(int board[][3]) {
    for (int i=0; i < 3; i++) {
        printf("\n");
        for (int j=0; j < 3; j++) {
            if (board[i][j] == 1)
                printf(" X ");
            else if(board[i][j] == -1)
                printf(" O ");
            else
                printf("   ");

            if (j != 2)
                printf("|");
        }
        if (i >= 0 && i < 2) {
            printf("\n");
            printf("-----------");
        }
    }
    printf("\n");
}

void play(int board[][3]) {
    int continuePlay;
    reset(board);

    do {
        system("cls" || "clear");
        display(board);
        move(board);
    } while (checkEnd(board, turn) != 1);
}

int checkAvailable(int board[][3], int line, int column) {
    if(line < 0 || line > 2 || column < 0 || column > 2 || board[line][column] != 0)
        return 0;
    else
        return 1;
}

int checkLine(int board[][3]) {
    for (int i=0; i < 3; i++) {
        int soma = 0;
        for (int j=0; j < 3; j++) {
            soma += board[i][j];
            if (soma == -3 || soma == 3)
                return 1;
        }
    }
    return 0;
}

int checkColumn(int board[][3]) {
    for (int j=0; j < 3; j++) {
        int soma = 0;
        for (int i=0; i < 3; i++) {
            soma += board[i][j];
            if (soma == -3 || soma == 3)
                return 1;
        }
    }
    return 0;
}

int checkDiagonal(int board[][3]) {
    int mainDiagonal = 0,
    secundaryDiagonal = 0, 
    contador = 3;
    for (int i=0; i < 3; i++) {
        mainDiagonal += board[i][i];
        secundaryDiagonal += board[i][--contador];
    }

    if (mainDiagonal == 3 || mainDiagonal == -3 ||
    secundaryDiagonal == 3 || secundaryDiagonal == -3)
        return 1;
    
    return 0;
}

int checkTie(int board[][3]) {
    for (int i=0; i < 3; i++) {
        for (int j=0; j < 3; j++) {
            if (board[i][j] == 0)
                return 0;
        }
    }
    return 1;
}

int checkEnd(int board[][3], int turn) {
    if (checkLine(board)) {
        printf("\n\nEnd of game. Player %d won!!!\n\n", (turn % 2) + 1);
        display(board);
        return 1;
    }
    if (checkColumn(board)) {
        printf("\n\nEnd of game. Player %d won!!!\n\n", (turn % 2) + 1);
        display(board);
        return 1;
    }
    if (checkDiagonal(board)) {
        printf("\n\nEnd of game. Player %d won!!!\n\n", (turn % 2) + 1);
        display(board);
        return 1;
    }
    if (checkTie(board)) {
        printf("\n\nEnd of game. The game was tied.\n\n");;
        display(board);
        return 1;
    }
}

void move(int board[][3]) {
    int line, column;
    turn++;

    printf("\nPlayer %d\n", (turn % 2) + 1);

    do {
        printf("Line: ");
        scanf("%d", &line);
        line--;
 
        printf("Column: ");
        scanf("%d", &column);
        column--;

        if (checkAvailable(board, line, column) == 0)
            printf("This position is already occupied.\n");

    } while (checkAvailable(board, line, column) == 0);

    if(turn % 2)
        board[line][column] = -1;
    else
        board[line][column] = 1;
}
