#ifndef LINE
#define LINE

#include "Shape.hpp"

class Line: public Shape{

    public:

        // Constructors
        Line();
        Line(int x, int y, int x1, int y1, Canvas* aCanvas);
        Line(Point start, Point end, Canvas* aCanvas);

        // Getters and Setters
        int getLength();
        void setEndPt(int x, int y);

        // Draw shape with specified ending character
        void drawWithEndingPoint(char arrow);

        // Functions inherited from base class Shape
        virtual void draw();
        virtual double computeArea();
        virtual double computePerimeter();

    protected:
        // length of line
        int length;

        // x and y values for end point.
        Point endPt;
};

#endif