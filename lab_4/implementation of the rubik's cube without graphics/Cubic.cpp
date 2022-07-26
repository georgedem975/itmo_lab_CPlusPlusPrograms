#include "Cubic.h"

Color Cubic::GetColor()
{
    return this->colors.front();
}

int Cubic::GetCounterOfColors()
{
    return this->colors.size();
}

Color Cubic::GetNumberColor(int number)
{
    return this->colors[number];
}

void Cubic::SetColor(Color newColor)
{
    this->colors.push_back(newColor);
}

Cubic::Cubic()
{
    this->index.SetIdX(1);
    this->index.SetIdY(1);
    this->index.SetIdZ(1);
    if (this->colors.size() != 0)
    {
        while (this->colors.size() != 0)
        {
            this->colors.pop_back();
        }
    }
}

Cubic::Cubic(Id index)
{
    this->index.SetIdX(index.GetIdX());
    this->index.SetIdY(index.GetIdY());
    this->index.SetIdZ(index.GetIdZ());
    if (this->colors.size() != 0)
    {
        while (this->colors.size() != 0)
        {
            this->colors.pop_back();
        }
    }
}

Cubic::Cubic(const Cubic& other)
{
    this->index = other.index;
    for (int i = 0; i < other.colors.size(); i++)
    {
        this->colors[i] = other.colors[i];
    }
}

Cubic::Cubic(Id index, Color one)
{
    this->index = index;
    this->colors.push_back(one);
}

Cubic::Cubic(Id index, Color one, Color two) : Cubic(index, one)
{
    this->colors.push_back(two);
}

Cubic::Cubic(Id index, Color one, Color two, Color three) : Cubic(index, one, two)
{
    this->colors.push_back(three);
}

Cubic::~Cubic()
{
    if (this->colors.size() != 0)
    {
        while (this->colors.size() != 0)
        {
            this->colors.pop_back();
        }
    }
}