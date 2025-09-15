#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <limits>

using namespace std;


struct Player {
    string fullName;
    double rating;
    string team;
    int jerseyNumber;
    int goalsScored;
};


int getPlayerCount(const string& filename);
void readPlayers(const string& filename, Player* players, int count);
bool comparePlayers(const Player& a, const Player& b);
void sortPlayers(Player* players, int count);
void printPlayers(const Player* players, int count);

int main() {
    const string filename = "fifa22db-1.txt";
    int playerCount = 0;
    Player* players = nullptr;

    playerCount = getPlayerCount(filename);

    if (playerCount > 0) {
        players = new Player[playerCount];

        readPlayers(filename, players, playerCount);

        sortPlayers(players, playerCount);

        printPlayers(players, playerCount);

        delete[] players;
        players = nullptr;
    } else {
        cout << "No player records found or could not open file." << endl;
    }

    return 0;
}


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
    return lineCount / 5;
}


void readPlayers(const string& filename, Player* players, int count) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error opening file for reading: " << filename << endl;
        return;
    }

    for (int i = 0; i < count; ++i) {
        getline(inFile, players[i].fullName);
        inFile >> players[i].rating;
        inFile.ignore(numeric_limits<streamsize>::max(), '\n'); 
        getline(inFile, players[i].team);
        inFile >> players[i].jerseyNumber;
        inFile >> players[i].goalsScored;
        inFile.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    inFile.close();
}

bool comparePlayers(const Player& a, const Player& b) {
    return a.goalsScored > b.goalsScored;
}

void sortPlayers(Player* players, int count) {
    sort(players, players + count, comparePlayers);
}

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