#include "Figure.h"
#include <iostream>

Figure::Figure()
{
    shapes = nullptr;
    numOfShapes = 0;
}

std::ostream& operator<<(std::ostream& os, const Coordinates& rhs)
{
    os << "(" << rhs.x << ", " << rhs.y << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Box& rhs)
{
    os << "The top left-, and bottom right coordinates for the bounding box are: (" << rhs.topLeft << 
    ") and " << rhs.bottomRight << " respectively.\n";
    return os;
}

void Figure::addShape(Shape *s)
{
    Shape **array = new Shape*[numOfShapes+1];
    for(int i = 0; i < numOfShapes; i++)
    {
        array[i] = shapes[i];
    }
    array[numOfShapes] = s;
    delete[] shapes;
    shapes = array;
    numOfShapes += 1;
}

void Figure::printShapes()
{
    for(int i = 0; i < numOfShapes; i++)
    {
        std::cout << shapes[i]->position().x << ", " << shapes[i]->position().y << '\n';
    }
}

void printCoordinates(Coordinates* coords, int size)
{
    std::cout << "number of coordinates : " << size << "\n";
    for(int i = 0; i < size; ++i)
    {
        std::cout << coords[i] << " ";
    }
        
    std::cout << "\n";
}

Box Figure::getBoundingBox()
{
    double xMin, yMin, xMax, yMax;
    std::cout << "numOfShapes : " << numOfShapes << "\n";
    for (int j = 0; j < numOfShapes; j++)
    {
        Coordinates *coords = shapes[j]->getCoordinates();
        int size = shapes[j]->getSize();

    
        //printCoordinates(coords, size);
        if(j == 0)
        {
            xMin = coords[0].x;
            yMin = coords[0].y;
            xMax = coords[0].x;
            yMax = coords[0].y;
        }
        for (int i = 0; i < size; i++)
        {
            if (coords[i].x < xMin)
            {
                xMin = coords[i].x;
            }
            else if (coords[i].x > xMax)
            {
                xMax = coords[i].x;
            }
            if (coords[i].y < yMin)
            {
                yMin = coords[i].y;
            }
            if (coords[i].y > yMax)
            {
                yMax = coords[i].y;
            }
        }
    }
    Coordinates upperLeft;
    upperLeft.x = xMin;
    upperLeft.y = yMax;

    Coordinates lowerRight;
    lowerRight.x = xMax;
    lowerRight.y = yMin;

    Box boundingBox;
    boundingBox.topLeft = upperLeft;
    boundingBox.bottomRight = lowerRight;

    return boundingBox;
}

Shape** Figure::getClosest(Shape* location, int n)
{
    if(n > numOfShapes)
    {
        n = numOfShapes;
        std::cout << "Too many shapes requested. Returning available shapes." << std::endl;
    }
    Shape** array = new Shape*[n];
    for(int i = 0; i < n; i++)
    {
        array[i] = shapes[i];
    }
    bubbleSort(location, array, n);

    return array;
}

void bubbleSort(Shape* s, Shape* array[], int n)
{
    if(n == 1)
    {
        return;
    }
    for(int i = 0; i < n-1; i++)
    {
        if(s->distance(array[i]) > s->distance(array[i+1]))
        {
            //swap positions
            Shape* temp;
            temp = array[i];
            array[i] = array[i+1];
            array[i+1] = temp;
        }
    }
    bubbleSort(s, array, n-1);
}