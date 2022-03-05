#include<iostream>
#include<string>
#include<thread>
#include<chrono>
#include<fstream>

#include "Canvas.hpp"
#include "Shape.hpp"

int Canvas::netArea = 0;
int Canvas::netPerimeter = 0;

// Default Canvas constuctor
Canvas::Canvas(){
    xSize = DEFAULT_X_VAL;
    ySize = DEFAULT_Y_VAL; 
    // netArea = 0;
    // netPerimeter = 0;
};

// Canvas constructor for initializing canvas size and filler char.
Canvas::Canvas(int xSize, int ySize, char lineChar): xSize(xSize), ySize(ySize), fillChar(lineChar){
    this->clearCanvas();
    // netArea = 0;
    // netPerimeter = 0;
};

// Gets current filler character
char Canvas::getFillChar(){
    return fillChar;
};

// Overwrites default filler char
void Canvas::setFillChar(char newFillChar){
    fillChar = newFillChar;
};



// Resets canvas to "blank" state by filling with fillChar
void Canvas::clearCanvas(){
    
    for(int i = 0; i < xSize; i++){
        for(int j = 0; j < ySize; j++){
            this->GRID[i][j] = fillChar;
        }
    }
};

// Displays contents of 2d array GRID on terminal
void Canvas::show(){
    for(int i = 0; i < xSize; i++){
        for(int j = 0; j < ySize; j++){
            std::cout << this->GRID[i][j];
        }
        std::cout << std::endl;
    };
    std::cout << "Total area: " << netArea << std::endl;
    std::cout << "Total perimeter: " << netPerimeter << std::endl;
    std::cout << "Number of shapes: " << Shape::shapeCount << std::endl;   
}

// Write contents of GRID array to text file
void Canvas::writeFile(){
    
    std::fstream myFile;
    myFile.open("OutputFile.txt", std::ios::out);
    for(int i = 0; i < xSize; i++){
        for(int j = 0; j < ySize; j++){
            myFile << this->GRID[i][j];
        }
        myFile << std::endl;
    };
}

