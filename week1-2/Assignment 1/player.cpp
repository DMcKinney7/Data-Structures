
#include "player.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>

/**
 * @brief Reads player records from a file into a vector of Player structs.
 */
void readPlayers(const std::string& filename, std::vector<Player>& players) {
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Error opening file for reading: " << filename << std::endl;
        return;
    }

    Player tempPlayer;
    while (getline(inFile, tempPlayer.fullName)) {
        if ( (inFile >> tempPlayer.rating) &&
             (inFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n')) &&
             (getline(inFile, tempPlayer.team)) &&
             (inFile >> tempPlayer.jerseyNumber) &&
             (inFile >> tempPlayer.goalsScored) )
        {
            inFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            players.push_back(tempPlayer);
        } else {
            std::cerr << "Warning: Incomplete player record found. Stopping read." << std::endl;
            break;
        }
    }

    inFile.close();
}

/**
 * @brief Prints the player records from a vector in reverse order.
 */
void printPlayersReverse(const std::vector<Player>& players) {
    std::cout << std::fixed << std::setprecision(1);
    for (int i = players.size() - 1; i >= 0; --i) {
        std::cout << "Name     : " << players[i].fullName << std::endl;
        std::cout << "Rating   : " << players[i].rating << std::endl;
        std::cout << "Team     : " << players[i].team << std::endl;
        std::cout << "Number   : " << players[i].jerseyNumber << std::endl;
        std::cout << "Goals    : " << players[i].goalsScored << std::endl;
        std::cout << "-------------------------------------" << std::endl;
    }
}
