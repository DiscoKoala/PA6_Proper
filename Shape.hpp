#ifndef SHAPES
#define SHAPES

#include "Canvas.hpp"
#include "Point.hpp"

class Shape{

    public:

        static int shapeCount;

        // Base class constructors
        Shape();
        Shape(int x, int y, Canvas* aCanvas);
        Shape(Point origin, int x, Canvas* aCanvas);

        // Counts number of drawn shapes
        static void shapeCounter();
        void display(Canvas* canvas);

        // Getters
        char getLineChar();
        int getOriginPtX();
        int getOriginPtY();
        
        // Returns pointer to Canvas object
        Canvas* getCanvas();

        // Sets object pointer to specified object
        void setCanvas(Canvas* aCanvas);

        void setLineChar(char aLineChar);
        void setOriginPt(int x, int y);

        // Base class virtual functions to be overridden in derived classes
        virtual void draw() = 0;
        virtual double computeArea() = 0;
        virtual double computePerimeter() = 0;

    protected:
        // Declare pointer to canvas object
        Canvas* canvas;

        // Object holding origin points
        Point originPt;

        // Line character variable declaration
        char lineChar;
        


};

#endif 