#include <stdio.h>
#define SIZE 3

typedef char Board[SIZE][SIZE];

int play_game(void) {
    Board board;
    char current_player = 'X';
    
    init_board(board);
    
    while (1) {
        print_board(board);
        printf("Ход игрока %c\n", current_player);
        
        int move = get_player_move(board);
        int row = (move - 1) / SIZE;
        int col = (move - 1) % SIZE;
        
        board[row][col] = current_player;
        
        if (check_winner(board, current_player)) {
            print_board(board);
            printf("Победил игрок %c!\n", current_player);
            return 1;
        }
        
        if (is_board_full(board)) {
            print_board(board);
            printf("Игра закончилась ничьей!\n");
            return 1;
        }
        
        current_player = (current_player == 'X') ? 'O' : 'X';
    }
}

int main() {
    char answer;
    
    printf("Добро пожаловать в крестики-нолики!\n");
    
    do {
        play_game();
        
        // Спрашиваем, хотят ли сыграть ещё раз
        printf("\nХотите сыграть ещё раз? (y/n): ");
        while (getchar() != '\n');  // Очищаем буфер перед вводом символа
        scanf("%c", &answer);
        
    } while (answer == 'y' || answer == 'Y' || answer == 'd' || answer == 'D');
    
    printf("Спасибо за игру! До встречи!\n");
    return 0;
}
