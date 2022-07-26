#include "CorrectPolygon.h"

CorrectPolygon::CorrectPolygon()
{
    Point newPoint(0, 0);
    Polygon::BroukenLine::broukenLine.push_back(newPoint);
}

CorrectPolygon::CorrectPolygon(Point a, Point b, Point c)
{
    Polygon::broukenLine.push_back(a);
    Polygon::broukenLine.push_back(b);
    Polygon::broukenLine.push_back(c);
}

CorrectPolygon::CorrectPolygon(const CorrectPolygon& other)
{
    this->broukenLine = other.broukenLine;
}

CorrectPolygon::~CorrectPolygon()
{
    Polygon::~Polygon();
}

void CorrectPolygon::isCorrect()
{
    for (int i = 0; i < this->broukenLine.size() - 2; i++)
    {
        double lengthOne = sqrt((this->broukenLine[i + 1].GetSpaceX() - this->broukenLine[i].GetSpaceX()) * (this->broukenLine[i + 1].GetSpaceX() - this->broukenLine[i].GetSpaceX()) +
            (this->broukenLine[i + 1].GetSpaceY() - this->broukenLine[i].GetSpaceY()) * (this->broukenLine[i + 1].GetSpaceY() - this->broukenLine[i].GetSpaceY()));
        double lengthTwo = sqrt((this->broukenLine[i + 2].GetSpaceX() - this->broukenLine[i + 1].GetSpaceX()) * (this->broukenLine[i + 2].GetSpaceX() - this->broukenLine[i + 1].GetSpaceX()) +
            (this->broukenLine[i + 2].GetSpaceY() - this->broukenLine[i + 1].GetSpaceY()) * (this->broukenLine[i + 2].GetSpaceY() - this->broukenLine[i + 1].GetSpaceY()));
        
        if (lengthOne != lengthTwo)
        {
            std::cout << "is not correct" << std::endl;
            return;
        }
    }
    std::cout << "is correct" << std::endl;
}