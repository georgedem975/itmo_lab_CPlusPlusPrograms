#include "Triangle.h"

void Triangle::printSquare()
{
    std::cout << this->squareOfTriangle << std::endl;
}

Triangle::Triangle()
{
    Point first(1, 0);
    Point second(0, 1);
    Point third(-1, 0);
    this->broukenLine.pop_back();
    if (this->broukenLine.size() != 0)
    {
        while (this->broukenLine.size() != 0)
        {
            this->broukenLine.pop_back();
        }
    }
    this->broukenLine.push_back(first);
    this->broukenLine.push_back(second);
    this->broukenLine.push_back(third);
    this->squareOfTriangle = this->Square();
}

Triangle::Triangle(Point first, Point second, Point third)
{
    this->broukenLine.pop_back();
    if (this->broukenLine.size() != 0)
    {
        while (this->broukenLine.size() != 0)
        {
            this->broukenLine.pop_back();
        }
    }
    this->broukenLine.push_back(first);
    this->broukenLine.push_back(second);
    this->broukenLine.push_back(third);
    this->squareOfTriangle = this->Square();
}

Triangle::Triangle(const Triangle& other)
{
    this->broukenLine = other.broukenLine;
}

Triangle::~Triangle()
{
    ClosedPolyline::~ClosedPolyline();
}

void Triangle::length()
{
    ClosedPolyline::length();
}

void Triangle::printTops()
{
    ClosedPolyline::printTops();
}

bool Triangle::isTriangle()
{
    if (this->broukenLine.size() != 3)
    {
        return false;
    }

    else
    {
        return true;
    }
}

double Triangle::Square()
{
    double squareOfTriangle;
    lengthFS = sqrt((this->broukenLine[1].GetSpaceX() - this->broukenLine[0].GetSpaceX()) * (this->broukenLine[1].GetSpaceX() - this->broukenLine[0].GetSpaceX()) +
        (this->broukenLine[1].GetSpaceY() - this->broukenLine[0].GetSpaceY()) * (this->broukenLine[1].GetSpaceY() - this->broukenLine[0].GetSpaceY()));
    lengthST = sqrt((this->broukenLine[2].GetSpaceX() - this->broukenLine[1].GetSpaceX()) * (this->broukenLine[2].GetSpaceX() - this->broukenLine[1].GetSpaceX()) +
        (this->broukenLine[2].GetSpaceY() - this->broukenLine[1].GetSpaceY()) * (this->broukenLine[2].GetSpaceY() - this->broukenLine[1].GetSpaceY()));
    lengthFT = sqrt((this->broukenLine[2].GetSpaceX() - this->broukenLine[0].GetSpaceX()) * (this->broukenLine[2].GetSpaceX() - this->broukenLine[0].GetSpaceX()) +
        (this->broukenLine[2].GetSpaceY() - this->broukenLine[0].GetSpaceY()) * (this->broukenLine[2].GetSpaceY() - this->broukenLine[0].GetSpaceY()));
    int flag = 0;

    if (lengthFS > lengthST && lengthFS > lengthFT)
    {
        flag = 1;
    }
    else if (lengthST > lengthFS && lengthST > lengthFT)
    {
        flag = 2;
    }
    else if (lengthFT > lengthFS && lengthFT > lengthST)
    {
        flag = 3;
    }

    switch (flag)
    {
    case 0:
        squareOfTriangle = (lengthFT * lengthST * sqrt(3)) / 4;
        break;
    case 1:
        squareOfTriangle = (lengthFT * lengthFS * lengthST) / (2 * lengthFS);
        break;
    case 2:
        squareOfTriangle = (lengthFT * lengthFS * lengthST) / (2 * lengthST);
        break;
    case 3:
        squareOfTriangle = (lengthFT * lengthFS * lengthST) / (2 * lengthFT);
        break;
    }

    return squareOfTriangle;
}