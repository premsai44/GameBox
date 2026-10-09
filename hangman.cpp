#include "hangman.h"
#include "scores.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;

void playHangman(string playerName) {
    cout << "\n========================================\n";
    cout << "                HANGMAN\n";
    cout << "========================================\n";

    string words[] = {"PROGRAMMING", "ALGORITHM", "VARIABLE", "POINTER", "FUNCTION", "STRUCTURE", "CLASS", "ARRAY", "DEVELOPER", "COMPILER"};
    int numWords = 10;

    string secretWord = words[rand() % numWords];
    string guessedWord = "";
    for (size_t i = 0; i < secretWord.length(); ++i) {
        guessedWord += "_";
    }

    int maxAttempts = 6;
    int wrongAttempts = 0;
    string guessedLetters = "";
    bool won = false;

    while (wrongAttempts < maxAttempts && !won) {
        cout << "\nWord: ";
        for (size_t i = 0; i < guessedWord.length(); ++i) {
            cout << guessedWord[i] << " ";
        }
        cout << "\nGuesses remaining: " << (maxAttempts - wrongAttempts) << "\n";
        
        if (!guessedLetters.empty()) {
            cout << "Guessed letters: ";
            for (size_t i = 0; i < guessedLetters.length(); ++i) {
                cout << guessedLetters[i] << " ";
            }
            cout << "\n";
        }

        cout << "Enter a letter: ";
        char guess;
        cin >> guess;
        guess = toupper(guess);

        bool alreadyGuessed = false;
        for (size_t i = 0; i < guessedLetters.length(); ++i) {
            if (guessedLetters[i] == guess) {
                alreadyGuessed = true;
                break;
            }
        }

        if (alreadyGuessed) {
            cout << "You already guessed that letter!\n";
            continue;
        }

        guessedLetters += guess;

        bool found = false;
        for (size_t i = 0; i < secretWord.length(); ++i) {
            if (secretWord[i] == guess) {
                guessedWord[i] = guess;
                found = true;
            }
        }

        if (!found) {
            cout << "Incorrect!\n";
            wrongAttempts++;
        } else {
            cout << "Correct!\n";
        }

        if (guessedWord == secretWord) {
            won = true;
        }
    }

    cout << "\n========================================\n";
    string result;
    int score = 0;

    if (won) {
        cout << "You won! The word was: " << secretWord << "\n";
        result = "Win";
        score = 50 + ((maxAttempts - wrongAttempts) * 10);
    } else {
        cout << "Game Over! The word was: " << secretWord << "\n";
        result = "Loss";
        score = 0;
    }

    GameRecord record = {"Hangman", playerName, score, result};
    recordGame(record);
}
