#include <iostream>

class Point
{
    public:
        Point();
        Point(double newSpaceX, double newSpaceY);
        Point(const Point &other);
        ~Point();
        double GetSpaceX();
        double GetSpaceY();
        void SetSpaceX(double newSpaceX);
        void SetSpaceY(double newSpaceY);
        void operator = (const Point &other);
        void printPoint();
    private:
        double spaceX, spaceY;
};

