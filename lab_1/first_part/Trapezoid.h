#pragma once

#include "Polygon.h"

class Trapezoid : public Polygon
{
public:
    Trapezoid();
    Trapezoid(Point one, Point two, Point three, Point four);
    Trapezoid(const Trapezoid& other);
    ~Trapezoid();

private:
    bool isTrapezoid();
};