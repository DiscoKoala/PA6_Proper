#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <limits>

#include "Line.hpp"
#include "Shape.hpp"

using namespace std;

Line::Line(): Shape(){
    endPt.x = 0;
    endPt.y = 0;
    length = 0;
};

Line::Line(int x, int y, int x1, int y1, Canvas* aCanvas): Shape (x, y, aCanvas){
        
    if (x > x1) {
        originPt.x = x1;
        originPt.y = y1;
        endPt.x = x;
        endPt.y = y;
    } else if (x == x1 && y > y1 ) {
        originPt.y = y1;
        endPt.y = y;
        endPt.x = x;
    }  else {  //the default case to set the end point
        endPt.x = x1;
        endPt.y = y1;
    }

    // length = sqrt((x-x1)^2 + (y-y1)^2)
    length = round(sqrt(pow(x - x1, 2) + pow(y - y1, 2)));
};
        
Line::Line(Point start, Point end, Canvas* aCanvas): Shape(start.x, start.y, aCanvas){

    endPt.x = end.x;
    endPt.y = end.y;
    length = round (sqrt(pow(getOriginPtX() - endPt.x, 2) + pow(getOriginPtY() - endPt.y, 2)));

};


void Line::setEndPt(int x, int y){
    
    Shape::setOriginPt(x, y);
};

void Line::draw(){
    int xDiff = abs(endPt.x - originPt.x);
    int yDiff = abs(endPt.y - originPt.y);
    bool yIncreasing = endPt.y >= originPt.y;
    double slope;

    // compute the slope
    if (endPt.x != originPt.x) {
        slope = (endPt.y - originPt.y)/(double)(endPt.x - originPt.x);
    } else {
        slope = numeric_limits<double>::max();
    };

    // y-intercept(b) = y - a*x
    int intercept = originPt.y - slope * originPt.x;
    //cout << slope << " " << intercept << endl;

    int x, y;
    //if the line is a perpedicular vertical line  (else part)
    //use y-coordinate to find the corresponding x-coordinate value
    //if not, loop thru x-coordinate to find the corresponding y-coordinate value
    if (slope != numeric_limits<double>::max()) {
        if (abs(slope) == 0 or abs(slope) > 1 ) {
            for (x = originPt.x; x <= (originPt.x + xDiff); x++ ) {
                y = slope * x  + intercept;
                //y = y * Line::AspectRatio;
                //cout << x << " " << y << endl;
                canvas->GRID[y][x] = lineChar;
            };
        } else {
            bool moreToDraw = true;
            for (y = originPt.y; moreToDraw;){
                x = (y - intercept) / slope;
                //y = y * Line::AspectRatio;
                //cout << slope << " " << intercept << " " << x << " " << y << endl;
                canvas->GRID[y][x] = lineChar;
                if (slope > 0) { 
                    y++;
                    moreToDraw = (y <= (originPt.y + yDiff));
                } else { 
                    y--; 
                    moreToDraw = (y > (originPt.y - yDiff));
                };
            }
        }
    } else {
        x = originPt.x;
        for (y = originPt.y; y <= originPt.y + yDiff; y++ ) {
            //cout << slope << " " << intercept << " " << x << " " << y << endl;
            canvas->GRID[y][x] = lineChar;
        };       
    };
}

int Line::getLength(){
    return length;
};

void Line::drawWithEndingPoint(char arrow){
    
    draw();
    canvas->GRID[originPt.y][originPt.x] = arrow;
    canvas->GRID[endPt.y][endPt.x] = arrow;
};

double Line::computeArea(){
    return length;
};

double Line::computePerimeter(){
    return length;
};
