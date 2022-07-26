#include "Variable.h"

Variable::Variable()
{
    degree = 0;
    variable = 'x';
}

Variable::Variable(const Variable& other)
{
    this->degree = other.degree;
    this->variable = other.variable;
}

Variable::Variable(int newDegree, std::basic_string<char, std::char_traits<char>, std::allocator<char>> newVariable)
{
    this->variable = newVariable;
    this->degree = newDegree;
}

Variable::~Variable()
{
    this->degree = NULL;
}

void Variable::print()
{
    for (int i = 0; i < this->variable.size(); i++)
    {
        std::cout << this->variable[i] << '^' << this->degree;
    }
}

void Variable::SetDegree(int newDegree)
{
    degree = newDegree;
}

void Variable::SetVariable(char newVariable)
{
    variable = newVariable;
}

int Variable::GetDegree()
{
    return degree;
}

std::string Variable::GetVariable()
{
    return variable;
}

Variable& Variable::operator=(const Variable& other)
{
    this->variable = other.variable;
    this->degree = other.degree;
    return *this;
}

bool Variable::operator==(const Variable& other)
{
    return this->degree == other.degree && this->variable == other.variable;
}

bool Variable::operator!=(const Variable& other)
{
    return this->degree != other.degree && this->variable != other.variable;
}

void Variable::add(char value)
{
    this->variable.push_back(value);
}

std::istream& Variable::operator>>(std::istream& s)
{
    std::cout << "Enter degree and variable:\n";
    std::cin >> this->degree >> this->variable;
    std::cout << "\n";
    return s;
}