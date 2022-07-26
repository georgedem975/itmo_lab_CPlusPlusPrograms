#include <glfw3.h>
#include <Windows.h>
#include <iostream>
#include <fstream>

struct Coordinate
{
	float x;
	float y;
	float z;
};

enum Color
{
	white,
	red,
	green,
	blue,
	yellow,
	purple
};

class Cube
{
public:
	Cube();
	Cube(float newDistance);
	Cube(float newDistance, float newCx, float newCy, float newCz);
	~Cube();
	void print();
	void showColor(Color sideColor);
	void rotateR(int grad);
	void rotateL(int grad);
	void rotateU(int grad);
	void rotateD(int grad);
	void R();
	void L();
	void U();
	void D();
	bool isTrueCube();

private:
	float distance;
	Coordinate distanceCoordinate;
	Color top;
	Color bottom;
	Color right;
	Color left;
	Color before;
	Color back;
};