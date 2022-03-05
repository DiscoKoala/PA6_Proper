#ifndef CANVAS
#define CANVAS

class Canvas{

    public:
        // Constant default x and y values for canvas size
        const static int MAX_X_VAL = 1280;
        const static int MAX_Y_VAL = 720;
        const static int DEFAULT_X_VAL = 80;
        const static int DEFAULT_Y_VAL = 50;
        static int netArea, netPerimeter;

        // 2D array to hold contents of canvas
        char GRID [MAX_Y_VAL][MAX_X_VAL];
        
        // Constructors
        Canvas();
        Canvas(int xSize, int ySize, char lineChar);

        // Emptying Canvas object to 2D array
        void clearCanvas();

        // Displaying contents of 2D array
        void show();
        // void display();

        // Getter/Setter for filler char
        char getFillChar() ;
        void setFillChar(char newFillChar);
        void setTotalArea(int area);
        void setTotalPerim(int perim);

        void writeFile();
        // void areaAndPerim();

    private:
        // x and y member variables for custom canvas size
        int xSize, ySize;

        // fill character member variable
        char fillChar;
};

#endif