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