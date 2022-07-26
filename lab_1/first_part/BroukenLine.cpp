#include "BroukenLine.h"

BroukenLine::BroukenLine()
{
    Point top(0, 0);
    broukenLine.push_back(top);
}

BroukenLine::BroukenLine(Point first, Point second, Point third)
{
    broukenLine.push_back(first);
    broukenLine.push_back(second);
    broukenLine.push_back(third);
}

BroukenLine::BroukenLine(const BroukenLine& other)
{
    this->broukenLine.operator=(other.broukenLine);
}

BroukenLine::~BroukenLine()
{
    this->broukenLine.~vector();
}

void BroukenLine::createTop(Point newTop)
{
    this->broukenLine.push_back(newTop);
}

void BroukenLine::length()
{
    Point first, second;
    double len = 0;
    for (int i = 1; i < this->broukenLine.size(); i++)
    {
        first = this->broukenLine[i - 1];
        second = this->broukenLine[i];
        len += sqrt((second.GetSpaceX() - first.GetSpaceX()) * (second.GetSpaceX() - first.GetSpaceX()) +
            (second.GetSpaceY() - first.GetSpaceY()) * (second.GetSpaceY() - first.GetSpaceY()));
    }
    std::cout << len << std::endl;
}

void BroukenLine::printTops()
{
    for (int i = 0; i < this->broukenLine.size(); i++)
    {
        this->broukenLine[i].printPoint();
    }
}

void BroukenLine::operator=(const BroukenLine& other)
{
    this->broukenLine = other.broukenLine;
}