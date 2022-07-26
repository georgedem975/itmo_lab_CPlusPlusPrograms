#include "Trapezoid.h"

Trapezoid::Trapezoid()
{
    Point one(1, 0);
    Point two(0, 1);
    Point three(-1, 0);
    Point four(0, -1);
    this->broukenLine.pop_back();
    if (this->broukenLine.size() != 0)
    {
        while (this->broukenLine.size() != 0)
        {
            this->broukenLine.pop_back();
        }
    }
    this->broukenLine.push_back(one);
    this->broukenLine.push_back(two);
    this->broukenLine.push_back(three);
    this->broukenLine.push_back(four);
}

Trapezoid::Trapezoid(Point one, Point two, Point three, Point four)
{
    this->broukenLine.pop_back();
    if (this->broukenLine.size() != 0)
    {
        while (this->broukenLine.size() != 0)
        {
            this->broukenLine.pop_back();
        }
    }
    this->broukenLine.push_back(one);
    this->broukenLine.push_back(two);
    this->broukenLine.push_back(three);
    this->broukenLine.push_back(four);
}

Trapezoid::Trapezoid(const Trapezoid& other)
{
    this->broukenLine = other.broukenLine;
}

Trapezoid::~Trapezoid()
{
    Polygon::~Polygon();
}

bool Trapezoid::isTrapezoid()
{
    if (this->broukenLine.size() != 4)
    {
        return false;
    }
    else
    {
        return true;
    }
}