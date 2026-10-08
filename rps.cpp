#include "rps.h"
#include "scores.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

void playRockPaperScissors(string playerName) {
    cout << "\n========================================\n";
    cout << "          ROCK PAPER SCISSORS\n";
    cout << "             (Best of 5)\n";
    cout << "========================================\n";
    
    int playerWins = 0;
    int computerWins = 0;
    int roundsPlayed = 0;
    
    string choices[] = {"Rock", "Paper", "Scissors"};

    while (playerWins < 3 && computerWins < 3 && roundsPlayed < 5) {
        cout << "\n--- Round " << (roundsPlayed + 1) << " ---\n";
        cout << "Score -> " << playerName << ": " << playerWins << " | Computer: " << computerWins << "\n";
        cout << "1. Rock\n2. Paper\n3. Scissors\n";
        cout << "Enter your choice (1-3): ";
        
        int playerChoice;
        if (!(cin >> playerChoice) || playerChoice < 1 || playerChoice > 3) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input.\n";
            continue;
        }
        
        int computerChoice = (rand() % 3) + 1;
        
        cout << "\nYou chose: " << choices[playerChoice - 1] << "\n";
        cout << "Computer chose: " << choices[computerChoice - 1] << "\n";
        
        if (playerChoice == computerChoice) {
            cout << "=> It's a tie!\n";
        } else if ((playerChoice == 1 && computerChoice == 3) || 
                   (playerChoice == 2 && computerChoice == 1) || 
                   (playerChoice == 3 && computerChoice == 2)) {
            cout << "=> You win this round!\n";
            playerWins++;
        } else {
            cout << "=> Computer wins this round!\n";
            computerWins++;
        }
        roundsPlayed++;
    }
    
    cout << "\n========================================\n";
    cout << "              FINAL SCORE\n";
    cout << playerName << ": " << playerWins << " | Computer: " << computerWins << "\n";
    
    string result;
    int finalScore = playerWins * 10;
    
    if (playerWins > computerWins) {
        cout << "Congratulations, " << playerName << "! You won the match!\n";
        result = "Win";
    } else if (computerWins > playerWins) {
        cout << "Computer wins the match.\n";
        result = "Loss";
    } else {
        cout << "The match ended in a tie!\n";
        result = "Draw";
    }
    cout << "========================================\n";
    
    GameRecord record = {"Rock Paper Scissors", playerName, finalScore, result};
    recordGame(record);
}
