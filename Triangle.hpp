#ifndef TRIANGLE
#define TRIANGLE

#include "Shape.hpp"

class Triangle: public Shape{

    public:
        // Base and height variable declaration
        int base, height;

        // Point objects
        Point secondPoint, thirdPoint;
        
        // Constructors
        Triangle();
        Triangle(int x, int y, int newBase, int newHeight, Canvas *theCanvas);
        Triangle(Point origin, Point secondPt, Point thirdPt, Canvas *theCanvas);

        // Getters and setters
        int getBase();
        void setBase(int newBase);
        int getHeight();
        void setHeight(int newHeight);

        // Virtual functions inherited from base class Shape
        virtual void draw();
        virtual double computeArea();
        virtual double computePerimeter();
};

#endif