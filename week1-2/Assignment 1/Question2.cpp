#include <iostream>
#include <string>
#include <vector>
#include "player.h"
#include "player.cpp"

using namespace std;


int main() {
    const string filename = "fifa22db-1.txt";
    vector<Player> players;

    
    readPlayers(filename, players);

    if (!players.empty()) {
        printPlayersReverse(players);
    } else {
        cout << "No player records found or could not open file." << endl;
    }

    return 0;
}