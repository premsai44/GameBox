#include "scores.h"
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<GameRecord> gameHistory;

void recordGame(const GameRecord& record) {
    gameHistory.push_back(record);
}

void viewLeaderboard() {
    cout << "\n--- Leaderboard ---\n";
    if (gameHistory.empty()) {
        cout << "No games played yet.\n";
        return;
    }

    map<string, int> playerScores;
    for (size_t i = 0; i < gameHistory.size(); ++i) {
        playerScores[gameHistory[i].playerName] += gameHistory[i].score;
    }

    vector<pair<string, int>> sortedScores(playerScores.begin(), playerScores.end());
    for (size_t i = 0; i < sortedScores.size() - 1; ++i) {
        for (size_t j = 0; j < sortedScores.size() - i - 1; ++j) {
            if (sortedScores[j].second < sortedScores[j + 1].second) {
                swap(sortedScores[j], sortedScores[j + 1]);
            }
        }
    }

    for (size_t i = 0; i < sortedScores.size(); ++i) {
        cout << i + 1 << ". " << sortedScores[i].first << " - " << sortedScores[i].second << " points\n";
    }
}

void viewGameHistory() {
    cout << "\n--- Game History ---\n";
    if (gameHistory.empty()) {
        cout << "No games have been played yet.\n";
        return;
    }
    
    for (size_t i = 0; i < gameHistory.size(); ++i) {
        cout << i + 1 << ". " << gameHistory[i].playerName 
             << " played " << gameHistory[i].gameName 
             << " | Result: " << gameHistory[i].result 
             << " | Score: " << gameHistory[i].score << "\n";
    }
}
