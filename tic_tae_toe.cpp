#include<bits/stdc++.h>
using namespace std;
const int SIZE = 3;

void printBoard(char board[SIZE][SIZE]) {
    cout << endl;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << board[i][j];
            if (j < SIZE - 1) cout << " | ";
        }
        cout << endl;
        if (i < SIZE - 1) cout << "-----------" << endl;
    }
    cout << endl;
}

bool checkWin(char board[SIZE][SIZE], char player) {
    for (int i = 0; i < SIZE; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

bool isFull(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == ' ') return false;
        }
    }
    return true;
}

void playerMove(char board[SIZE][SIZE], char player) {
    int move;
    while (true) {
        cout << "Player " << player << ", enter your move (1-9): ";
        cin >> move;
        move--;  // Convert to 0-based index
        int row = move / SIZE;
        int col = move % SIZE;

        if (move >= 0 && move < 9 && board[row][col] == ' ') {
            board[row][col] = player;
            break;
        } else {
            cout << "Invalid move.Please Try again.\n";
        }
    }
}

void aiMove(char board[SIZE][SIZE], char player) {
    srand(time(0));  // Initialize random seed
    int move;
    while (true) {
        move = rand() % 9;
        int row = move / SIZE;
        int col = move % SIZE;

        if (board[row][col] == ' ') {
            board[row][col] = player;
            cout << "AI plays at position : " << move + 1 << ".\n";
            break;
        }
    }
}

void playGame2Players() {
    char board[SIZE][SIZE] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    char currentPlayer = 'X';

    while (true) {
        printBoard(board);
        playerMove(board, currentPlayer);

        if (checkWin(board, currentPlayer)) {
            printBoard(board);
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }

        if (isFull(board)) {
            printBoard(board);
            cout << "It's a draw!\n";
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';  // Switch player
    }
}

void playGame1Player() {
    char board[SIZE][SIZE] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    char player = 'X';
    char ai = 'O';

    while (true) {
        printBoard(board);
        playerMove(board, player);

        if (checkWin(board, player)) {
            printBoard(board);
            cout << "You " << player << " wins!\n";
            cout<<" Congratulations !!";
            break;
        }

        if (isFull(board)) {
            printBoard(board);
            cout << " It's a draw!\n";
            break;
        }

        aiMove(board, ai);

        if (checkWin(board, ai)) {
            printBoard(board);
            cout << "AI wins!\n";
            cout<<"You Lose Try again !!";
            break;
        }

        if (isFull(board)) {
            printBoard(board);
            cout << "It's a draw!\n";
            break;
        }
    }
}

int main() {
    int choice;

    cout << "Welcome to Tic-Tac-Toe!\n";
    cout << "Select Game Mode:\n";
    cout << "1. Player vs Player\n";
    cout << "2. Player vs AI\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        playGame2Players();
    } else if (choice == 2) {
        cout<<"Please Enter: X";
        playGame1Player();
    } else {
        cout << "Invalid choice. Exiting...\n";
    }

    return 0;
} 
