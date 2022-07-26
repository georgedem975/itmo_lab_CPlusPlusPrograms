#pragma once

#include <iostream>
#include <locale.h>
#include <string>
#include <vector>

class Variable
{
public:
    Variable();
    Variable(int newDegree, std::basic_string<char, std::char_traits<char>, std::allocator<char>> newVariable);
    Variable(const Variable& other);
    ~Variable();
    void print();
    void SetDegree(int newDegree);
    void SetVariable(char newVariable);
    int GetDegree();
    std::string GetVariable();
    Variable& operator = (const Variable& other);
    bool operator == (const Variable& other);
    bool operator != (const Variable& other);
    void add(char value);
    std::istream& operator >> (std::istream& s);
private:
    int degree;
    std::string variable;
};