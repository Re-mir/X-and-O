#include <stdio.h>  
#include <stdlib.h>
#define SIZE 3  

typedef char Board[SIZE][SIZE];

void init_board(Board board) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

void print_board(const Board board) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) printf("-----------\n");
    }
    printf("\n");
}


int get_player_move(const Board board) {
    int move;
    while (1) {

        printf("Введите номер клетки (1-%d): ", SIZE * SIZE);

        if (scanf("%d", &move) != 1) {
            printf("Ошибка! Введите число.\n");
            while (getchar() != '\n');
            continue;
        }

        if (move < 1 || move > SIZE * SIZE) {
            printf("Число должно быть от 1 до %d!\n", SIZE * SIZE);
            continue;
        }
        
        int row = (move - 1) / SIZE;
        int col = (move - 1) % SIZE;
        
        if (board[row][col] != ' ') {
            printf("Клетка уже занята! Выберите другую.\n");
            continue;
        }
        
        return move;
    }
}