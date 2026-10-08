#include "numberguess.h"
#include "scores.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void playNumberGuess(string playerName) {
    cout << "\n========================================\n";
    cout << "          NUMBER GUESSING GAME\n";
    cout << "========================================\n";
    cout << "1. Easy (1-50, 10 attempts)\n";
    cout << "2. Medium (1-100, 7 attempts)\n";
    cout << "3. Hard (1-200, 5 attempts)\n";
    cout << "Select difficulty (1-3): ";
    
    int diff;
    if (!(cin >> diff) || diff < 1 || diff > 3) {
        cin.clear();
        cin.ignore(10000, '\n');
        diff = 2;
    }

    int maxNumber = 100;
    int maxAttempts = 7;
    int scoreMultiplier = 20;
    
    if (diff == 1) {
        maxNumber = 50;
        maxAttempts = 10;
        scoreMultiplier = 10;
    } else if (diff == 3) {
        maxNumber = 200;
        maxAttempts = 5;
        scoreMultiplier = 30;
    }

    int secretNumber = (rand() % maxNumber) + 1;
    int attempts = 0;
    bool won = false;

    cout << "\nI have chosen a number between 1 and " << maxNumber << ".\n";
    
    while (attempts < maxAttempts) {
        cout << "Attempt " << (attempts + 1) << " of " << maxAttempts << ". Enter guess: ";
        int guess;
        if (!(cin >> guess)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input.\n";
            continue;
        }
        
        attempts++;
        
        if (guess == secretNumber) {
            cout << "Correct! You guessed it in " << attempts << " attempts.\n";
            won = true;
            break;
        } else if (guess < secretNumber) {
            cout << "Too low!\n";
        } else {
            cout << "Too high!\n";
        }
    }
    
    string result = "Loss";
    int finalScore = 0;
    
    if (won) {
        result = "Win";
        finalScore = (maxAttempts - attempts + 1) * scoreMultiplier;
    } else {
        cout << "Game over! The number was " << secretNumber << ".\n";
    }
    
    GameRecord record = {"Number Guess", playerName, finalScore, result};
    recordGame(record);
}
