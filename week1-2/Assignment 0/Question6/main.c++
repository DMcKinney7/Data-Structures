#include <iostream>
#include <string>
#include "areas.h"
#include "implementation.c++"
using namespace std;

int main() {
    int userChoice;  
    do {
        menu();
        cin >> userChoice;
        double side, radius, length, width, base, height;

        switch (userChoice)
            {
            case 1:// Square
                cout << "Please enter the side length of the square(cm): ";
                cin >> side;
                cout << "The area is: " << areaSquare(side) << "cm." << endl;
                break;
            
            case 2:// Rectangle
                cout << "Please enter the length(cm):";
                cin >> length;
                cout << "Please enter the width(cm):";
                cin >> width;
                cout << "The area is: " << areaRectangle(length, width) << "cm." << endl;
                break;
            
            case 3:// Triangle
                cout << "Please enter the base(cm):";
                cin >> base;
                cout << "Please enter the height(cm):";
                cin >> height;
                cout << "The area is: " << areaTriangle(base, height) << "cm." << endl;
                break;

            case 4:// Circle
                cout << "Please enter the radius of the circle(cm):";
                cin >> radius;
                cout << "The area is: " << areaCircle(radius) << "cm." << endl;
                break;

            case 5:// Quit
                cout << "Exiting the program.\n" << endl;
                break;

            default:
                cout << "Invalid choice. Please select a valid option.\n" << endl;
                break;
            }
    } while (userChoice != 5);
    return 0;
}