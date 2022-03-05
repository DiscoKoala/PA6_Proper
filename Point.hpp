#ifndef POINT
#define POINT

struct Point{
    
    int x; 
    int y;

    // Default Constructor
    Point(){};

    // Initializing x and y values for Point object
    Point (int x, int y) : x(x), y(y) {}
};

#endif