#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

typedef char Board[SIZE][SIZE];

char get_current_player(char current_player) {
    return (current_player == 'X') ? 'O' : 'X';
}

int can_make_move(const Board board, int row, int col) {
    return board[row][col] == ' ';
}

int main() {
    Board board;
    char current_player = 'X'; 
    int row, col;
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
    
    printf("Начинает игрок X\n");
    
    while (1) {
        printf("Ход игрока %c\n", current_player);
        
        int move = get_player_move(board);
        row = (move - 1) / SIZE;
        col = (move - 1) % SIZE;
        
        if (!can_make_move(board, row, col)) {
            printf("Неверный ход! Клетка уже занята\n");
            continue;
        }
        
        board[row][col] = current_player;
        print_board(board); 
        current_player = get_current_player(current_player);
    }
    
    return 0;
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