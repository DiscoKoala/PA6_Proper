#include<iostream>
#include<string>
#include<cmath>

#include "Circle.hpp"
#include "Shape.hpp"
#include "Line.hpp"
#include  "Canvas.hpp"

// Default constructor
Circle::Circle(): Shape(){
    radius = 0;
}

// Initialized by Shape base class
// Initializes origin points for x and y
// Initializes circle radius
Circle::Circle(int x, int y, int newRadius, Canvas* theCanvas): Shape(x, y, theCanvas){
    originPt.x = x;
    originPt.y = y;
    radius = newRadius;
};

// Radius Setter
void Circle::setRadius(int newRadius){
    radius = newRadius;
};

// Draw function that utilizes Line::draw()
// Diameter calculated and used as end point in line object
// If the radius is larger than 1, circle is represented
// by line of 'o' with '(' and ')' on both ends respectively
// Otherwise, circle is represented by 'O'
void Circle::draw(){
    int diameter = originPt.x +(2*radius);
    Line myLine(originPt.x, originPt.y, diameter, originPt.y, canvas),
        myLine2(diameter, originPt.y, diameter, originPt.y, canvas);
    
    if(radius > 2){
        myLine.setLineChar('o');
        myLine.draw();
        canvas->GRID[originPt.y][originPt.x] = '(';
        canvas->GRID[originPt.y][diameter] = ')';
    }
    else{
        // myLine.setLineChar('0');
        myLine2.draw();
        canvas->GRID[originPt.y][diameter] = 'O';
    }

    canvas->netArea += computeArea();
    canvas->netPerimeter += computePerimeter();
    shapeCounter();
};

// Computes area of circle object
double Circle::computeArea(){
    return (M_PI * pow(this->radius, 2.0));
};

// Computes perimeter of circle object
double Circle::computePerimeter(){
    return(2.0 * M_PI * this->radius);
};

// Radius getter
int Circle::getRadius(){
    return radius;
};