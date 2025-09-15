#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <limits>

using namespace std;

/**
 * @struct Player
 * @brief Holds all information for a single player.
 */
struct Player {
    string fullName;
    double rating;
    string team;
    int jerseyNumber;
    int goalsScored;
};

// Function prototypes
void readPlayers(const string& filename, vector<Player>& players);
void printPlayersReverse(const vector<Player>& players);

/**
 * @brief Main function to drive the program.
 * It initializes a vector of players, reads data from a file,
 * and prints the data in reverse order.
 */
int main() {
    const string filename = "fifa22db-1.txt";
    vector<Player> players;

    // Read player records from the file into the vector.
    // The vector will automatically resize as needed.
    readPlayers(filename, players);

    if (!players.empty()) {
        // Print the player records in reverse order of how they were read.
        printPlayersReverse(players);
    } else {
        cout << "No player records found or could not open file." << endl;
    }

    return 0;
}

/**
 * @brief Reads player records from a file into a vector of Player structs.
 * It reads until the end of the file, handling an arbitrary number of records.
 * @param filename The name of the file to read from.
 * @param players A reference to the vector to store the player data.
 */
void readPlayers(const string& filename, vector<Player>& players) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error opening file for reading: " << filename << endl;
        return;
    }

    Player tempPlayer;
    // Loop continues as long as we can successfully read a player's name.
    // This robustly handles files with partial records at the end.
    while (getline(inFile, tempPlayer.fullName)) {
        // Attempt to read the rest of the player's data
        if ( (inFile >> tempPlayer.rating) &&
             (inFile.ignore(numeric_limits<streamsize>::max(), '\n')) &&
             (getline(inFile, tempPlayer.team)) &&
             (inFile >> tempPlayer.jerseyNumber) &&
             (inFile >> tempPlayer.goalsScored) )
        {
            inFile.ignore(numeric_limits<streamsize>::max(), '\n'); // Consume the rest of the line
            players.push_back(tempPlayer); // Add the fully-read player to the vector
        } else {
            // If a full record could not be read after reading a name, break the loop.
            // This prevents errors with malformed files.
            cerr << "Warning: Incomplete player record found. Stopping read." << endl;
            break;
        }
    }

    inFile.close();
}

/**
 * @brief Prints the player records from a vector in reverse order.
 * @param players A constant reference to the vector of Player structs.
 */
void printPlayersReverse(const vector<Player>& players) {
    cout << fixed << setprecision(1);
    // Iterate from the last element to the first
    for (int i = players.size() - 1; i >= 0; --i) {
        cout << "Name     : " << players[i].fullName << endl;
        cout << "Rating   : " << players[i].rating << endl;
        cout << "Team     : " << players[i].team << endl;
        cout << "Number   : " << players[i].jerseyNumber << endl;
        cout << "Goals    : " << players[i].goalsScored << endl;
        cout << "-------------------------------------" << endl;
    }
}