#define BOARD_H
#define SIZE 3

typedef char Board[SIZE][SIZE];

void init_board(Board board);
void print_board(const Board board);

int check_game_over(const Board board, char player) {
    if (check_winner(board, player)) {
        printf("Победил игрок %c!\n", player);
        return 1;
    }
    

    if (is_board_full(board)) {
        printf("Игра закончилась ничьей!\n");
        return 2;
    }
    
    return 0;
}