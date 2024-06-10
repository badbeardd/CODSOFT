#include <iostream>
#include <cstdlib>

using namespace std;

const int M = 3;
const int N = 3;
const char player1 = 'X';
const char player2 = 'O';
const char EMPTY = '_';

char win_condition(const char (&game_board)[M][N]) {
    // Check rows
    for (int i = 0; i < M; ++i) {
        if (game_board[i][0] == game_board[i][1] && game_board[i][1] == game_board[i][2] && game_board[i][0] != EMPTY) {
            return game_board[i][0];
        }
    }

    // Check columns
    for (int j = 0; j < N; ++j) {
        if (game_board[0][j] == game_board[1][j] && game_board[1][j] == game_board[2][j] && game_board[0][j] != EMPTY) {
            return game_board[0][j];
        }
    }

    // Check diagonals
    if (game_board[0][0] == game_board[1][1] && game_board[1][1] == game_board[2][2] && game_board[0][0] != EMPTY) {
        return game_board[0][0];
    }
    if (game_board[0][2] == game_board[1][1] && game_board[1][1] == game_board[2][0] && game_board[0][2] != EMPTY) {
        return game_board[0][2];
    }

    return '\0'; // No winner
}

void print_board(const char (&game_board)[M][N]) {
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << game_board[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    while (true) {
        char game_board[M][N];

        // Initializing each cell to EMPTY
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                game_board[i][j] = EMPTY;
            }
        }

        char input, winner = '\0', response;
        int row, col, countt = 0, turn = 1;

        while (true) {
            cout << "Game Board" << endl;
            print_board(game_board);

            cout << "Give the Player input and respective row and column: ";
            cin >> input >> row >> col;
            if ((input == player2 || input == player1) && row >= 0 && row < M && col >= 0 && col < N) {
                if (game_board[row][col] == EMPTY) {
                    if (turn == 1 && input == player1) {
                        game_board[row][col] = input;
                        turn = 0;
                    } else if (turn == 0 && input == player2) {
                        game_board[row][col] = input;
                        turn = 1;
                    }

                    countt++;
                    winner = win_condition(game_board);
                } else {
                    cout << "Cell is already occupied. Try again." << endl;
                }
            } else {
                cout << "Invalid input. Try again." << endl;
            }

            if (countt > 8 || winner != '\0') {
                break;
            }

            cout << string(50, '\n'); // Clear the screen
        }

        cout << "Game Board" << endl;
        print_board(game_board);

        if (winner != '\0') {
            if (winner == player1) {
                cout << "Player 1 wins!" << endl;
            } else {
                cout << "Player 2 wins!" << endl;
            }
        } else {
            cout << "Draw" << endl;
        }

        cout << "Play Again? Y or N: ";
        cin >> response;
        if (response == 'N' || response == 'n') {
            break;
        } else {
            cout << "Restarted" << endl;
        }
    }
    return 0;
}
