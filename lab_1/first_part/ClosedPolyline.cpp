#include "ClosedPolyline.h"

void ClosedPolyline::operator=(const ClosedPolyline& other)
{
    this->broukenLine = other.broukenLine;
}

void ClosedPolyline::printTops()
{
    for (int i = 0; i < this->broukenLine.size(); i++)
    {
        this->broukenLine[i].printPoint();
    }
}

void ClosedPolyline::createTop(Point newTop)
{
    this->broukenLine.push_back(newTop);
}

ClosedPolyline::ClosedPolyline()
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

ClosedPolyline::ClosedPolyline(Point first, Point second, Point third)
{
    broukenLine.pop_back();
    broukenLine.push_back(first);
    broukenLine.push_back(second);
    broukenLine.push_back(third);
}
ClosedPolyline::ClosedPolyline(const ClosedPolyline& other)
{
    this->broukenLine = other.broukenLine;
}

ClosedPolyline::~ClosedPolyline()
{
    this->broukenLine.~vector();
}

void ClosedPolyline::length()
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
    Point start = this->broukenLine[0], end = this->broukenLine[this->broukenLine.size() - 1];
    len += sqrt((end.GetSpaceX() - start.GetSpaceX()) * (end.GetSpaceX() - start.GetSpaceX()) +
        (end.GetSpaceY() - start.GetSpaceY()) * (end.GetSpaceY() - start.GetSpaceY()));
    std::cout << len << std::endl;
}

bool ClosedPolyline::intersection() 
{
    for (int i = 0; i < this->broukenLine.size() - 2; i++)
    {
        for (int j = i + 1; j < this->broukenLine.size() - 1; j++)
        {
            float k1 = (this->broukenLine[i].GetSpaceY() - this->broukenLine[i + 1].GetSpaceY()) /
                (this->broukenLine[i].GetSpaceX() - this->broukenLine[i + 1].GetSpaceX());
            float k2 = (this->broukenLine[j].GetSpaceY() - this->broukenLine[j + 1].GetSpaceY()) /
                (this->broukenLine[j].GetSpaceX() - this->broukenLine[j + 1].GetSpaceX());
            float b1 = this->broukenLine[i].GetSpaceY() - (this->broukenLine[i].GetSpaceX() * k1);
            float b2 = this->broukenLine[j].GetSpaceY() - (this->broukenLine[j].GetSpaceX() * k2);
            float X = (b2 - b1) / (k1 - k2);
            float Y = (k1 * X) + b1;
            if (this->broukenLine[i].GetSpaceX() < this->broukenLine[i + 1].GetSpaceX())
            {
                if (this->broukenLine[i].GetSpaceY() < this->broukenLine[i + 1].GetSpaceY())
                {
                    if (this->broukenLine[i].GetSpaceX() < X && this->broukenLine[i + 1].GetSpaceX() > X &&
                        this->broukenLine[i].GetSpaceY() < Y && this->broukenLine[i + 1].GetSpaceY() > Y)
                    {
                        return true;
                    }
                }
                else
                {
                    if (this->broukenLine[i].GetSpaceX() < X && this->broukenLine[i + 1].GetSpaceX() > X &&
                        this->broukenLine[i].GetSpaceY() > Y && this->broukenLine[i + 1].GetSpaceY() < Y)
                    {
                        return true;
                    }
                }
            }
            else
            {
                if (this->broukenLine[i].GetSpaceY() < this->broukenLine[i + 1].GetSpaceY())
                {
                    if (this->broukenLine[i].GetSpaceX() > X && this->broukenLine[i + 1].GetSpaceX() < X &&
                        this->broukenLine[i].GetSpaceY() < Y && this->broukenLine[i + 1].GetSpaceY() > Y)
                    {
                        return true;
                    }
                }
                else
                {
                    if (this->broukenLine[i].GetSpaceX() > X && this->broukenLine[i + 1].GetSpaceX() < X &&
                        this->broukenLine[i].GetSpaceY() > Y && this->broukenLine[i + 1].GetSpaceY() < Y)
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}