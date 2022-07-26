#include "Id.h"

class Rotation
{
public:
    Rotation();
    Rotation(int x, int y, int  z);
    Rotation(const Rotation& other);
    ~Rotation();
    void SetX(int x);
    void SetY(int y);
    void SetZ(int z);
    int GetX();
    int GetY();
    int GetZ();

private:
    int x;
    int y;
    int z;
};