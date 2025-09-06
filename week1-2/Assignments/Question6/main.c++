#include <iostream>
#include <string>
#include "areas.h"
using namespace std;
void menu();

int main() {
    int userChoice;
    double radius, length, width;
    
    do {
    menu();
    cin >> userChoice;

    switch (userChoice)
    {
    case 1:
        
        break;
    
    case 2:
        break;
    
    case 3:
        break;

    case 4:
        break;

    case 5:
        cout << "Exiting the program.\n" << endl;
        break;

    default:
        cout << "Invalid choice. Please select a valid option.\n" << endl;
        break;
    }
    } while (userChoice != 5);

    

// Radius in cm: 0.5

// The area is:  0.785 cm.

// Please select the shape

//     Square
//     Rectangle
//     Triangle
//     Circle
//     Quit

// select figure: 4

// Length in cm: 90

// Width in cm: 70

// The area is: 6300 cm
}

void menu() {
    cout << "Please select the shape\n" << endl;
    cout << "\t1: Square" << endl;
    cout << "\t2: Rectangle" << endl;
    cout << "\t3: Triangle" << endl;
    cout << "\t4: Circle" << endl;
    cout << "\t5: Quit" << endl;
    cout << "\nSelect figure: ";
}
/*
scope
Question 6: Area Calculator (multiple files) [10 points]

Write a C++ program that finds (calculates) the area of a shape selected by the user (Square, Rectangle, triangle, and circle) and prints the result to the screen.

Each shape has a designated function to calculate its area and receives the required information to conduct the calculation. However, the results are returned by the function (not a void function) to the caller (main function) such that the required information to calculate the area is read in the main function and passed to the right function based on the user selection.

 

In this program, you are expected to implement the functions inside a different file (implementation.cpp) and have the signatures of the functions stored in a header file (areas.h) which is included by the main file. That is, your project will have 3 files:

1: main cpp files (mainFile.cpp)  2: header file (areas.h),     3: implementation cpp file (implementation.cpp)

The first main file includes the header file (#include "areas.h") and all the needed libraries and is responsible for reading the user selection and the proper information needed for calculating the area of the selected shape. This file is expected to recognize the user selection and invoke (call) the proper function with the required pieces of information and then receive the returned value from the called function and prints it to the screen.  The idea is to try to avoid any side effects to the functions (see the slides) by making the input and the output conducted in the main function and outside the calculating functions. The program repeatedly asks the user to select the shape or 5 to quit.

The header file (areas.h) will contain function signatures and global variables if needed.

The implementation file (implementation.cpp) is where you need to fully implement your functions declared in the header file.  You also need to make sure that your header file is included here as well.

Note: for the circle, you can assume that PI (π) is 3.14

 

See an example dialog below:

Please select the shape

    Square
    Rectangle
    Triangle
    Circle
    Quit

select figure: 4

Radius in cm: 0.5

The area is:  0.785 cm.

Please select the shape

    Square
    Rectangle
    Triangle
    Circle
    Quit

select figure: 4

Length in cm: 90

Width in cm: 70

The area is: 6300 cm

...
-*/