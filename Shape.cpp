#include<iostream>
#include<string>

#include "Shape.hpp"

int Shape::shapeCount = 0;

// Default base class constructor
Shape::Shape(){
    originPt.x = 0;
    originPt.y = 0;
    canvas = nullptr;
    lineChar  = '=';
};

// Base class constructor for intializes origin points and canvas objects
Shape::Shape(int x, int y, Canvas* aCanvas){
    originPt.x = x;
    originPt.y = y;
    canvas = aCanvas;
    lineChar  = '-';
};

// Line character getter
char Shape::getLineChar(){
    return lineChar;
};

// Line character setter
void Shape::setLineChar(char aLineChar){
    lineChar = aLineChar;
};

// X 0rigin point getter
int Shape::getOriginPtX(){
    return originPt.x;
};
// Y 0rigin point getter
int Shape::getOriginPtY(){
    return originPt.y;
};

// Canvas object getter
Canvas* Shape::getCanvas(){
    return canvas;
};

// Canvas object getter
void Shape::setCanvas(Canvas* aCanvas){
    canvas = aCanvas;
};

// Counts number of drawn shapes
void Shape::shapeCounter(){
    ++shapeCount;
};

// X and Y origin point setter
void Shape::setOriginPt(int x, int y){
    originPt.x = x;
    originPt.y = y;
};

void Shape::display(Canvas* canvas){
    std::cout << "Total area: " << canvas->netArea << std::endl;
    std::cout << "Total perimeter: " << canvas->netPerimeter << std::endl;
    std::cout << "Number of shapes: " << shapeCount << std::endl;
};
