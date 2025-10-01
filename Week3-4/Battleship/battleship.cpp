#include "battleship.h"
#include <iostream>
#include <ctime>
#include <string>
using namespace std;

//this is a friend function to Location class.
bool compare(const Location& loc1, const Location& loc2) {
    return (loc1 == loc2);
    /*nitoce that == operator is overloaded for the Location class*/

}

//overloding the << operator to teach the compiler how to print a ship info using cout
ostream& operator<<(ostream& os, const Ship& sh)
{
    string status;
    if (!sh.sunk)
        status = " up ";
    else
        status = " sunk ";
    sh.loc.print();

    os << "->" << status;
    return os;
}

//--------Location implementation-----------------------------------------------------------------------//

Location::Location() {
    coordinates = new int[2];
    coordinates[0] = -1;
    coordinates[1] = -1;
}

Location::Location(int x, int y) {
    coordinates = new int[2];
    coordinates[0] = x;
    coordinates[1] = y;
}

Location::Location(const Location& other) {
    coordinates = new int[2];
    coordinates[0] = other.coordinates[0];
    coordinates[1] = other.coordinates[1];
}

Location& Location::operator=(const Location& other) {
    if (this != &other) {
        coordinates[0] = other.coordinates[0];
        coordinates[1] = other.coordinates[1];
    }
    return *this;
}

Location::~Location() {
    delete[] coordinates;
}

void Location::pick() {
    coordinates[0] = rand() % FIELD_SIZE + 1;
    coordinates[1] = rand() % FIELD_SIZE + 1;
}

void Location::fire() {
    int x, y;
    do {
        cout << "Enter x coordinate (1-6): ";
        cin >> x;
        cout << "Enter y coordinate (1-6): ";
        cin >> y;
        if (x < 1 || x > FIELD_SIZE || y < 1 || y > FIELD_SIZE)
            cout << "Invalid coordinates. Try again.\n";
    } while (x < 1 || x > FIELD_SIZE || y < 1 || y > FIELD_SIZE);
    coordinates[0] = x;
    coordinates[1] = y;
}

void Location::print() const {
    cout << "[" << coordinates[0] << "," << coordinates[1] << "]";
}

int Location::getCoordX() {
    return coordinates[0];
}

int Location::getCoordY() {
    return coordinates[1];
}

//--------Ship implementation------------------------------------------------//

Ship::Ship() : loc(-1, -1), sunk(false) {}

bool Ship::match(const Location& otherLocation) const {
    return compare(loc, otherLocation);
}

bool Ship::isSunk() const {
    return sunk;
}

void Ship::sink() {
    sunk = true;
}

void Ship::setLocation(const Location& currentLoc) {
    loc = currentLoc;
}

Location Ship::getLocation() {
    return loc;
}

//--------Fleet implementation ------------------//

Fleet::Fleet() {
    // Ships are default constructed, so loc = (-1,-1) and sunk = false
}

int Fleet::check(const Location& loc) const {
    for (int i = 0; i < FLEET_SIZE; ++i) {
        if (ships[i].match(loc))
            return i;
    }
    return -1;
}

void Fleet::deployFleet() {
    srand(static_cast<unsigned>(time(0)));
    for (int i = 0; i < FLEET_SIZE; ++i) {
        Location tempLoc;
        bool unique;
        do {
            tempLoc.pick();
            unique = true;
            for (int j = 0; j < i; ++j) {
                if (ships[j].match(tempLoc)) {
                    unique = false;
                    break;
                }
            }
        } while (!unique);
        ships[i].setLocation(tempLoc);
        // ships[i].sunk = false; // Not needed, Ship constructor sets sunk=false
    }
}

bool Fleet::operational() const {
    for (int i = 0; i < FLEET_SIZE; ++i) {
        if (!ships[i].isSunk())
            return true;
    }
    return false;
}

int Fleet::isHitNSink(const Location& loc) {
    int idx = check(loc);
    if (idx == -1)
        return 0; // miss
    if (ships[idx].isSunk())
        return 2; // already sunk
    ships[idx].sink();
    return 1; // hit and sunk
}

void Fleet::printFleet() const {
    for (int i = 0; i < FLEET_SIZE; ++i) {
        cout << ships[i];
        if (i < FLEET_SIZE - 1)
            cout << " , ";
    }
    cout << endl;
}

Ship* Fleet::getShipList() {
    return ships;
}

int Fleet::getFleetSize() {
    return FLEET_SIZE;
}
