#include "Polygon.h"

void Polygon::theAreaOfARegularPolygon()
{
    double square = 0;
    std::vector<Point> origin;
    origin = this->broukenLine;
    std::vector<Point> ostat;
    if (this->broukenLine.size() < 3)
    {
        std::cout << "not a polygon";
        exit(1);
    }
    int index = 0;
    int flags = 2;

    while (origin.size() > 2)
    {
        if (origin.size() - flags > 0)
        {
            ostat.push_back(origin[index]);
            ostat.push_back(origin[index + 2]);
            index += 2;
            flags = flags + 2;
        }
        origin = ostat;
    }
    std::cout << square << std::endl;
}

void Polygon::createTop(Point newTop)
{
    ClosedPolyline::broukenLine.push_back(newTop);
}

void Polygon::printTops()
{
    ClosedPolyline::printTops();
}

void Polygon::length()
{
    ClosedPolyline::length();
}

Polygon::Polygon(const Polygon& other)
{
    this->broukenLine = other.broukenLine;
}

Polygon::Polygon()
{
    Point top(0, 0);
    broukenLine.pop_back();
    if (broukenLine.size() != 0)
    {
        while (broukenLine.size() != 0)
        {
            broukenLine.pop_back();
        }
    }
    broukenLine.push_back(top);
}

Polygon::~Polygon()
{
    this->broukenLine.~vector();
}

Polygon::Polygon(Point first, Point second, Point third)
{
    this->broukenLine.pop_back();
    this->broukenLine.push_back(first);
    this->broukenLine.push_back(second);
    this->broukenLine.push_back(third);
}
