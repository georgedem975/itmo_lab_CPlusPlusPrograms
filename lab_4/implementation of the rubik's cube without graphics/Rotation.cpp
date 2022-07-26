#include "Rotation.h"

Rotation::Rotation()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Rotation::Rotation(int x, int y, int z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

Rotation::Rotation(const Rotation& other)
{
    this->x = other.x;
    this->y = other.y;
    this->z = other.z;
}

Rotation::~Rotation()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

void Rotation::SetX(int x)
{
    this->x = x;
}

void Rotation::SetY(int y)
{
    this->y = y;
}

void Rotation::SetZ(int z)
{
    this->z = z;
}

int Rotation::GetX()
{
    return this->x;
}

int Rotation::GetY()
{
    return this->y;
}

int Rotation::GetZ()
{
    return this->z;
}