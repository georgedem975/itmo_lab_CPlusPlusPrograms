#pragma once

#include "ClosedPolyline.h"

class Polygon : public ClosedPolyline
{
public:
    friend class Triangle;
    Polygon();
    Polygon(Point first, Point second, Point third);
    Polygon(const Polygon& other);
    ~Polygon();
    void length() override;
    void printTops() override;
    void createTop(Point newTop) override;
    virtual void theAreaOfARegularPolygon();
};