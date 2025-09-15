#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <limits>

using namespace std;

// Struct to hold player information
struct Player {
    string fullName;
    double rating;
    string team;
    int jerseyNumber;
    int goalsScored;
};

// Function prototypes
int getPlayerCount(const string& filename);
void readPlayers(const string& filename, Player* players, int count);
bool comparePlayers(const Player& a, const Player& b);
void sortPlayers(Player* players, int count);
void printPlayers(const Player* players, int count);

int main() {
    const string filename = "fifa22db-1.txt";
    int playerCount = 0;
    Player* players = nullptr;

    // Get the number of players from the file
    playerCount = getPlayerCount(filename);

    if (playerCount > 0) {
        // Dynamically allocate an array of Player structs
        players = new Player[playerCount];

        // Read player records from the file
        readPlayers(filename, players, playerCount);

        // Sort the players by goals scored in descending order
        sortPlayers(players, playerCount);

        // Print the sorted player records
        printPlayers(players, playerCount);

        // Deallocate the dynamic array
        delete[] players;
        players = nullptr;
    } else {
        cout << "No player records found or could not open file." << endl;
    }

    return 0;
}

/**
 * @brief Counts the number of player records in the file.
 * Each record is 5 lines long.
 * @param filename The name of the file to read.
 * @return The number of players.
 */
int getPlayerCount(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error opening file: " << filename << endl;
        return 0;
    }

    int lineCount = 0;
    string line;
    while (getline(inFile, line)) {
        lineCount++;
    }

    inFile.close();
    return lineCount / 5; // Each player has 5 lines of data
}

/**
 * @brief Reads player records from the file into the dynamic array.
 * @param filename The name of the file.
 * @param players Pointer to the array of Player structs.
 * @param count The number of players to read.
 */
void readPlayers(const string& filename, Player* players, int count) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error opening file for reading: " << filename << endl;
        return;
    }

    for (int i = 0; i < count; ++i) {
        getline(inFile, players[i].fullName);
        inFile >> players[i].rating;
        inFile.ignore(numeric_limits<streamsize>::max(), '\n'); // Consume the rest of the line
        getline(inFile, players[i].team);
        inFile >> players[i].jerseyNumber;
        inFile >> players[i].goalsScored;
        inFile.ignore(numeric_limits<streamsize>::max(), '\n'); // Consume the rest of the line
    }

    inFile.close();
}

/**
 * @brief Comparison function for sorting players by goals in descending order.
 * @param a First player.
 * @param b Second player.
 * @return true if player a has more goals than player b.
 */
bool comparePlayers(const Player& a, const Player& b) {
    return a.goalsScored > b.goalsScored;
}

/**
 * @brief Sorts the array of players.
 * @param players Pointer to the array of Player structs.
 * @param count The number of players in the array.
 */
void sortPlayers(Player* players, int count) {
    sort(players, players + count, comparePlayers);
}

/**
 * @brief Prints the player records in a formatted way.
 * @param players Pointer to the array of Player structs.
 * @param count The number of players in the array.
 */
void printPlayers(const Player* players, int count) {
    cout << fixed << setprecision(1);
    for (int i = 0; i < count; ++i) {
        cout << "Name     : " << players[i].fullName << endl;
        cout << "Rating   : " << players[i].rating << endl;
        cout << "Team     : " << players[i].team << endl;
        cout << "Number   : " << players[i].jerseyNumber << endl;
        cout << "Goals    : " << players[i].goalsScored << endl;
        cout << "-------------------------------------" << endl;
    }
}