#define BOARD_H

#define SIZE 3

typedef char Board[SIZE][SIZE];

void init_board(Board board);
void print_board(const Board board);

int check_winner(const Board board, char player) {
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }
    
    for (int j = 0; j < SIZE; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return 1;  // Победа по вертикали
        }
    }
    
    // Проверка диагоналей
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }
    
    return 0; 
}
