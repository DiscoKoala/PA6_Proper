#include<iostream>
#include<string>
#include<cstdio>

#include "Rectangle.hpp"
#include "Shape.hpp"
#include "Line.hpp"
#include "Canvas.hpp"
#include "Trapezoid.hpp"

// Default constructor
Trapezoid::Trapezoid(): Shape(){
    topRight.x = 0;
    topRight.y = 0;
};

// Constructor that initializes topRight member variable 
// Initializes via Shape base class
Trapezoid::Trapezoid(int x, int x1, int x2, int y, int theWidth, int theHeight, Canvas* aCanvas): Shape(x, y, aCanvas){
    topRight.x = x + theWidth;
    topRight.y = y + theHeight;
};

// Constructor that takes Point object to set origin ending points
// theBottomLeft = origin points
// theTopRight = ending points
Trapezoid::Trapezoid(Point theBottomLeft, Point theTopRight, Point secondPt, 
        Point thirdPt, Canvas* aCanvas): Shape(theBottomLeft.x, theBottomLeft.y, aCanvas){
    topRight = theTopRight; 
    secondPoint = secondPt;
    thirdPoint = thirdPt;
};

// Rectangle member function for drawing a rectangle on canvas. 
// Utilizes four line object instances.
void Trapezoid::draw(){
    
    Line myLine(originPt.x, originPt.y, topRight.x, topRight.y, canvas),
        myLine1(topRight.x, topRight.y, secondPoint.x, secondPoint.y, canvas),
        myLine2(secondPoint.x, secondPoint.y, thirdPoint.x, thirdPoint.y, canvas),
        myLine3(thirdPoint.x, thirdPoint.y, originPt.x, originPt.y, canvas);

    myLine.draw();
    myLine1.draw();
    myLine2.draw();
    myLine3.draw();

    canvas->netArea += computeArea();
    canvas->netPerimeter += computePerimeter();

};

// Same functionatlity as draw() 
// with the added feature of specifying end point characters
void Trapezoid::drawWithEndingChar(char arrow){
    
    Line myLine(originPt.x, originPt.y, topRight.x, topRight.y, canvas),
        myLine1(topRight.x, topRight.y, secondPoint.x, secondPoint.y, canvas),
        myLine2(secondPoint.x, secondPoint.y, thirdPoint.x, thirdPoint.y, canvas),
        myLine3(thirdPoint.x, thirdPoint.y, originPt.x, originPt.y, canvas);
    
    myLine.drawWithEndingPoint('+');
    myLine1.drawWithEndingPoint('+');
    myLine2.drawWithEndingPoint('+');
    myLine3.drawWithEndingPoint('+');

    canvas->netArea += computeArea();
    canvas->netPerimeter += computePerimeter();
    shapeCounter();
};

double Trapezoid::computeArea(){

};

// Suppose to compute perimeter but my method resulted in segfault 11
double Trapezoid::computePerimeter(){
    // int side = sqrt(pow((thirdPoint.x - originPt.x), 2)) + sqrt(pow(height, 2));
    // return (side + side + length1 + length2);
};