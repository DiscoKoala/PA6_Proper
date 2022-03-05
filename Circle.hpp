#ifndef CIRCLE
#define CIRCLE

#include "Shape.hpp"

class Circle: public Shape{

    public:
        // Constructors
        Circle();
        Circle(int x, int y, int newRadius, Canvas *theCanvas);

        // Getter and Setter
        int getRadius();
        void setRadius(int newRadius);

        // Functions inherited from base class Shape
        virtual void draw();
        virtual double computeArea();
        virtual double computePerimeter();

    private:
        // Radius member variable
        int radius;
};

#endif