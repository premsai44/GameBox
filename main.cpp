#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "main.h"
#include "rps.h"
#include "tictactoe.h"
#include "numberguess.h"
#include "hangman.h"
#include "scores.h"

using namespace std;

void displayMenu() {
    cout << "\n========================================\n";
    cout << "                GAMEBOX\n";
    cout << "          C++ MINI-GAME COLLECTION\n";
    cout << "========================================\n";
    cout << "1. Rock Paper Scissors\n";
    cout << "2. Tic-Tac-Toe (XO)\n";
    cout << "3. Number Guessing Game\n";
    cout << "4. Hangman\n";
    cout << "5. View Leaderboard\n";
    cout << "6. View Game History\n";
    cout << "7. Exit\n";
    cout << "\nEnter your choice: ";
}

int main() {
    srand(time(0));
    int choice;
    string playerName;

    cout << "Welcome to GameBox! Enter your player name: ";
    cin >> playerName;

    do {
        displayMenu();
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            choice = 0;
        }

        switch (choice) {
            case 1:
                playRockPaperScissors(playerName);
                break;
            case 2:
                playTicTacToe(playerName);
                break;
            case 3:
                playNumberGuess(playerName);
                break;
            case 4:
                playHangman(playerName);
                break;
            case 5:
                viewLeaderboard();
                break;
            case 6:
                viewGameHistory();
                break;
            case 7:
                cout << "Thanks for playing GameBox, " << playerName << "!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}
