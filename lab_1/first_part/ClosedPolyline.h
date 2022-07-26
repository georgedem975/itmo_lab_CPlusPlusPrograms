#pragma once

#include "BroukenLine.h"

class ClosedPolyline : public BroukenLine
{
public:
    ClosedPolyline();
    ClosedPolyline(Point first, Point second, Point third);
    ClosedPolyline(const ClosedPolyline& other);
    ~ClosedPolyline();
    void length() override;
    void createTop(Point newTop) override;
    void printTops() override;
    bool intersection();
    void operator =(const ClosedPolyline& other);
};
