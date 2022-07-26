#pragma once

#include "Variable.h"

class Polynomyal
{
public:
    Polynomyal();
    Polynomyal(std::string polynom);
    Polynomyal(const Polynomyal& other);
    ~Polynomyal();
    int stringToInt(std::string value);
    void print();
    void add(int newConst, Variable newVar);
    Polynomyal& operator = (const Polynomyal& other);
    bool operator == (const Polynomyal& other);
    bool operator != (const Polynomyal& other);
    Polynomyal operator + (const Polynomyal& other);
    Polynomyal operator - (const Polynomyal& other);
    Polynomyal& operator += (const Polynomyal& other);
    Polynomyal& operator -= (const Polynomyal& other);
    Polynomyal& operator ++ ();
    Polynomyal& operator ++ (int value);
    Polynomyal& operator -- ();
    Polynomyal& operator -- (int value);
    Polynomyal  operator * (const Polynomyal& other);
    Polynomyal& operator / (int value);
    Polynomyal& operator *= (const Polynomyal& other);
    Polynomyal& operator /= (int value);
    std::istream& operator >> (std::istream& s);
    std::ostream& operator << (std::ostream& s);
    void operator [] (int index);
    void print(int id);
private:
    std::vector<std::pair<int, Variable>> polynomyal;
    int constanta = 0;
};