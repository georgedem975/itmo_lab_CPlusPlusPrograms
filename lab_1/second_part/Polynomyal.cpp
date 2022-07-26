#include "Polynomyal.h"


void Polynomyal::print(int id)
{
    if (id < 0 || id > this->polynomyal.size())
    {
        std::cout << "WRONG ID" << "\n";
    }
    else if (id == this->polynomyal.size() + 1)
    {
        std::cout << this->constanta << "\n";
    }
    else
    {
        std::cout << this->polynomyal[id].first << this->polynomyal[id].second.GetVariable() << '^' << this->polynomyal[id].second.GetDegree() << '\n';
    }
}

void Polynomyal::operator[](int index)
{
    this->print(index);
}

void Polynomyal::print()
{
    for (int i = 0; i < polynomyal.size(); i++)
    {
        std::cout << polynomyal[i].first;
        polynomyal[i].second.print();
        if (i < polynomyal.size() - 1)
        {
            std::cout << " + ";
        }
    }
    if (this->constanta != 0)
    {
        std::cout << " + " << constanta;
    }
    std::cout << '\n';
}

Polynomyal::Polynomyal()
{
    this->constanta = 0;
}

int Polynomyal::stringToInt(std::string value)
{
    int waigth = 1;
    int result = 0;
    for (int i = value.size() - 1; i >= 0; i--)
    {
        result += ((int)value[i] - (int)'0') * waigth;
        waigth *= 10;
    }
    return result;
}

Polynomyal::Polynomyal(std::string polynom)
{
    std::string constString;
    std::string degree;
    std::basic_string<char> var;
    bool flag = false;
    for (int i = 0; i <= polynom.size(); i++)
    {
        int temp = (int)polynom[i];
        if (temp >= 48 && temp <= 57)
        {
            if (!flag)
            {
                constString.push_back(polynom[i]);
            }
            else
            {
                degree.push_back(polynom[i]);
            }
        }
        else if (temp >= 97 && temp <= 122)
        {
            var.push_back(polynom[i]);
            flag = true;
        }
        else if (temp == 43 || i == polynom.size())
        {
            Variable newVar(stringToInt((degree)), var);
            polynomyal.push_back(std::make_pair(stringToInt(constString), newVar));

            if (stringToInt(degree) == 0)
            {
                polynomyal.pop_back();
                this->constanta += stringToInt(constString);
            }
            else if (stringToInt(constString) == 0)
            {
                polynomyal.pop_back();
            }
            else if (polynomyal.size() > 1)
            {
                polynomyal.pop_back();
                flag = true;
                for (int j = 0; j < polynomyal.size() && flag; j++)
                {
                    if (stringToInt(degree) == polynomyal[j].second.GetDegree() && var == polynomyal[j].second.GetVariable())
                    {
                        polynomyal[j].first = polynomyal[j].first + stringToInt(constString);
                        flag = false;
                    }
                }
                if (flag)
                {
                    polynomyal.push_back(std::make_pair(stringToInt(constString), newVar));
                }
            }

            flag = false;
            while (constString.size() != 0)
            {
                constString.pop_back();
            }
            while (degree.size() != 0)
            {
                degree.pop_back();
            }
            while (var.size() != 0)
            {
                var.pop_back();
            }
        }
    }
}

Polynomyal::Polynomyal(const Polynomyal& other)
{
    if (this->polynomyal.size() != 0)
    {
        while (this->polynomyal.size() != 0)
        {
            this->polynomyal.pop_back();
        }
    }
    if (this->constanta != 0)
    {
        this->constanta = 0;
    }
    for (int i = 0; i < other.polynomyal.size(); i++)
    {
        this->polynomyal.push_back(other.polynomyal[i]);
    }
    this->constanta = other.constanta;
}

Polynomyal::~Polynomyal()
{
    for (int i = 0; i < this->polynomyal.size(); i++)
    {
        this->polynomyal.pop_back();
    }
    this->constanta = NULL;
}

Polynomyal& Polynomyal::operator=(const Polynomyal& other)
{
    while (this->polynomyal.size() != 0)
    {
        this->polynomyal.pop_back();
    }
    for (int i = 0; i < other.polynomyal.size(); i++)
    {
        this->polynomyal.push_back(other.polynomyal[i]);
    }
    this->constanta = other.constanta;
    return *this;
}

bool Polynomyal::operator==(const Polynomyal& other)
{
    if (this->polynomyal.size() != other.polynomyal.size())
    {
        return false;
    }
    else if (this->constanta != other.constanta)
    {
        return false;
    }
    else
    {
        for (int i = 0; i < this->polynomyal.size(); i++)
        {
            if (this->polynomyal[i].first != other.polynomyal[i].first || this->polynomyal[i].second != other.polynomyal[i].second)
            {
                return false;
            }
        }
        return 1;
    }
}

bool Polynomyal::operator!=(const Polynomyal& other)
{
    if (this->polynomyal.size() != other.polynomyal.size())
    {
        return true;
    }
    else if (this->constanta != other.constanta)
    {
        return true;
    }
    else
    {
        for (int i = 0; i < this->polynomyal.size(); i++)
        {
            if (this->polynomyal[i].first != other.polynomyal[i].first || this->polynomyal[i].second != other.polynomyal[i].second)
            {
                return true;
            }
        }
        return false;
    }
}

Polynomyal Polynomyal::operator+(const Polynomyal& other)
{
    Polynomyal temp;
    if (temp.polynomyal.size() != 0)
    {
        while (temp.polynomyal.size() != 0)
        {
            temp.polynomyal.pop_back();
        }
    }
    if (temp.constanta != 0)
    {
        temp.constanta = 0;
    }
    temp.constanta = this->constanta + other.constanta;
    for (int i = 0; i < this->polynomyal.size(); i++)
    {
        temp.add(this->polynomyal[i].first, this->polynomyal[i].second);
    }
    for (int j = 0; j < other.polynomyal.size(); j++)
    {
        temp.add(other.polynomyal[j].first, other.polynomyal[j].second);
    }
    return temp;
}

Polynomyal Polynomyal::operator-(const Polynomyal& other)
{
    Polynomyal temp;
    if (temp.polynomyal.size() != 0)
    {
        while (temp.polynomyal.size() != 0)
        {
            temp.polynomyal.pop_back();
        }
    }
    if (temp.constanta != 0)
    {
        temp.constanta = 0;
    }
    temp.constanta = this->constanta - other.constanta;
    for (int i = 0; i < this->polynomyal.size(); i++)
    {
        temp.add(this->polynomyal[i].first, this->polynomyal[i].second);
    }
    for (int i = 0; i < other.polynomyal.size(); i++)
    {
        Variable tempVar = other.polynomyal[i].second;
        bool flag = true;
        for (int j = 0; j < temp.polynomyal.size(); j++)
        {
            if (tempVar == temp.polynomyal[j].second)
            {
                temp.polynomyal[j].first = temp.polynomyal[j].first - other.polynomyal[j].first;
                flag = false;
            }
        }
        if (flag)
        {
            temp.add(-(other.polynomyal[i].first), tempVar);
        }
    }
    return temp;
}

Polynomyal& Polynomyal::operator+=(const Polynomyal& other)
{
    this->constanta = this->constanta + other.constanta;
    for (int j = 0; j < other.polynomyal.size(); j++)
    {
        this->add(other.polynomyal[j].first, other.polynomyal[j].second);
    }
    return *this;
}

Polynomyal& Polynomyal::operator-=(const Polynomyal& other)
{
    this->constanta = this->constanta - other.constanta;
    for (int i = 0; i < other.polynomyal.size(); i++)
    {
        Variable tempVar = other.polynomyal[i].second;
        bool flag = true;
        for (int j = 0; j < this->polynomyal.size(); j++)
        {
            if (tempVar == this->polynomyal[j].second)
            {
                this->polynomyal[j].first = this->polynomyal[j].first - other.polynomyal[j].first;
                flag = false;
            }
        }
        if (flag)
        {
            this->add(-(other.polynomyal[i].first), tempVar);
        }
    }
    return *this;
}

void Polynomyal::add(int newConst, Variable newVar)
{
    this->polynomyal.push_back(std::make_pair(newConst, newVar));
    for (int i = 0; i < this->polynomyal.size() - 1; i++)
    {
        if (newVar == this->polynomyal[i].second)
        {
            this->polynomyal.pop_back();
            this->polynomyal[i].first = this->polynomyal[i].first + newConst;
        }
    }
}

Polynomyal& Polynomyal::operator++()
{
    for (int i = 0; i < this->polynomyal.size(); i++)
    {
        this->polynomyal[i].first++;
    }
    this->constanta++;
    return *this;
}

Polynomyal& Polynomyal::operator++(int value)
{
    Polynomyal temp;
    if (temp.constanta != 0)
    {
        temp.constanta = 0;
    }
    if (temp.polynomyal.size() != 0)
    {
        while (temp.polynomyal.size() != 0)
        {
            temp.polynomyal.pop_back();
        }
    }
    for (int i = 0; i < this->polynomyal.size(); i++)
    {
        temp.polynomyal.push_back(this->polynomyal[i]);
    }
    temp.constanta = this->constanta;

    for (int i = 0; i < this->polynomyal.size(); i++)
    {
        this->polynomyal[i].first++;
    }
    this->constanta++;

    return temp;
}

Polynomyal& Polynomyal::operator--()
{
    for (int i = 0; i < this->polynomyal.size(); i++)
    {
        this->polynomyal[i].first--;
    }
    this->constanta--;
    return *this;
}

Polynomyal& Polynomyal::operator--(int value)
{
    Polynomyal temp;
    if (temp.constanta != 0)
    {
        temp.constanta = 0;
    }
    if (temp.polynomyal.size() != 0)
    {
        while (temp.polynomyal.size() != 0)
        {
            temp.polynomyal.pop_back();
        }
    }
    for (int i = 0; i < this->polynomyal.size(); i++)
    {
        temp.polynomyal.push_back(this->polynomyal[i]);
    }
    temp.constanta = this->constanta;

    for (int i = 0; i < this->polynomyal.size(); i++)
    {
        this->polynomyal[i].first--;
    }
    this->constanta--;

    return temp;
}

Polynomyal Polynomyal::operator*(const Polynomyal& other)
{
    Polynomyal temp;
    if (temp.polynomyal.size() != 0)
    {
        while (temp.polynomyal.size() != 0)
        {
            temp.polynomyal.pop_back();
        }
    }
    if (temp.constanta!= 0)
    {
        temp.constanta = 0;
    }

    for (int i = 0; i < other.polynomyal.size(); i++)
    {
        Variable tempVar = other.polynomyal[i].second;
        for (int j = 0; j < this->polynomyal.size(); j++)
        {
            if (tempVar == this->polynomyal[j].second)
            {
                Variable newVar(this->polynomyal[j].second.GetDegree() * 2, this->polynomyal[j].second.GetVariable());
                temp.add(other.polynomyal[i].first * this->polynomyal[j].first, newVar);
            }
            else
            {
                Variable newVar(this->polynomyal[j].second.GetDegree() * tempVar.GetDegree(), this->polynomyal[j].second.GetVariable());
                newVar.add(tempVar.GetVariable()[0]);
                temp.add(other.polynomyal[i].first * this->polynomyal[j].first, newVar);
            }
        }
    }
    for (int i = 0; i < other.polynomyal.size(); i++)
    {
        Variable tempVar = other.polynomyal[i].second;
        temp.add(other.polynomyal[i].first * this->constanta, tempVar);
    }
    temp.constanta = other.constanta * this->constanta;
    return temp;
}

Polynomyal& Polynomyal::operator/(int value)
{
    this->constanta = this->constanta / value;
    for (int i = 0; i < this->polynomyal.size(); i++)
    {
        this->polynomyal[i].first = this->polynomyal[i].first / value;
    }
    return *this;
}

Polynomyal& Polynomyal::operator*=(const Polynomyal& other)
{
    Polynomyal temp;
    if (temp.polynomyal.size() != 0)
    {
        while (temp.polynomyal.size() != 0)
        {
            temp.polynomyal.pop_back();
        }
    }
    if (temp.constanta != 0)
    {
        temp.constanta = 0;
    }

    for (int i = 0; i < this->polynomyal.size(); i++)
    {
        temp.add(this->polynomyal[i].first, this->polynomyal[i].second);
    }
    temp.constanta = this->constanta;

    while (this->polynomyal.size() != 0)
    {
        this->polynomyal.pop_back();
    }
    this->constanta = 0;

    for (int i = 0; i < other.polynomyal.size(); i++)
    {
        Variable tempVar = other.polynomyal[i].second;
        for (int j = 0; j < temp.polynomyal.size(); j++)
        {
            if (tempVar == temp.polynomyal[j].second)
            {
                Variable newVar(temp.polynomyal[j].second.GetDegree() * 2, temp.polynomyal[j].second.GetVariable());
                this->add(other.polynomyal[i].first * temp.polynomyal[j].first, newVar);
            }
            else
            {
                Variable newVar(temp.polynomyal[j].second.GetDegree() * tempVar.GetDegree(), temp.polynomyal[j].second.GetVariable());
                newVar.add(tempVar.GetVariable()[0]);
                this->add(other.polynomyal[i].first * temp.polynomyal[j].first, newVar);
            }
        }
    }
    for (int i = 0; i < other.polynomyal.size(); i++)
    {
        Variable TEMP = other.polynomyal[i].second;
        this->add(other.polynomyal[i].first * temp.constanta, TEMP);
    }
    this->constanta = other.constanta * temp.constanta;
    return *this;
}

Polynomyal& Polynomyal::operator/=(int value)
{
    for (int i = 0; i < this->polynomyal.size(); i++)
    {
        this->polynomyal[i].first /= value;
    }
    this->constanta /= value;
    return *this;
}

std::istream& Polynomyal::operator>>(std::istream& s)
{
    std::string var;
    int degree;
    int constVar;
    std::cout << "Enter VAR:\n";
    std::cin >> var;
    std::cout << "Enter DEGREE:\n";
    std::cin >> degree;
    std::cout << "Enter CONST:\n";
    std::cin >> constVar;
    std::cout << "\n";
    Variable newVar(degree, var);
    this->add(constVar, newVar);
    return s;
}

std::ostream& Polynomyal::operator<<(std::ostream& s)
{
    for (int i = 0; i < polynomyal.size(); i++)
    {
        std::cout << polynomyal[i].first;
        polynomyal[i].second.print();
        if (i < polynomyal.size() - 1)
        {
            std::cout << " + ";
        }
    }
    if (this->constanta != 0)
    {
        std::cout << " + " << constanta;
    }
    std::cout << '\n';
    return s;
}