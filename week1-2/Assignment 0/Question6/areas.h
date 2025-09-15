#include <math.h>
#ifndef AREAS_H
#define AREAS_H
const double PI = M_PI;
void menu();
// Calculates the area of a square
double areaSquare(double side);

// Calculates the area of a rectangle
double areaRectangle(double length, double width);

// Calculates the area of a triangle
double areaTriangle(double base, double height);

// Calculates the area of a circle
double areaCircle(double radius);

#endif // AREAS_H

