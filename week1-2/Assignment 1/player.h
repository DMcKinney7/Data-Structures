
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

/**
 * @struct Player
 * @brief Holds all information for a single player.
 */
struct Player {
    std::string fullName;
    double rating;
    std::string team;
    int jerseyNumber;
    int goalsScored;
};

// Function prototypes

/**
 * @brief Reads player records from a file into a vector of Player structs.
 * @param filename The name of the file to read from.
 * @param players A reference to the vector to store the player data.
 */
void readPlayers(const std::string& filename, std::vector<Player>& players);

/**
 * @brief Prints the player records from a vector in reverse order.
 * @param players A constant reference to the vector of Player structs.
 */
void printPlayersReverse(const std::vector<Player>& players);

#endif // PLAYER_H
