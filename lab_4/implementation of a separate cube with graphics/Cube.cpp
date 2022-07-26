#include "Cube.h"

Cube::Cube()
{
	this->distance = 0.5;
	this->distanceCoordinate.x = 0.0;
	this->distanceCoordinate.y = 0.0;
	this->distanceCoordinate.z = 0.0;
	this->top = white;
	this->bottom = red;
	this->right = green;
	this->left = blue;
	this->before = yellow;
	this->back = purple;
}

Cube::Cube(float newDistance) : Cube()
{
	this->distance = newDistance;
}

Cube::Cube(float newDistance, float newCx, float newCy, float newCz) : Cube(newDistance)
{
	this->distanceCoordinate.x = newCx;
	this->distanceCoordinate.y = newCy;
	this->distanceCoordinate.z = newCz;
}

Cube::~Cube()
{
	this->distance = NULL;
	this->distanceCoordinate.x = NULL;
	this->distanceCoordinate.y = NULL;
	this->distanceCoordinate.z = NULL;
}

void Cube::print()
{
	glBegin(GL_QUADS);
	showColor(top);
	glVertex3f(-this->distance, -this->distance, this->distance);
	glVertex3f(this->distance, -this->distance, this->distance);
	glVertex3f(this->distance, this->distance, this->distance);
	glVertex3f(-this->distance, this->distance, this->distance);
	glEnd();

	glBegin(GL_QUADS);
	showColor(bottom);
	glVertex3f(-this->distance, -this->distance, -this->distance);
	glVertex3f(this->distance, -this->distance, -this->distance);
	glVertex3f(this->distance, this->distance, -this->distance);
	glVertex3f(-this->distance, this->distance, -this->distance);
	glEnd();

	glBegin(GL_QUADS);
	showColor(right);
	glVertex3f(this->distance, -this->distance, this->distance);
	glVertex3f(this->distance, -this->distance, -this->distance);
	glVertex3f(this->distance, this->distance, -this->distance);
	glVertex3f(this->distance, this->distance, this->distance);
	glEnd();

	glBegin(GL_QUADS);
	showColor(left);
	glVertex3f(-this->distance, -this->distance, this->distance);
	glVertex3f(-this->distance, -this->distance, -this->distance);
	glVertex3f(-this->distance, this->distance, -this->distance);
	glVertex3f(-this->distance, this->distance, this->distance);
	glEnd();

	glBegin(GL_QUADS);
	showColor(before);
	glVertex3f(-this->distance, this->distance, this->distance);
	glVertex3f(this->distance, this->distance, this->distance);
	glVertex3f(this->distance, this->distance, -this->distance);
	glVertex3f(-this->distance, this->distance, -this->distance);
	glEnd();

	glBegin(GL_QUADS);
	showColor(back);
	glVertex3f(-this->distance, -this->distance, this->distance);
	glVertex3f(this->distance, -this->distance, this->distance);
	glVertex3f(this->distance, -this->distance, -this->distance);
	glVertex3f(-this->distance, -this->distance, -this->distance);
	glEnd();
}

void Cube::showColor(Color sideColor)
{
	switch (sideColor)
	{
	case white:
		glColor3f(1.0f, 1.0f, 1.0f);
		break;
	case red:
		glColor3f(1.0f, 0.0f, 0.0f);
		break;
	case green:
		glColor3f(0.0f, 1.0f, 0.0f);
		break;
	case blue:
		glColor3f(0.0f, 0.0f, 1.0f);
		break;
	case yellow:
		glColor3f(1.0f, 1.0f, 0.0f);
		break;
	case purple:
		glColor3f(1.0f, 0.0f, 1.0f);
		break;
	default:
		break;
	}
}

bool Cube::isTrueCube()
{
	if (this->top == this->bottom || this->top == this->right || this->top == this->left
		|| this->top == this->before || this->top == this->back)
	{
		return false;
	}
	else if (this->bottom == this->right || this->bottom == this->left ||
		this->bottom == this->before || this->bottom == this->back)
	{
		return false;
	}
	else if (this->right == this->left || this->right == this->before ||
		this->right == this->back)
	{
		return false;
	}
	else if (this->left == this->before || this->left == this->back ||
		this->before == this->back)
	{
		return false;
	}
	return true;
}

void Cube::rotateR(int grad)
{
	glPushMatrix();
	glRotatef(-grad, 0, 1, 0);
	this->print();
	Sleep(10);
	glPopMatrix();
}

void Cube::R()
{
	Color temp = this->bottom;
	this->bottom = this->left;
	this->left = this->before;
	this->before = this->right;
	this->right = temp;
}

void Cube::rotateL(int grad)
{
	glPushMatrix();
	glRotatef(grad, 0, 1, 0);
	this->print();
	Sleep(10);
	glPopMatrix();
}

void Cube::L()
{
	Color temp = this->bottom;
	this->bottom = this->right;
	this->right = this->before;
	this->before = this->left;
	this->left = temp;
}

void Cube::rotateU(int grad)
{
	glPushMatrix();
	glRotatef(grad, 1, 0, 0);
	this->print();
	Sleep(10);
	glPopMatrix();
}

void Cube::U()
{
	Color temp = this->bottom;
	this->bottom = this->back;
	this->back = this->before;
	this->before = this->top;
	this->top = temp;
}

void Cube::rotateD(int grad)
{
	glPushMatrix();
	glRotatef(-grad, 1, 0, 0);
	this->print();
	Sleep(10);
	glPopMatrix();
}

void Cube::D()
{
	Color temp = this->bottom;
	this->bottom = this->before;
	this->before = this->top;
	this->top = this->back;
	this->back = temp;
}