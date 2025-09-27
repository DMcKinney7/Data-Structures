/*
Part 2: Battleship Game (Classes and Dynamic Memory) [20 Points]

Partial Source Code:

    Header file: battleship.h 

Download battleship.h 
Test File :  testingFile.cpp
Download testingFile.cpp  
Partial Implementation File:  battleship.cpp

    Download battleship.cpp 

Description: Programming Project 2

(OOP Style, Dynamic Memory Allocation with Classes, Rule of Three, Class Composition).  Project Goals: o Brush up on OOP-style concepts stuff studied in CS I and CS I.

    Learn more about how to test an application and develop it in an incremental manner. o Basic output formatting. o Work with class composition and using class objects as members of other classes

Partial Code: Please go to Canvas and download the zipped folder that has the partial code. (please unzip the project folder before using it). The source code is shown below if you want to copy and paste it to your project instead of going to Canvas.  Make sure that the names of the files are as described below. 

    Header file: battleship.h 

Download battleship.h 
Test File :  testingFile.cpp
Download testingFile.cpp  
Partial Implementation File:  battleship.cpp

    Download battleship.cpp 

Classes with Dynamic Memory Allocation and Class Composition.

(Solve using OOP Style, two projects, a test, and the game)

Introduction

In this programming assignment, you are expected to develop a simplified version of the Battleship guessing game. The assignment is broken into two parts, the test part, and the full program (game). The below game and header file description apply to both parts. The idea is to encourage you to work on the development of the components (classes) that are expected to be used to build up the system (the battleship game) and test them before using them in your game development. 

Battleship game description. The field (ocean or space) is a square (6X6 grid).  Both of the coordinates of the grid (x and y) are numbers (from 1 to 6). Your program should randomly place a fleet of six ships in the ocean. Each ship takes up exactly one location in the ocean.   Multiple ships cannot be placed in the same location.  The ships, however, can be placed in adjacent locations.  The user fires on the ships by specifying the coordinates of the shot (x & y). The program reports whether each shot was a hit or a miss.  If the shot is a hit, the ship is sunk. The game continues until all ship fleet is sunk. The program does not keep track of the locations of the previously fired shots (will be a different project). However, the program tells the player that the ship is already sunk if the spot it occupies has been already chosen before. 

Classes and methods’ description. The classes and methods needed to implement the game are mostly declared in the header file (attached and shown below).  There are three main classes:

    Location stores the x and y coordinates of a ship or a shot.
    Ship stores the coordinates of the ship in a Location object and a Boolean variable signifying whether the ship was sunk.
    Fleet contains the fleet of the deployed ships.

The methods and functions that you are expected to implement are explained in the header file and project description. So, read the description and the comments in the header file carefully. Ask if you have any questions in a timely manner. 

    Functions that display the location of the fleet. After the fleet is deployed, the user is prompted if she would like to see the location of the ships (Hint: use this option for debugging). If the user selects this option (for testing purposes), the locations of the ship (and their status: sunk or not) are printed after every shot

The printout is done using the following methods (see header as well):

    Extraction operator << is overloaded for the Ship class on your behalf. It prints the location and status of a single ship. Again, it is already implemented for you (please use the same concept for future projects). A video is available on Canvas on how to overload operators in C++ if need be.
    printFleet() prints the location and the status (sunk or not) of the whole fleet of ships. This function uses the overloaded << operator for the Ship class. The output of this function may look like this:

[2, 3]-> up , [5, 1]-> up , [5, 5]-> sunk , [4, 4]-> up , [3, 5]-> sunk , [4, 1]-> up , [3, 3]-> sunk

Battle functions that control the gameplay. 

After the fleet of ships is deployed (ships are placed in random locations), and its location is printed if desired, the game starts. the pseudocode for your main() method should be as follows:

declare an object of class Fleet call deployFleet() method on it prompt the user if ships' positions and status need to be printed (for testing).

loop while method operational() returns true  ( at least one ship is not sunk.)      

Inside the loop:       declare an object of class Location,      invoke fire() on it to get the location of the user's shot,       pass this object to isHitNSink() method of your Fleet object analyze the return value of this method, and report a hit or a miss.         If the ship is already sunk, report that as well.     

The code and data are declared (Figure 1: header file “battleship.h

Download battleship.h ”, below). The information about locations, ships, and the entire fleet is encapsulated in classes. Please read them carefully.

C++ Projects you need to create:

    Create a test project that uses the given header file (h), shown below, and the test source file “Figure 2: testingFile.cpp 

Download testingFile.cpp ”, shown below. Add them to your test project. Then, implement member methods for the classes of battleship.h Download battleship.h and place the defined member functions in a source code file (testingFile.cpp

    Download testingFile.cpp)

You should implement the member functions for classes in an incremental way. Start with implementing member functions for class Location, then proceed to ship and then to the fleet. Uncomment the portions of testingFile.cpp
Download testingFile.cpp as you work on a particular class. Once your project works correctly with all code of testingFile.cpp

Download testingFile.cpp uncommented, submit your test project.  So, now you are confident that your classes can be used to develop the game.  That is, your header file and implementation file should be reused in the second project.

    Create a project and use battleship.h 

Download battleship.h  and battleship.cpp Download battleship.cpp from the test project above. Add game.cpp that contains main(), invokes the game functions declared in battleship.h

    Download battleship.h  and implements the Battleship game

Hint: the pseudocode for your main() should be as follows:

    Begin
    declare an object of class fleet (say fleet)
    call fleet.deployFleet() method on it
    prompt the user if ships' positions and status need to be printed
    (Inside a while loop) declare an object of class location, say loc
    invoke fire() to get the location of the user's shot,
    pass this object to isHitNSink() method of your fleet object for analysis.
    analyze the returned value from isHitNSink() and report a hit or a miss, already sunk based on returned code (0 miss, 1 hit, 2 already sunk).
    If (fleet.operational()) is true go to step 4. “loop while method operational() returns true - i.e. at least one ship is not sunk. “
    End

Summary of methods you need to implement for the declared classes:

Class Location:

Location::Location():  A default constructor that dynamically allocates an array with two elements coordinates[0] for x coordinate and coordinates[1] for y coordinate. Both are initialized with -1

 

Location::Location(int x, int y): An overloaded constructor that dynamically allocates an array with two elements coordinates[0] for x coordinate and coordinates[1] for y coordinate. parameters are used to initialize the array elements.

 

void Location::pick(): generates and assigns random coordinates [1 to 6] to the array elements void Location::fire(): Prompts the user to enter valid coordinates and assign them to the location array elements.  User entry is verified and a message is printed to the user if she enters invalid coordinates. void Location::print() const: a constant method that prints the location coordinates in the format [x,y]

//rule of three, since we have a member that uses dynamic memory allocation 

Location::Location(const Location& existing) : copyconstructor

Location& Location::operator=(const Location& existing) : assignment overloading  Location::~Location() { delete[] coordinates; }

Class Ship:

Ship::Ship(): Default constructor that assigns false to the sunk bool variable

bool Ship::match(const Location& otherLocation) const: A constant method that returns true if the received location parameters have the same coordinates. It does invoke the friend function compare(). The method returns false if the Location objects are not equal.

void Ship::sink(): sinks the ship. void Ship::setLocation(const Location& currentLoc): updates the ship location with the received parameter.

 

Class Fleet:

int Fleet::check(const Location& loc) const: a constant method that returns the index of the ship that occupies the received location object. The method returns -1 if there is no ship in the fleet that has the same coordinates.

void Fleet::deployFleet() // deploys the ships in random locations such that no location is occupied by more than one ship.

 

bool Fleet::operational() const: returns true as long as there is at least one none-sunk ship. It returns false if all the fleet is sunk.

int Fleet::isHitNSink(const Location& loc): checks the object that was fired by the user and sent to this method to see if it is occupied y any ship in the fleet.

This method:

returns 0 if none of the fleet ships occupies this location, which means it is a miss.

returns 1 if it is a hit, where a ship in the fleet is found to be occupying this location. This method sinks the ship and then returns 1.

returns 2 if the ship that occupies this location is already sunk.

Tips/Hints:

Think about a method that is part of the class Fleet that can be used here inside this method to search for a location used by the fleet that matches the received location coordinates.

void Fleet::printFleet() const: A constant method that prints the fleet information in the format shown below:

[2, 3]-> up , [5, 1]-> up , [5, 6]-> sunk , [4, 4]-> up , [3, 5]-> sunk, [4, 1]-> up , [3, 3]-> sunk

You are expected to benefit from the class ship printability (thanks to operator << overloading in the ship) Ship* Fleet::getShipList() : returns the fleet array.

 

int Fleet::getFleetSize(): returns the fleet size. Technically, it returns the const member FLEET_SIZE that is declared inside the fleet.

    Header file: battleship.h 

Download battleship.h 
Test File :  testingFile.cpp
Download testingFile.cpp  
Partial Implementation File:  battleship.cpp
Download battleship.cpp 
*/