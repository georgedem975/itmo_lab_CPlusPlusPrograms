#include "Point.h"

#include <iostream>
#include <locale.h>

void Point::operator=(const Point &other)
{
    this->spaceX = other.spaceX;
    this->spaceY = other.spaceY;
}

void Point::printPoint()
{
    std::cout << "(" << spaceX << "; " << spaceY << ")" << std::endl;
}

Point::Point()
{
    spaceX = 0;
    spaceY = 0;
}

Point::~Point()
{
    spaceX = NULL;
    spaceY = NULL;
}

Point::Point(double newSpaceX, double newSpaceY)
{
    spaceX = newSpaceX;
    spaceY = newSpaceY;
}

Point::Point(const Point &other)
{
    this->spaceX = other.spaceX;
    this->spaceY = other.spaceY;
}

double Point::GetSpaceX()
{
    return spaceX;
}

double Point::GetSpaceY()
{
    return spaceY;
}

void Point::SetSpaceX(double newSpaceX)
{
    spaceX = newSpaceX;
}

void Point::SetSpaceY(double newSpaceY)
{
    spaceY = newSpaceY;
}

