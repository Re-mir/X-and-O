#include <stdio.h>

#define SIZE 3

typedef char Board[SIZE][SIZE];

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
            printf("Число должно быть от 1 до %d! Попробуйте снова.\n", SIZE * SIZE);
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