#include "Rotation.h"

class Cubic
{
public:
    Cubic();
    Cubic(Id index);
    Cubic(Id index, Color one);
    Cubic(Id index, Color one, Color two);
    Cubic(Id index, Color one, Color two, Color three);
    Cubic(const Cubic& other);
    ~Cubic();
    void SetColor(Color newColor);
    Color GetColor();
    Color GetNumberColor(int number);
    int GetCounterOfColors();
    Rotation rotate;

private:
    Id index;
    std::vector<Color> colors;
};