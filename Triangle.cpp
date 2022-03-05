#include<iostream>
#include<string>
#include<cmath>

#include "Triangle.hpp"
#include "Point.hpp"
#include "Shape.hpp"
#include "Line.hpp"

// Default constructor
Triangle::Triangle(): Shape(){
    secondPoint.x = 0;
    thirdPoint.y = 0;
};

// Intializes origin points
// Indirectly sets x and y values for second and third points
// Initialized by Shape
Triangle::Triangle(int x, int y, int newBase, int newHeight, Canvas *aCanvas): Shape(x, y, aCanvas){
    originPt.x = x;
    originPt.y = y;
    secondPoint.x = originPt.x + newBase;
    secondPoint.y = originPt.y;
    thirdPoint.y = originPt.y - newHeight;
    thirdPoint.x = originPt.y;
    height = newHeight;
    base = newBase;
};

// Takes Point objects as parameters
// Each object specifies point directly
// Initialized by Shape
Triangle::Triangle(Point origin, Point secondPt, Point thirdPt, Canvas *aCanvas): Shape(origin.x, origin.y, aCanvas){
    originPt = origin;
    secondPoint = secondPt;
    thirdPoint = thirdPt;
    base = secondPoint.x - origin.x;
    height = origin.y - secondPoint.y;

};

// Instantiates three line objects.
// Lines drawn in triangluar fashion
void Triangle::draw(){

    // Line object going from initial point to next point
    Line myLine(originPt.x, originPt.y, secondPoint.x, secondPoint.y, canvas),
        myLine1(secondPoint.x, secondPoint.y, thirdPoint.x, thirdPoint.y, canvas),
        myLine2(thirdPoint.x, thirdPoint.y, originPt.x, originPt.y, canvas);

    myLine.draw();
    myLine1.draw();
    myLine2.draw();

    canvas->netArea = computeArea();
    canvas-> netPerimeter =computePerimeter();
    shapeCounter();
};

// Base getter
int Triangle::getBase(){
    return secondPoint.x - originPt.x;
};

// Height getter
int Triangle::getHeight(){
    return height;
};

// Overriden function to compute triangle area
double Triangle::computeArea(){ 
    return (this->base * this->height)/2;
};

// Overriden function to compute triangle perimeter
double Triangle::computePerimeter(){
    int hyp = sqrt(pow(this->base/2,2)) + sqrt(pow(this->height, 2));
    return (base + hyp + hyp);
};