#include "Cubic.h"

class CubikRubic
{
public:
    CubikRubic();
    void print();
    bool isTrueCubicRubic();
    bool isTrue();
    void generationAlgorithm(int modificator);
    void F();
    void F___();
    void B();
    void B___();
    void L();
    void L___();
    void R();
    void R___();
    void D();
    void D___();
    void U();
    void U___();
private:
    Cubic arrayOfCubics[3][3][3];
};