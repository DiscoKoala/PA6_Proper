#ifndef TRAPEZOID
#define TRAPEZOID

#include "Shape.hpp"
#include "Canvas.hpp"

class Trapezoid: public Shape{

    public:

    Trapezoid();
    Trapezoid(int x, int x1, int x2, int y, int theWidth, int theHeight, Canvas* aCanvas);
    Trapezoid(Point theBottomLeft, Point theTopRight, Point secondPt, Point thirdPt, Canvas* aCanvas);

    void drawWithEndingChar(char arrow);

    // Virtual functions inherited from base class Shape
    virtual void draw();
    virtual double computeArea();
    virtual double computePerimeter();

    private:
        // End points
        Point topRight, secondPoint, thirdPoint;
        int height, length1, length2;
};

#endif