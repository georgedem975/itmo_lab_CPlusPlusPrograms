#include <iostream>
#include <fstream>
#include <vector>

enum Color
{
    white,
    red,
    green,
    blue,
    yellow,
    purple
};

class Id
{
public:
    Id();
    Id(int x, int y, int z);
    Id(const Id& other);
    ~Id();
    void SetIdX(int x);
    void SetIdY(int y);
    void SetIdZ(int z);
    int GetIdX();
    int GetIdY();
    int GetIdZ();

private:
    int x;
    int y;
    int z;
};