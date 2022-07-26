#include "Id.h"

Id::~Id()
{
    this->x = NULL;
    this->y = NULL;
    this->z = NULL;
}

Id::Id(int x, int y, int z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

Id::Id(const Id& other)
{
    this->x = other.x;
    this->y = other.y;
    this->z = other.z;
}

Id::Id()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

int Id::GetIdX()
{
    return this->x;
}

int Id::GetIdY()
{
    return this->y;
}

int Id::GetIdZ()
{
    return this->z;
}

void Id::SetIdX(int x)
{
    this->x = x;
}

void Id::SetIdY(int y)
{
    this->y = y;
}

void Id::SetIdZ(int z)
{
    this->z = z;
}