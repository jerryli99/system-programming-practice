#include <stdio.h>

int evaluate_position(const char *board, int n) {
    int white_sum = 0, black_sum = 0;
    const char *p = NULL;

    for (p = board; p < board + n; p++) {
        switch(*p) {
            case 'Q':   white_sum += 9; 
                        break;
            case 'R':   white_sum += 5; 
                        break;
            case 'B':   
            case 'N':   white_sum += 3; 
                        break;
            case 'P':   white_sum += 1; 
                        break;
            case 'q':   black_sum += 9; 
                        break;
            case 'r':   black_sum += 5; 
                        break;
            case 'b':   
            case 'n':   black_sum += 3; 
                        break;
            case 'p':   black_sum += 1; 
                        break;
            default:
                break;
        }
    }
    return (white_sum - black_sum);
}

int main() {
    char chess_board[8][8] = {{'R', '.', 'B', 'Q', 'K', 'B', 'N', 'R'},
                              {'P', 'P', 'P', '.', '.', '.', 'P', 'P'},
                              {'.', '.', '.', '.', '.', '.', '.', '.'},
                              {'.', '.', '.', '.', '.', '.', '.', '.'},
                              {'.', '.', 'p', '.', '.', '.', '.', '.'},
                              {'.', '.', '.', '.', '.', '.', '.', '.'},
                              {'p', 'p', '.', 'p', 'p', 'p', 'p', 'p'},
                              {'r', 'n', '.', '.', 'k', 'b', 'n', 'r'}};


    printf("Evaluate positions: %d\n", evaluate_position(chess_board[0], 8*8));
    return 0;
}