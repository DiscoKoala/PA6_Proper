#include<iostream>
#include<string>
#include<cstdio>

#include "Rectangle.hpp"
#include "Shape.hpp"
#include "Line.hpp"
#include "Canvas.hpp"

// Default constructor
Rectangle::Rectangle(): Shape(){
    topRight.x = 0;
    topRight.y = 0;
};

// Constructor that initializes topRight member variable 
// Initializes via Shape base class
Rectangle::Rectangle(int x, int y, int theWidth, int theHeight, Canvas* aCanvas): Shape(x, y, aCanvas){
    topRight.x = x + theWidth;
    topRight.y = y + theHeight;
};

// Constructor that takes Point object to set origin ending points
// theBottomLeft = origin points
// theTopRight = ending points
Rectangle::Rectangle(Point theBottomLeft, Point theTopRight, Canvas* aCanvas): Shape(theBottomLeft.x, theBottomLeft.y, aCanvas){
    topRight = theTopRight; 
};

// Rectangle member function for drawing a rectangle on canvas. 
// Utilizes four line object instances.
void Rectangle::draw(){
    
    Line myLine(originPt.x, originPt.y, topRight.x, originPt.y, canvas),
        myLine1(topRight.x, originPt.y, topRight.x, topRight.y, canvas),
        myLine2(topRight.x, topRight.y, originPt.x, topRight.y, canvas),
        myLine3(originPt.x, topRight.y, originPt.x, originPt.y, canvas);

    myLine.setLineChar('|');
    myLine.draw();
    myLine1.setLineChar('-');
    myLine1.draw();
    myLine2.setLineChar('|');
    myLine2.draw();
    myLine3.setLineChar('-');
    myLine3.draw();

    canvas->netArea += computeArea();
    canvas->netPerimeter += computePerimeter();
    shapeCounter();
};

// Same functionatlity as draw() 
// with the added feature of specifying end point characters
void Rectangle::drawWithEndingChar(char arrow){
    
    Line myLine(originPt.x, originPt.y, topRight.x, originPt.y, canvas),
        myLine1(topRight.x, originPt.y, topRight.x, topRight.y, canvas),
        myLine2(topRight.x, topRight.y, originPt.x, topRight.y, canvas),
        myLine3(originPt.x, topRight.y, originPt.x, originPt.y, canvas),
        myLine4(0, 2, 20, 2, canvas), myLine5(0,4,20,4, canvas), 
        myLine6(0, 6, 20, 6, canvas), myLine7(5,0,5,8,canvas),
        myLine8(10,0,10,8,canvas), myLine9(15,0,15,8,canvas);
    
    myLine.setLineChar('-');
    myLine.drawWithEndingPoint('+');
    myLine1.setLineChar('|');
    myLine1.drawWithEndingPoint('+');
    myLine2.setLineChar('-');
    myLine2.drawWithEndingPoint('+');
    myLine3.setLineChar('|');
    myLine3.drawWithEndingPoint('+');
    myLine4.setLineChar('-');
    myLine4.drawWithEndingPoint('+');
    myLine5.setLineChar('-');
    myLine5.drawWithEndingPoint('+');
    myLine6.setLineChar('-');
    myLine6.drawWithEndingPoint('+');
    myLine7.setLineChar('|');
    myLine7.drawWithEndingPoint('+');
    myLine8.setLineChar('|');
    myLine8.drawWithEndingPoint('+');
    myLine9.setLineChar('|');
    myLine9.drawWithEndingPoint('+');

    canvas->netArea += computeArea();
    canvas->netPerimeter += computePerimeter();
    shapeCounter();
};

// Subtract origin y value from final y value
int Rectangle::getHeight(){
    return topRight.y - originPt.y;
};
// Subtract origin y value from final y value
int Rectangle::getWidth(){
    return topRight.x - originPt.x;
};

// Computes area of rectangle objects
double Rectangle::computeArea(){
    return (this->getWidth() * this->getHeight());
};

// Computes perimeter of rectangle objects
double Rectangle::computePerimeter(){
    return ((2.0*this->getWidth()) + (2.0*this->getHeight()));
};


