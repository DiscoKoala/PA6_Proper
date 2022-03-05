#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

#include "Point.hpp"
#include "Shape.hpp"
#include "Canvas.hpp"
#include "Line.hpp"
#include "Rectangle.hpp"
#include "Square.hpp"
#include "Circle.hpp"
#include "Triangle.hpp"
#include "Trapezoid.hpp"

using namespace std;

int main(){

    // Canvas object instantiation
    Canvas* myScreen = new Canvas(30, 30, ' ');

    // Shape objects instantiation
    Rectangle myRectangle(0, 0, 20, 8, myScreen);
    // Square mySquare(21, 18, 8, myScreen);
    // Triangle myTriangle(8, 12, 16, 8, myScreen);
    // Triangle myTriangle1(Point(25, 12), Point(33, 4), Point(41, 12), myScreen);
    // Circle myCircle(21, 28, 4, myScreen);
    // Trapezoid myTrapezoid(Point(5, 46), Point(15, 41), Point(25, 41), Point(35, 46), myScreen);

    // Drawing shapes
    myRectangle.drawWithEndingChar('+');
    // mySquare.drawWithEndingChar('+');
    // myTrapezoid.drawWithEndingChar('+');
    // myTriangle.draw();
    // myTriangle1.draw();
    // myCircle.draw();

    //Displaying contents of canvas
    myScreen->show();
    myScreen->writeFile();

    return 0;
};