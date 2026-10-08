#include "tictactoe.h"
#include "scores.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

char board[3][3];

void initBoard() {
    char start = '1';
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = start++;
        }
    }
}

void printBoard() {
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

bool checkWin(char mark) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == mark && board[i][1] == mark && board[i][2] == mark) return true;
        if (board[0][i] == mark && board[1][i] == mark && board[2][i] == mark) return true;
    }
    if (board[0][0] == mark && board[1][1] == mark && board[2][2] == mark) return true;
    if (board[0][2] == mark && board[1][1] == mark && board[2][0] == mark) return true;
    return false;
}

bool isDraw() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] != 'X' && board[i][j] != 'O') return false;
        }
    }
    return true;
}

void playTicTacToe(string playerName) {
    cout << "\n========================================\n";
    cout << "              TIC-TAC-TOE\n";
    cout << "========================================\n";
    cout << "1. Player vs Player\n";
    cout << "2. Player vs Computer\n";
    cout << "Choose mode (1-2): ";
    
    int mode;
    if (!(cin >> mode) || (mode != 1 && mode != 2)) {
        cin.clear();
        cin.ignore(10000, '\n');
        mode = 2;
    }

    initBoard();
    int turn = 0;
    bool gameOver = false;
    string result;
    int score = 0;

    while (!gameOver) {
        printBoard();
        
        if (turn % 2 == 0) {
            cout << playerName << "'s turn (X). Enter cell (1-9): ";
            int choice;
            cin >> choice;
            int row = (choice - 1) / 3;
            int col = (choice - 1) % 3;
            
            if (choice >= 1 && choice <= 9 && board[row][col] != 'X' && board[row][col] != 'O') {
                board[row][col] = 'X';
                if (checkWin('X')) {
                    printBoard();
                    cout << playerName << " wins!\n";
                    result = "Win";
                    score = 50;
                    gameOver = true;
                } else if (isDraw()) {
                    printBoard();
                    cout << "It's a draw!\n";
                    result = "Draw";
                    score = 10;
                    gameOver = true;
                }
                turn++;
            } else {
                cout << "Invalid move.\n";
            }
        } else {
            if (mode == 1) {
                cout << "Player 2's turn (O). Enter cell (1-9): ";
                int choice;
                cin >> choice;
                int row = (choice - 1) / 3;
                int col = (choice - 1) % 3;
                
                if (choice >= 1 && choice <= 9 && board[row][col] != 'X' && board[row][col] != 'O') {
                    board[row][col] = 'O';
                    if (checkWin('O')) {
                        printBoard();
                        cout << "Player 2 wins!\n";
                        result = "Loss";
                        score = 0;
                        gameOver = true;
                    } else if (isDraw()) {
                        printBoard();
                        cout << "It's a draw!\n";
                        result = "Draw";
                        score = 10;
                        gameOver = true;
                    }
                    turn++;
                } else {
                    cout << "Invalid move.\n";
                }
            } else {
                cout << "Computer's turn (O)...\n";
                bool moved = false;
                while (!moved) {
                    int choice = (rand() % 9) + 1;
                    int row = (choice - 1) / 3;
                    int col = (choice - 1) % 3;
                    if (board[row][col] != 'X' && board[row][col] != 'O') {
                        board[row][col] = 'O';
                        moved = true;
                    }
                }
                
                if (checkWin('O')) {
                    printBoard();
                    cout << "Computer wins!\n";
                    result = "Loss";
                    score = 0;
                    gameOver = true;
                } else if (isDraw()) {
                    printBoard();
                    cout << "It's a draw!\n";
                    result = "Draw";
                    score = 10;
                    gameOver = true;
                }
                turn++;
            }
        }
    }

    GameRecord record = {"Tic-Tac-Toe", playerName, score, result};
    recordGame(record);
}
