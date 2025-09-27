
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

struct Player {
    std::string fullName;
    double rating;
    std::string team;
    int jerseyNumber;
    int goalsScored;
};

void readPlayers(const std::string& filename, std::vector<Player>& players);

void printPlayersReverse(const std::vector<Player>& players);

#endif // PLAYER_H
