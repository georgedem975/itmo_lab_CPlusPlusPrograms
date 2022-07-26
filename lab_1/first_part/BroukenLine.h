#include "Point.h"

#include <vector>
#include <iostream>

class BroukenLine
{
    public:
        BroukenLine();
        BroukenLine(Point First, Point Second, Point Third);
        BroukenLine(const BroukenLine &other);
        ~BroukenLine();
        virtual void createTop(Point newTop);
        virtual void length();
        virtual void printTops();
        void operator =(const BroukenLine & other);
    protected:
        std::vector<Point> broukenLine;
};
