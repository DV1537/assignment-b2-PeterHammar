#ifndef FIGURE_H
#define FIGURE_H
#include "Shape.h"

/*
* Extend the Figure class with the following:
* getClosest(Shape location, int n) - returns n closest shapes to the location. 
* Make sure that a Shape can be x,y coordinates as well, i.e. a point.
* In the class, you must implement and use a recursive sorting algorithm of your choice
* Your program should read from a file containing multiple shapes (one per line) and return 3 closes shapes to the first one. 
* The file may contain any number of shapes.
* The program should print the points of each shape. One shape per line.
*/

class Box
{
    public:
        Coordinates topLeft;
        Coordinates bottomRight;
        friend std::ostream& operator<<(std::ostream& os, const Box& rhs);
};

class Figure
{
    public:
        Figure();
        void addShape(Shape *s);
        Box getBoundingBox();
        Shape** getClosest(Shape*, int);
        void bubbleSort(Shape*, Shape*[], int);

        //temporary function
        void printShapes();
    private: 
        Shape** shapes;
        int numOfShapes;
};

#endif