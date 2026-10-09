#include "scramble.h"
#include "scores.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;

void playScramble(string playerName) {
    cout << "\n========================================\n";
    cout << "              WORD SCRAMBLE\n";
    cout << "========================================\n";

    string words[] = {"NETWORK", "SYSTEM", "INTEGER", "BOOLEAN", "OBJECT", "MEMORY", "DEBUG", "SYNTAX"};
    int numWords = 8;

    string secretWord = words[rand() % numWords];
    string scrambledWord = secretWord;
    
    for (size_t i = 0; i < scrambledWord.length(); ++i) {
        int swapIdx = rand() % scrambledWord.length();
        char temp = scrambledWord[i];
        scrambledWord[i] = scrambledWord[swapIdx];
        scrambledWord[swapIdx] = temp;
    }

    if (scrambledWord == secretWord && secretWord.length() > 1) {
        char temp = scrambledWord[0];
        scrambledWord[0] = scrambledWord[1];
        scrambledWord[1] = temp;
    }

    cout << "Unscramble this programming word: " << scrambledWord << "\n";
    
    int maxAttempts = 3;
    int attempts = 0;
    bool won = false;
    
    while (attempts < maxAttempts && !won) {
        cout << "Attempt " << (attempts + 1) << " of " << maxAttempts << ". Your guess: ";
        string guess;
        cin >> guess;
        
        for (size_t i = 0; i < guess.length(); ++i) {
            guess[i] = toupper(guess[i]);
        }
        
        if (guess == secretWord) {
            cout << "Correct! You unscrambled the word.\n";
            won = true;
        } else {
            attempts++;
            if (attempts < maxAttempts) {
                cout << "Incorrect! Try again.\n";
            }
        }
    }

    string result;
    int score = 0;

    if (won) {
        result = "Win";
        score = 40 - (attempts * 10);
    } else {
        cout << "\nGame Over! The word was: " << secretWord << "\n";
        result = "Loss";
        score = 0;
    }

    GameRecord record = {"Word Scramble", playerName, score, result};
    recordGame(record);
}
