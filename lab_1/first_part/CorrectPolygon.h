#pragma once

#include "Polygon.h"

class CorrectPolygon : public Polygon
{
public:
    CorrectPolygon();
    CorrectPolygon(Point a, Point b, Point c);
    CorrectPolygon(const CorrectPolygon& other);
    ~CorrectPolygon();
    void isCorrect();
};