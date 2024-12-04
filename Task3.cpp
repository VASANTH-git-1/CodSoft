#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to display the Tic-Tac-Toe board
void displayBoard(const vector<vector<char>>& board) {
    cout << "\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << " " << board[i][j] << " ";
            if (j < 2) cout << "|";
        }
        cout << "\n";
        if (i < 2) cout << "---|---|---\n";
    }
    cout << "\n";
}

// Function to check if the current player has won
bool checkWin(const vector<vector<char>>& board, char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) || 
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) || 
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

// Function to check if the game is a draw
bool checkDraw(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

// Function to switch the player
char switchPlayer(char currentPlayer) {
    return (currentPlayer == 'X') ? 'O' : 'X';
}

// Main function
int main() {
    while (true) {
        // Initialize the game board
        vector<vector<char>> board(3, vector<char>(3, ' '));
        char currentPlayer = 'X';
        bool gameOver = false;

        cout << "Welcome to Tic-Tac-Toe!\n";
        displayBoard(board);

        // Game loop
        while (!gameOver) {
            int row, col;
            cout << "Player " << currentPlayer << ", enter your move (row and column: 1-3): ";
            cin >> row >> col;

            // Adjust for 0-based indexing
            row--;
            col--;

            // Validate the move
            if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
                cout << "Invalid move. Try again.\n";
                continue;
            }

            // Update the board
            board[row][col] = currentPlayer;
            displayBoard(board);

            // Check for win
            if (checkWin(board, currentPlayer)) {
                cout << "Player " << currentPlayer << " wins!\n";
                gameOver = true;
            }
            // Check for draw
            else if (checkDraw(board)) {
                cout << "It's a draw!\n";
                gameOver = true;
            }
            // Switch players
            else {
                currentPlayer = switchPlayer(currentPlayer);
            }
        }

        // Ask to play again
        char playAgain;
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
        if (playAgain != 'y' && playAgain != 'Y') {
            cout << "Thanks for playing Tic-Tac-Toe! Goodbye!\n";
            break;
        }
    }

    return 0;
}

