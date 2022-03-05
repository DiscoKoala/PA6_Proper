#ifndef RECTANGLE
#define RECTANGLE

#include "Shape.hpp"

class Rectangle: public Shape{

    public:
    // Constructors
    Rectangle();
    Rectangle(int x, int y, int theWidth, int theHeight, Canvas* aCanvas);
    Rectangle(Point theBottomLeft, Point theTopRight, Canvas* aCanvas);
    
    // Getters 
    int getHeight();
    int getWidth();

    // Polymorphed draw function
    void drawWithEndingChar(char arrow);

    // Virtual functions inherited from base class Shape
    virtual void draw();
    virtual double computeArea();
    virtual double computePerimeter();

    private:
        // End points
        Point topRight;
};

#endif 