#ifndef MODELS_H
#define MODELS_H
#include <string>

struct GameRecord {
    std::string gameName;
    std::string playerName;
    int score;
    std::string result;
};

struct Player {
    std::string name;
    int totalScore;
};

#endif
