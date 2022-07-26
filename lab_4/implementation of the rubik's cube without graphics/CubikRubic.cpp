#include "CubicRubic.h"

CubikRubic::CubikRubic()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                Id NEW(i, j, k);
                Cubic temp(NEW);
                arrayOfCubics[i][j][k] = temp;
            }
        }
    }
    for (int j = 0; j < 3; j++)
    {
        for (int k = 0; k < 3; k++)
        {
            this->arrayOfCubics[0][j][k].SetColor(white);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int k = 0; k < 3; k++)
        {
            this->arrayOfCubics[i][0][k].SetColor(red);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            this->arrayOfCubics[i][j][2].SetColor(green);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int k = 0; k < 3; k++)
        {
            this->arrayOfCubics[i][2][k].SetColor(blue);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            this->arrayOfCubics[i][j][0].SetColor(yellow);
        }
    }
    for (int j = 0; j < 3; j++)
    {
        for (int k = 0; k < 3; k++)
        {
            this->arrayOfCubics[2][j][k].SetColor(purple);
        }
    }

}

void CubikRubic::print()
{
    Color temp = this->arrayOfCubics[0][1][1].GetColor();
    for (int j = 0; j < 3; j++)
    {
        for (int k = 0; k < 3; k++)
        {
            if (this->arrayOfCubics[0][j][k].rotate.GetX() == 0 &&
                this->arrayOfCubics[0][j][k].rotate.GetY() == 0 &&
                this->arrayOfCubics[0][j][k].rotate.GetZ() == 0)
            {
                if (this->arrayOfCubics[0][1][1].GetColor() == white)
                {
                    std::cout << "white  ";
                }

                else if (this->arrayOfCubics[0][j][k].GetCounterOfColors() > 1)
                {
                    for (int g = 0; g < this->arrayOfCubics[0][j][k].GetCounterOfColors(); g++)
                    {
                        if (this->arrayOfCubics[0][j][k].GetNumberColor(g) == temp)
                        {
                            std::cout << "white  ";
                        }
                    }
                }
            }
        }
        std::cout << "\n";
    }

    temp = this->arrayOfCubics[1][0][1].GetColor();
    for (int j = 0; j < 3; j++)
    {
        for (int k = 0; k < 3; k++)
        {
            if (this->arrayOfCubics[j][0][k].rotate.GetX() == 0 &&
                this->arrayOfCubics[j][0][k].rotate.GetY() == 0 &&
                this->arrayOfCubics[j][0][k].rotate.GetZ() == 0)
            {
                if (this->arrayOfCubics[1][0][1].GetColor() == red)
                {
                    std::cout << "red  ";
                }

                else if (this->arrayOfCubics[j][0][k].GetCounterOfColors() > 1)
                {
                    for (int g = 0; g < this->arrayOfCubics[j][0][k].GetCounterOfColors(); g++)
                    {
                        if (this->arrayOfCubics[j][0][k].GetNumberColor(g) == temp)
                        {
                            std::cout << "red  ";
                        }
                    }
                }
            }
        }
        std::cout << "\n";
    }

    temp = this->arrayOfCubics[1][1][2].GetColor();
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (this->arrayOfCubics[i][j][2].rotate.GetX() == 0 &&
                this->arrayOfCubics[i][j][2].rotate.GetY() == 0 &&
                this->arrayOfCubics[i][j][2].rotate.GetZ() == 0)
            {
                if (this->arrayOfCubics[1][1][2].GetColor() == green)
                {
                    std::cout << "green  ";
                }

                else if (this->arrayOfCubics[i][j][2].GetCounterOfColors() > 1)
                {
                    for (int g = 0; g < this->arrayOfCubics[i][j][2].GetCounterOfColors(); g++)
                    {
                        if (this->arrayOfCubics[i][j][2].GetNumberColor(g) == temp)
                        {
                            std::cout << "green  ";
                        }
                    }
                }
            }
        }
        std::cout << "\n";
    }
    temp = this->arrayOfCubics[1][2][1].GetColor();
    for (int i = 0; i < 3; i++)
    {
        for (int k = 0; k < 3; k++)
        {
            if (this->arrayOfCubics[i][2][k].rotate.GetX() == 0 &&
                this->arrayOfCubics[i][2][k].rotate.GetY() == 0 &&
                this->arrayOfCubics[i][2][k].rotate.GetZ() == 0)
            {
                if (this->arrayOfCubics[i][2][k].GetColor() == blue)
                {
                    std::cout << "blue  ";
                }

                else if (this->arrayOfCubics[i][2][k].GetCounterOfColors() > 1)
                {
                    for (int g = 0; g < this->arrayOfCubics[i][2][k].GetCounterOfColors(); g++)
                    {
                        if (this->arrayOfCubics[i][2][k].GetNumberColor(g) == temp)
                        {
                            std::cout << "blue  ";
                        }
                    }
                }
            }
        }
        std::cout << "\n";
    }
    temp = this->arrayOfCubics[1][1][0].GetColor();
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (this->arrayOfCubics[i][j][0].rotate.GetX() == 0 &&
                this->arrayOfCubics[i][j][0].rotate.GetY() == 0 &&
                this->arrayOfCubics[i][j][0].rotate.GetZ() == 0)
            {
                if (this->arrayOfCubics[1][1][0].GetColor() == yellow)
                {
                    std::cout << "yellow  ";
                }

                else if (this->arrayOfCubics[i][j][0].GetCounterOfColors() > 1)
                {
                    for (int g = 0; g < this->arrayOfCubics[i][j][0].GetCounterOfColors(); g++)
                    {
                        if (this->arrayOfCubics[i][j][0].GetNumberColor(g) == temp)
                        {
                            std::cout << "yellow  ";
                        }
                    }
                }
            }
        }
        std::cout << "\n";
    }
    temp = this->arrayOfCubics[2][1][1].GetColor();
    for (int j = 0; j < 3; j++)
    {
        for (int k = 0; k < 3; k++)
        {
            if (this->arrayOfCubics[2][j][k].rotate.GetX() == 0 &&
                this->arrayOfCubics[2][j][k].rotate.GetY() == 0 &&
                this->arrayOfCubics[2][j][k].rotate.GetZ() == 0)
            {
                if (this->arrayOfCubics[2][1][1].GetColor() == purple)
                {
                    std::cout << "purple  ";
                }

                else if (this->arrayOfCubics[2][j][k].GetCounterOfColors() > 1)
                {
                    for (int g = 0; g < this->arrayOfCubics[2][j][k].GetCounterOfColors(); g++)
                    {
                        if (this->arrayOfCubics[2][j][k].GetNumberColor(g) == temp)
                        {
                            std::cout << "purple  ";
                        }
                    }
                }
            }
        }
        std::cout << "\n";
    }
}

bool CubikRubic::isTrue()
{
    int rot[7] = { -270, -180, -90, 0, 90, 180, 270 };
    bool flag = false;
    int counter = 0;
    for (int g = 0; g < 7; g++)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    if (i != 1 || j != 1 || k != 1)
                    {
                        if (this->arrayOfCubics[i][j][k].rotate.GetX() == rot[g] &&
                            this->arrayOfCubics[i][j][k].rotate.GetY() == rot[g] &&
                            this->arrayOfCubics[i][j][k].rotate.GetZ() == rot[g])
                        {
                            counter++;
                        }
                        if (counter == 26)
                        {
                            flag = true;
                        }
                    }
                }
            }
        }
        counter = 0;
        if (counter == 26)
        {
            break;
        }
    }
    if (flag)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool CubikRubic::isTrueCubicRubic()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (this->arrayOfCubics[i][j][0].rotate.GetX() != 0 ||
                this->arrayOfCubics[i][j][0].rotate.GetY() != 0 ||
                this->arrayOfCubics[i][j][0].rotate.GetZ() != 0)
            {
                return false;
            }
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (this->arrayOfCubics[i][j][2].rotate.GetX() != 0 ||
                this->arrayOfCubics[i][j][2].rotate.GetY() != 0 ||
                this->arrayOfCubics[i][j][2].rotate.GetZ() != 0)
            {
                return false;
            }
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int k = 0; k < 3; k++)
        {
            if (this->arrayOfCubics[i][0][k].rotate.GetX() != 0 ||
                this->arrayOfCubics[i][0][k].rotate.GetY() != 0 ||
                this->arrayOfCubics[i][0][k].rotate.GetZ() != 0)
            {
                return false;
            }
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int k = 0; k < 3; k++)
        {
            if (this->arrayOfCubics[i][2][k].rotate.GetX() != 0 ||
                this->arrayOfCubics[i][2][k].rotate.GetY() != 0 ||
                this->arrayOfCubics[i][2][k].rotate.GetZ() != 0)
            {
                return false;
            }
        }
    }
    for (int j = 0; j < 3; j++)
    {
        for (int k = 0; k < 3; k++)
        {
            if (this->arrayOfCubics[0][j][k].rotate.GetX() != 0 ||
                this->arrayOfCubics[0][j][k].rotate.GetY() != 0 ||
                this->arrayOfCubics[0][j][k].rotate.GetZ() != 0)
            {
                return false;
            }
        }
    }
    for (int j = 0; j < 3; j++)
    {
        for (int k = 0; k < 3; k++)
        {
            if (this->arrayOfCubics[2][j][k].rotate.GetX() != 0 ||
                this->arrayOfCubics[2][j][k].rotate.GetY() != 0 ||
                this->arrayOfCubics[2][j][k].rotate.GetZ() != 0)
            {
                return false;
            }
        }
    }
    return true;
}

void CubikRubic::generationAlgorithm(int modificator)
{
    if (modificator == 2)
    {
        int counterRotation = 0;
        if (counterRotation < 0)
        {
            counterRotation *= -1;
        }
        counterRotation = rand() % 100;
        std::cout << "counter of rotation == " << counterRotation << "\n";
        while (counterRotation != 0)
        {
            int numberRotation = 0;
            numberRotation = rand() % 12;
            if (numberRotation < 0)
            {
                numberRotation *= -1;
            }
            switch (numberRotation)
            {
            case 0:
                this->F();
                break;
            case 1:
                this->F___();
                break;
            case 2:
                this->B();
                break;
            case 3:
                this->B___();
                break;
            case 4:
                this->L();
                break;
            case 5:
                this->L___();
                break;
            case 6:
                this->R();
                break;
            case 7:
                this->R___();
                break;
            case 8:
                this->U();
                break;
            case 9:
                this->U___();
                break;
            case 10:
                this->D();
                break;
            case 11:
                this->D___();
                break;
            default:
                break;
            }
            counterRotation--;
        }
    }
    std::cout << "generation end...   " << '\n';
}

void CubikRubic::F()
{
    for (int i = 0; i < 3; i++)
    {
        for (int k = 0; k < 3; k++)
        {
            this->arrayOfCubics[i][0][k].rotate.SetX(this->arrayOfCubics[i][0][k].rotate.GetX() + 90);
            this->arrayOfCubics[i][0][k].rotate.SetY(this->arrayOfCubics[i][0][k].rotate.GetY() + 90);
            this->arrayOfCubics[i][0][k].rotate.SetZ(this->arrayOfCubics[i][0][k].rotate.GetZ() + 90);
            if (this->arrayOfCubics[i][0][k].rotate.GetX() == 360)
            {
                this->arrayOfCubics[i][0][k].rotate.SetX(0);
            }
            if (this->arrayOfCubics[i][0][k].rotate.GetY() == 360)
            {
                this->arrayOfCubics[i][0][k].rotate.SetY(0);
            }
            if (this->arrayOfCubics[i][0][k].rotate.GetZ() == 360)
            {
                this->arrayOfCubics[i][0][k].rotate.SetZ(0);
            }
        }
    }
}

void CubikRubic::F___()
{
    for (int i = 0; i < 3; i++)
    {
        for (int k = 0; k < 3; k++)
        {
            this->arrayOfCubics[i][0][k].rotate.SetX(this->arrayOfCubics[i][0][k].rotate.GetX() - 90);
            this->arrayOfCubics[i][0][k].rotate.SetY(this->arrayOfCubics[i][0][k].rotate.GetY() - 90);
            this->arrayOfCubics[i][0][k].rotate.SetZ(this->arrayOfCubics[i][0][k].rotate.GetZ() - 90);
            if (this->arrayOfCubics[i][0][k].rotate.GetX() == -360)
            {
                this->arrayOfCubics[i][0][k].rotate.SetX(0);
            }
            if (this->arrayOfCubics[i][0][k].rotate.GetY() == -360)
            {
                this->arrayOfCubics[i][0][k].rotate.SetY(0);
            }
            if (this->arrayOfCubics[i][0][k].rotate.GetZ() == -360)
            {
                this->arrayOfCubics[i][0][k].rotate.SetZ(0);
            }
        }
    }
}

void CubikRubic::B()
{
    for (int i = 0; i < 3; i++)
    {
        for (int k = 0; k < 3; k++)
        {
            this->arrayOfCubics[i][2][k].rotate.SetX(this->arrayOfCubics[i][2][k].rotate.GetX() - 90);
            this->arrayOfCubics[i][2][k].rotate.SetY(this->arrayOfCubics[i][2][k].rotate.GetY() - 90);
            this->arrayOfCubics[i][2][k].rotate.SetZ(this->arrayOfCubics[i][2][k].rotate.GetZ() - 90);
            if (this->arrayOfCubics[i][2][k].rotate.GetX() == -360)
            {
                this->arrayOfCubics[i][2][k].rotate.SetX(0);
            }
            if (this->arrayOfCubics[i][2][k].rotate.GetY() == -360)
            {
                this->arrayOfCubics[i][2][k].rotate.SetY(0);
            }
            if (this->arrayOfCubics[i][2][k].rotate.GetZ() == -360)
            {
                this->arrayOfCubics[i][2][k].rotate.SetZ(0);
            }
        }
    }
}

void CubikRubic::B___()
{
    for (int i = 0; i < 3; i++)
    {
        for (int k = 0; k < 3; k++)
        {
            this->arrayOfCubics[i][2][k].rotate.SetX(this->arrayOfCubics[i][2][k].rotate.GetX() + 90);
            this->arrayOfCubics[i][2][k].rotate.SetY(this->arrayOfCubics[i][2][k].rotate.GetY() + 90);
            this->arrayOfCubics[i][2][k].rotate.SetZ(this->arrayOfCubics[i][2][k].rotate.GetZ() + 90);
            if (this->arrayOfCubics[i][2][k].rotate.GetX() == 360)
            {
                this->arrayOfCubics[i][2][k].rotate.SetX(0);
            }
            if (this->arrayOfCubics[i][2][k].rotate.GetY() == 360)
            {
                this->arrayOfCubics[i][2][k].rotate.SetY(0);
            }
            if (this->arrayOfCubics[i][2][k].rotate.GetZ() == 360)
            {
                this->arrayOfCubics[i][2][k].rotate.SetZ(0);
            }
        }
    }
}

void CubikRubic::L()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            this->arrayOfCubics[i][j][0].rotate.SetX(this->arrayOfCubics[i][j][0].rotate.GetX() + 90);
            this->arrayOfCubics[i][j][0].rotate.SetY(this->arrayOfCubics[i][j][0].rotate.GetY() + 90);
            this->arrayOfCubics[i][j][0].rotate.SetZ(this->arrayOfCubics[i][j][0].rotate.GetZ() + 90);
            if (this->arrayOfCubics[i][j][0].rotate.GetX() == 360)
            {
                this->arrayOfCubics[i][j][0].rotate.SetX(0);
            }
            if (this->arrayOfCubics[i][j][0].rotate.GetY() == 360)
            {
                this->arrayOfCubics[i][j][0].rotate.SetY(0);
            }
            if (this->arrayOfCubics[i][j][0].rotate.GetZ() == 360)
            {
                this->arrayOfCubics[i][j][0].rotate.SetZ(0);
            }
        }
    }
}

void CubikRubic::L___()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            this->arrayOfCubics[i][j][0].rotate.SetX(this->arrayOfCubics[i][j][0].rotate.GetX() - 90);
            this->arrayOfCubics[i][j][0].rotate.SetY(this->arrayOfCubics[i][j][0].rotate.GetY() - 90);
            this->arrayOfCubics[i][j][0].rotate.SetZ(this->arrayOfCubics[i][j][0].rotate.GetZ() - 90);
            if (this->arrayOfCubics[i][j][0].rotate.GetX() == -360)
            {
                this->arrayOfCubics[i][j][0].rotate.SetX(0);
            }
            if (this->arrayOfCubics[i][j][0].rotate.GetY() == -360)
            {
                this->arrayOfCubics[i][j][0].rotate.SetY(0);
            }
            if (this->arrayOfCubics[i][j][0].rotate.GetZ() == -360)
            {
                this->arrayOfCubics[i][j][0].rotate.SetZ(0);
            }
        }
    }
}

void CubikRubic::R()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            this->arrayOfCubics[i][j][2].rotate.SetX(this->arrayOfCubics[i][j][2].rotate.GetX() - 90);
            this->arrayOfCubics[i][j][2].rotate.SetY(this->arrayOfCubics[i][j][2].rotate.GetY() - 90);
            this->arrayOfCubics[i][j][2].rotate.SetZ(this->arrayOfCubics[i][j][2].rotate.GetZ() - 90);
            if (this->arrayOfCubics[i][j][2].rotate.GetX() == -360)
            {
                this->arrayOfCubics[i][j][2].rotate.SetX(0);
            }
            if (this->arrayOfCubics[i][j][2].rotate.GetY() == -360)
            {
                this->arrayOfCubics[i][j][2].rotate.SetY(0);
            }
            if (this->arrayOfCubics[i][j][2].rotate.GetZ() == -360)
            {
                this->arrayOfCubics[i][j][2].rotate.SetZ(0);
            }
        }
    }
}

void CubikRubic::R___()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            this->arrayOfCubics[i][j][2].rotate.SetX(this->arrayOfCubics[i][j][2].rotate.GetX() + 90);
            this->arrayOfCubics[i][j][2].rotate.SetY(this->arrayOfCubics[i][j][2].rotate.GetY() + 90);
            this->arrayOfCubics[i][j][2].rotate.SetZ(this->arrayOfCubics[i][j][2].rotate.GetZ() + 90);
            if (this->arrayOfCubics[i][j][2].rotate.GetX() == 360)
            {
                this->arrayOfCubics[i][j][2].rotate.SetX(0);
            }
            if (this->arrayOfCubics[i][j][2].rotate.GetY() == 360)
            {
                this->arrayOfCubics[i][j][2].rotate.SetY(0);
            }
            if (this->arrayOfCubics[i][j][2].rotate.GetZ() == 360)
            {
                this->arrayOfCubics[i][j][2].rotate.SetZ(0);
            }
        }
    }
}

void CubikRubic::D()
{
    for (int j = 0; j < 3; j++)
    {
        for (int k = 0; k < 3; k++)
        {
            this->arrayOfCubics[0][j][k].rotate.SetX(this->arrayOfCubics[0][j][k].rotate.GetX() + 90);
            this->arrayOfCubics[0][j][k].rotate.SetY(this->arrayOfCubics[0][j][k].rotate.GetY() + 90);
            this->arrayOfCubics[0][j][k].rotate.SetZ(this->arrayOfCubics[0][j][k].rotate.GetZ() + 90);
            if (this->arrayOfCubics[0][j][k].rotate.GetX() == 360)
            {
                this->arrayOfCubics[0][j][k].rotate.SetX(0);
            }
            if (this->arrayOfCubics[0][j][k].rotate.GetY() == 360)
            {
                this->arrayOfCubics[0][j][k].rotate.SetY(0);
            }
            if (this->arrayOfCubics[0][j][k].rotate.GetZ() == 360)
            {
                this->arrayOfCubics[0][j][k].rotate.SetZ(0);
            }
        }
    }
}

void CubikRubic::D___()
{
    for (int j = 0; j < 3; j++)
    {
        for (int k = 0; k < 3; k++)
        {
            this->arrayOfCubics[0][j][k].rotate.SetX(this->arrayOfCubics[0][j][k].rotate.GetX() - 90);
            this->arrayOfCubics[0][j][k].rotate.SetY(this->arrayOfCubics[0][j][k].rotate.GetY() - 90);
            this->arrayOfCubics[0][j][k].rotate.SetZ(this->arrayOfCubics[0][j][k].rotate.GetZ() - 90);
            if (this->arrayOfCubics[0][j][k].rotate.GetX() == -360)
            {
                this->arrayOfCubics[0][j][k].rotate.SetX(0);
            }
            if (this->arrayOfCubics[0][j][k].rotate.GetY() == -360)
            {
                this->arrayOfCubics[0][j][k].rotate.SetY(0);
            }
            if (this->arrayOfCubics[0][j][k].rotate.GetZ() == -360)
            {
                this->arrayOfCubics[0][j][k].rotate.SetZ(0);
            }
        }
    }
}

void CubikRubic::U()
{
    for (int j = 0; j < 3; j++)
    {
        for (int k = 0; k < 3; k++)
        {
            this->arrayOfCubics[2][j][k].rotate.SetX(this->arrayOfCubics[2][j][k].rotate.GetX() - 90);
            this->arrayOfCubics[2][j][k].rotate.SetY(this->arrayOfCubics[2][j][k].rotate.GetY() - 90);
            this->arrayOfCubics[2][j][k].rotate.SetZ(this->arrayOfCubics[2][j][k].rotate.GetZ() - 90);
            if (this->arrayOfCubics[2][j][k].rotate.GetX() == -360)
            {
                this->arrayOfCubics[2][j][k].rotate.SetX(0);
            }
            if (this->arrayOfCubics[2][j][k].rotate.GetY() == -360)
            {
                this->arrayOfCubics[2][j][k].rotate.SetY(0);
            }
            if (this->arrayOfCubics[2][j][k].rotate.GetZ() == -360)
            {
                this->arrayOfCubics[2][j][k].rotate.SetZ(0);
            }
        }
    }
}

void CubikRubic::U___()
{
    for (int j = 0; j < 3; j++)
    {
        for (int k = 0; k < 3; k++)
        {
            this->arrayOfCubics[2][j][k].rotate.SetX(this->arrayOfCubics[2][j][k].rotate.GetX() + 90);
            this->arrayOfCubics[2][j][k].rotate.SetY(this->arrayOfCubics[2][j][k].rotate.GetY() + 90);
            this->arrayOfCubics[2][j][k].rotate.SetZ(this->arrayOfCubics[2][j][k].rotate.GetZ() + 90);
            if (this->arrayOfCubics[2][j][k].rotate.GetX() == 360)
            {
                this->arrayOfCubics[2][j][k].rotate.SetX(0);
            }
            if (this->arrayOfCubics[2][j][k].rotate.GetY() == 360)
            {
                this->arrayOfCubics[2][j][k].rotate.SetY(0);
            }
            if (this->arrayOfCubics[2][j][k].rotate.GetZ() == 360)
            {
                this->arrayOfCubics[2][j][k].rotate.SetZ(0);
            }
        }
    }
}