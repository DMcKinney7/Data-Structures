#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int calculateDistance(int time, int speed) { 
    return(time * speed);
}

int main() 
{
    int timeInput, speedInput;
    cout << "Please enter the time (in seconds): ";
    cin >> timeInput;
    cout << "Please enter the speed (in Meters/Second): ";
    cin >> speedInput;
    cout << calculateDistance(timeInput, speedInput)<< " Meters" << endl;
}

/*
Scope
Write a C++ Program that finds the value of the Distance from the following formula: 

Distance = Time x Speed.

The program prompts the user to enter both the time in seconds and speed in Meter/second and then sends them to a function as parameters.  The function calculates the Distance using the formula shown above and returns the distance value.  The program outputs the returned value to the screen.
*/