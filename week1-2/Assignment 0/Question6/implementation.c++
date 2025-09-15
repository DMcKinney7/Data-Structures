#include <iostream>
#include <string>
#include "areas.h"
using namespace std;
double areaSquare(double side);
double areaRectangle(double length, double width);
double areaTriangle(double base, double height);
double areaCircle(double radius);
void menu();

double areaSquare(double side) {
    return side * side;
}

double areaRectangle(double length, double width) {
    return length * width;
}

double areaTriangle(double base, double height) {
    return (base * height) / 2;
}

double areaCircle(double radius) {
    return PI * radius * radius;
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