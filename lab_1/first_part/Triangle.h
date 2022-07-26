#pragma once

#include "Polygon.h"

class Triangle : public Polygon
{
public:
    Triangle();
    Triangle(Point first, Point second, Point third);
    Triangle(const Triangle& other);
    ~Triangle();
    void printTops() override;
    void length() override;
    bool isTriangle();
    double Square();
    void printSquare();

protected:
    double firstCathet, secondCathet, hypotenuse;
    double lengthFS, lengthST, lengthFT;
    double squareOfTriangle;
};