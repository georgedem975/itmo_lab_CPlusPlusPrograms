#include "VisualCubicRubic.h"
#include <iostream>
#include <queue>
#include <string>
#include <Windows.h>

std::string waysss = "";
bool flagOfVCubicRubicIsTrue = 1;
void rubicBfs(visualCubicRubic::VisualCubicRubic newCubicForBfs, std::string& way);

void rubicBfs(visualCubicRubic::VisualCubicRubic newCubicForBfs, std::string& way)
{
	if (newCubicForBfs.isTrue())
	{
		flagOfVCubicRubicIsTrue = 0;
	}
	std::queue<visualCubicRubic::VisualCubicRubic> Queue;
	Queue.push(newCubicForBfs);
	while (flagOfVCubicRubicIsTrue && !Queue.empty())
	{
		visualCubicRubic::VisualCubicRubic temp;
		temp = Queue.front();
		Queue.pop();
		
		visualCubicRubic::VisualCubicRubic newR;
		newR = temp;
		newR.rotateR();
		newR.way = temp.way;
		newR.way.push_back('R');
		Queue.push(newR);
		if (newR.isTrue())
		{
			flagOfVCubicRubicIsTrue = 0;
			way = newR.way;
		}
		
		visualCubicRubic::VisualCubicRubic newR_;
		newR_ = temp;
		newR_.rotateR_();
		newR_.way = temp.way;
		newR_.way.push_back('R');
		newR_.way.push_back('_');
		if (newR_.isTrue())
		{
			flagOfVCubicRubicIsTrue = 0;
			way = newR_.way;
		}
		Queue.push(newR_);
		
		visualCubicRubic::VisualCubicRubic newL;
		newL = temp;
		newL.rotateL();
		newL.way = temp.way;
		newL.way.push_back('L');
		if (newL.isTrue())
		{
			flagOfVCubicRubicIsTrue = 0;
			way = newL.way;
		}
		Queue.push(newL);
		
		visualCubicRubic::VisualCubicRubic newL_;
		newL_ = temp;
		newL_.rotateL_();
		newL_.way = temp.way;
		newL_.way.push_back('L');
		newL_.way.push_back('_');
		if (newL_.isTrue())
		{
			flagOfVCubicRubicIsTrue = 0;
			way = newL_.way;
		}
		Queue.push(newL_);
		
		visualCubicRubic::VisualCubicRubic newF;
		newF = temp;
		newF.rotateF();
		newF.way = temp.way;
		newF.way.push_back('F');
		if (newF.isTrue())
		{
			flagOfVCubicRubicIsTrue = 0;
			way = newF.way;
		}
		Queue.push(newF);
		
		visualCubicRubic::VisualCubicRubic newF_;
		newF_ = temp;
		newF_.rotateF_();
		newF_.way = temp.way;
		newF_.way.push_back('F');
		newF_.way.push_back('_');
		if (newF_.isTrue())
		{
			flagOfVCubicRubicIsTrue = 0;
			way = newF_.way;
		}
		Queue.push(newF_);
		
		visualCubicRubic::VisualCubicRubic newB;
		newB = temp;
		newB.rotateB();
		newB.way = temp.way;
		newB.way.push_back('B');
		if (newB.isTrue())
		{
			flagOfVCubicRubicIsTrue = 0;
			way = newB.way;
		}
		Queue.push(newB);
		
		visualCubicRubic::VisualCubicRubic newB_;
		newB_ = temp;
		newB_.rotateB_();
		newB_.way = temp.way;
		newB_.way.push_back('B');
		newB_.way.push_back('_');
		if (newB_.isTrue())
		{
			flagOfVCubicRubicIsTrue = 0;
			way = newB_.way;
		}
		Queue.push(newB_);
		
		visualCubicRubic::VisualCubicRubic newU;
		newU = temp;
		newU.rotateU();
		newU.way = temp.way;
		newU.way.push_back('U');
		if (newU.isTrue())
		{
			flagOfVCubicRubicIsTrue = 0;
			way = newU.way;
		}
		Queue.push(newU);
		
		visualCubicRubic::VisualCubicRubic newU_;
		newU_ = temp;
		newU_.rotateU_();
		newU_.way = temp.way;
		newU_.way.push_back('U');
		newU_.way.push_back('_');
		if (newU_.isTrue())
		{
			flagOfVCubicRubicIsTrue = 0;
			way = newU_.way;
		}
		Queue.push(newU_);
		
		visualCubicRubic::VisualCubicRubic newD;
		newD = temp;
		newD.rotateD();
		newD.way = temp.way;
		newD.way.push_back('D');
		if (newD.isTrue())
		{
			flagOfVCubicRubicIsTrue = 0;
			way = newD.way;
		}
		Queue.push(newD);
		
		visualCubicRubic::VisualCubicRubic newD_;
		newD_ = temp;
		newD_.rotateD_();
		newD_.way = temp.way;
		newD_.way.push_back('D');
		newD_.way.push_back('_');
		if (newD_.isTrue())
		{
			flagOfVCubicRubicIsTrue = 0;
			way = newD_.way;
		}
		Queue.push(newD_);
	}
}

namespace visualCubicRubic
{
	float colorWhite[3] = { 1, 1, 1 };
	float colorYellow[3] = { 1, 1, 0 };
	float colorGreen[3] = { 0, 0.8, 0.3 };
	float colorBlue[3] = { 0, 0, 1 };
	float colorOrange[3] = { 1, 0.4, 0.1 };
	float colorRed[3] = { 1, 0, 0 };

	cubic::cubic()
	{
		this->f = not_found;
		this->f_ = not_found;
		this->u = not_found;
		this->u_ = not_found;
		this->r = not_found;
		this->l = not_found;
	}

	void cubic::operator = (const cubic& other)
	{
		this->f = not_found;
		this->f_ = not_found;
		this->u = not_found;
		this->u_ = not_found;
		this->r = not_found;
		this->l = not_found;

		this->f = other.f;
		this->f_ = other.f_;
		this->u = other.u;
		this->u_ = other.u_;
		this->r = other.r;
		this->l = other.l;
	}

	cubic::~cubic()
	{

	}

	void cubic::print()
	{
		if (this->f != not_found)
		{
			glBegin(GL_QUADS);
			this->printF_color();
			glVertex3f(this->x_l + 0.02, this->y_u - 0.02, this->z_f);
			glVertex3f(this->x_r - 0.02, this->y_u - 0.02, this->z_f);
			glVertex3f(this->x_r - 0.02, this->y_d + 0.02, this->z_f);
			glVertex3f(this->x_l + 0.02, this->y_d + 0.02, this->z_f);
			glEnd();

			glBegin(GL_QUADS);
			glColor3f(0, 0, 0);
			glVertex3f(this->x_l, this->y_u, this->z_f - 0.001);
			glVertex3f(this->x_r, this->y_u, this->z_f - 0.001);
			glVertex3f(this->x_r, this->y_d, this->z_f - 0.001);
			glVertex3f(this->x_l, this->y_d, this->z_f - 0.001);
			glEnd();
		}
		if (this->f_ != not_found)
		{
			glBegin(GL_QUADS);
			this->printF__color();
			glVertex3f(this->x_l + 0.02, this->y_u - 0.02, this->z_b);
			glVertex3f(this->x_r - 0.02, this->y_u - 0.02, this->z_b);
			glVertex3f(this->x_r - 0.02, this->y_d + 0.02, this->z_b);
			glVertex3f(this->x_l + 0.02, this->y_d + 0.02, this->z_b);
			glEnd();

			glBegin(GL_QUADS);
			glColor3f(0, 0, 0);
			glVertex3f(this->x_l, this->y_u, this->z_b + 0.001);
			glVertex3f(this->x_r, this->y_u, this->z_b + 0.001);
			glVertex3f(this->x_r, this->y_d, this->z_b + 0.001);
			glVertex3f(this->x_l, this->y_d, this->z_b + 0.001);
			glEnd();
		}
		if (this->u != not_found)
		{
			glBegin(GL_QUADS);
			this->printU_color();
			glVertex3f(this->x_l + 0.02, this->y_u, this->z_b + 0.02);
			glVertex3f(this->x_r - 0.02, this->y_u, this->z_b + 0.02);
			glVertex3f(this->x_r - 0.02, this->y_u, this->z_f - 0.02);
			glVertex3f(this->x_l + 0.02, this->y_u, this->z_f - 0.02);
			glEnd();

			glBegin(GL_QUADS);
			glColor3f(0, 0, 0);
			glVertex3f(this->x_l, this->y_u - 0.001, this->z_b);
			glVertex3f(this->x_r, this->y_u - 0.001, this->z_b);
			glVertex3f(this->x_r, this->y_u - 0.001, this->z_f);
			glVertex3f(this->x_l, this->y_u - 0.001, this->z_f);
			glEnd();
		}
		if (this->u_ != not_found)
		{
			glBegin(GL_QUADS);
			this->printU__color();
			glVertex3f(this->x_l + 0.02, this->y_d, this->z_b + 0.02);
			glVertex3f(this->x_r - 0.02, this->y_d, this->z_b + 0.02);
			glVertex3f(this->x_r - 0.02, this->y_d, this->z_f - 0.02);
			glVertex3f(this->x_l + 0.02, this->y_d, this->z_f - 0.02);
			glEnd();

			glBegin(GL_QUADS);
			glColor3f(0, 0, 0);
			glVertex3f(this->x_l, this->y_d + 0.001, this->z_b);
			glVertex3f(this->x_r, this->y_d + 0.001, this->z_b);
			glVertex3f(this->x_r, this->y_d + 0.001, this->z_f);
			glVertex3f(this->x_l, this->y_d + 0.001, this->z_f);
			glEnd();
		}
		if (this->r != not_found)
		{
			glBegin(GL_QUADS);
			this->printR_color();
			glVertex3f(this->x_r, this->y_u - 0.02, this->z_b + 0.02);
			glVertex3f(this->x_r, this->y_d + 0.02, this->z_b + 0.02);
			glVertex3f(this->x_r, this->y_d + 0.02, this->z_f - 0.02);
			glVertex3f(this->x_r, this->y_u - 0.02, this->z_f - 0.02);
			glEnd();

			glBegin(GL_QUADS);
			glColor3f(0, 0, 0);
			glVertex3f(this->x_r - 0.001, this->y_u, this->z_b);
			glVertex3f(this->x_r - 0.001, this->y_d, this->z_b);
			glVertex3f(this->x_r - 0.001, this->y_d, this->z_f);
			glVertex3f(this->x_r - 0.001, this->y_u, this->z_f);
			glEnd();
		}
		if (this->l != not_found)
		{
			glBegin(GL_QUADS);
			this->printL_color();
			glVertex3f(this->x_l, this->y_u - 0.02, this->z_b + 0.02);
			glVertex3f(this->x_l, this->y_d + 0.02, this->z_b + 0.02);
			glVertex3f(this->x_l, this->y_d + 0.02, this->z_f - 0.02);
			glVertex3f(this->x_l, this->y_u - 0.02, this->z_f - 0.02);
			glEnd();

			glBegin(GL_QUADS);
			glColor3f(0, 0, 0);
			glVertex3f(this->x_l + 0.001, this->y_u, this->z_b);
			glVertex3f(this->x_l + 0.001, this->y_d, this->z_b);
			glVertex3f(this->x_l + 0.001, this->y_d, this->z_f);
			glVertex3f(this->x_l + 0.001, this->y_u, this->z_f);
			glEnd();
		}
	}

	void cubic::printF_color()
	{
		switch (this->f)
		{
		case white:
			glColor3f(colorWhite[0], colorWhite[1], colorWhite[2]);
			break;
		case yellow:
			glColor3f(colorYellow[0], colorYellow[1], colorYellow[2]);
			break;
		case green:
			glColor3f(colorGreen[0], colorGreen[1], colorGreen[2]);
			break;
		case blue:
			glColor3f(colorBlue[0], colorBlue[1], colorBlue[2]);
			break;
		case orange:
			glColor3f(colorOrange[0], colorOrange[1], colorOrange[2]);
			break;
		case red:
			glColor3f(colorRed[0], colorRed[1], colorRed[2]);
			break;
		default:
			break;
		}
	}

	void cubic::printF__color()
	{
		switch (this->f_)
		{
		case white:
			glColor3f(colorWhite[0], colorWhite[1], colorWhite[2]);
			break;
		case yellow:
			glColor3f(colorYellow[0], colorYellow[1], colorYellow[2]);
			break;
		case green:
			glColor3f(colorGreen[0], colorGreen[1], colorGreen[2]);
			break;
		case blue:
			glColor3f(colorBlue[0], colorBlue[1], colorBlue[2]);
			break;
		case orange:
			glColor3f(colorOrange[0], colorOrange[1], colorOrange[2]);
			break;
		case red:
			glColor3f(colorRed[0], colorRed[1], colorRed[2]);
			break;
		default:
			break;
		}
	}

	void cubic::printU_color()
	{
		switch (this->u)
		{
		case white:
			glColor3f(colorWhite[0], colorWhite[1], colorWhite[2]);
			break;
		case yellow:
			glColor3f(colorYellow[0], colorYellow[1], colorYellow[2]);
			break;
		case green:
			glColor3f(colorGreen[0], colorGreen[1], colorGreen[2]);
			break;
		case blue:
			glColor3f(colorBlue[0], colorBlue[1], colorBlue[2]);
			break;
		case orange:
			glColor3f(colorOrange[0], colorOrange[1], colorOrange[2]);
			break;
		case red:
			glColor3f(colorRed[0], colorRed[1], colorRed[2]);
			break;
		default:
			break;
		}
	}

	void cubic::printU__color()
	{
		switch (this->u_)
		{
		case white:
			glColor3f(colorWhite[0], colorWhite[1], colorWhite[2]);
			break;
		case yellow:
			glColor3f(colorYellow[0], colorYellow[1], colorYellow[2]);
			break;
		case green:
			glColor3f(colorGreen[0], colorGreen[1], colorGreen[2]);
			break;
		case blue:
			glColor3f(colorBlue[0], colorBlue[1], colorBlue[2]);
			break;
		case orange:
			glColor3f(colorOrange[0], colorOrange[1], colorOrange[2]);
			break;
		case red:
			glColor3f(colorRed[0], colorRed[1], colorRed[2]);
			break;
		default:
			break;
		}
	}

	void cubic::printR_color()
	{
		switch (this->r)
		{
		case white:
			glColor3f(colorWhite[0], colorWhite[1], colorWhite[2]);
			break;
		case yellow:
			glColor3f(colorYellow[0], colorYellow[1], colorYellow[2]);
			break;
		case green:
			glColor3f(colorGreen[0], colorGreen[1], colorGreen[2]);
			break;
		case blue:
			glColor3f(colorBlue[0], colorBlue[1], colorBlue[2]);
			break;
		case orange:
			glColor3f(colorOrange[0], colorOrange[1], colorOrange[2]);
			break;
		case red:
			glColor3f(colorRed[0], colorRed[1], colorRed[2]);
			break;
		default:
			break;
		}
	}

	void cubic::printL_color()
	{
		switch (this->l)
		{
		case white:
			glColor3f(colorWhite[0], colorWhite[1], colorWhite[2]);
			break;
		case yellow:
			glColor3f(colorYellow[0], colorYellow[1], colorYellow[2]);
			break;
		case green:
			glColor3f(colorGreen[0], colorGreen[1], colorGreen[2]);
			break;
		case blue:
			glColor3f(colorBlue[0], colorBlue[1], colorBlue[2]);
			break;
		case orange:
			glColor3f(colorOrange[0], colorOrange[1], colorOrange[2]);
			break;
		case red:
			glColor3f(colorRed[0], colorRed[1], colorRed[2]);
			break;
		default:
			break;
		}
	}

	void cubic::SetColor(color newColor, int mode)
	{
		switch (mode)
		{
		case 0:
			this->u = newColor;
			break;
		case 1:
			this->u_ = newColor;
			break;
		case 2:
			this->f = newColor;
			break;
		case 3:
			this->f_ = newColor;
			break;
		case 4:
			this->r = newColor;
			break;
		case 5:
			this->l = newColor;
			break;
		default:
			break;
		}
	}

	color cubic::GetColorf()
	{
		return this->f;
	}

	color cubic::GetColorf_()
	{
		return this->f_;
	}

	color cubic::GetColoru()
	{
		return this->u;
	}

	color cubic::GetColoru_()
	{
		return this->u_;
	}

	color cubic::GetColorr()
	{
		return this->r;
	}

	color cubic::GetColorl()
	{
		return this->l;
	}

	float cubic::Get_x_l()
	{
		return this->x_l;
	}

	float cubic::Get_x_r()
	{
		return this->x_r;
	}

	float cubic::Get_y_d()
	{
		return this->y_d;
	}

	float cubic::Get_y_u()
	{
		return this->y_u;
	}

	float cubic::Get_z_b()
	{
		return this->z_b;
	}

	float cubic::Get_z_f()
	{
		return this->z_f;
	}

	void cubic::Set_vert(float new_x_r, float new_x_l, float new_y_d, float new_y_u, float new_z_f, float new_z_b)
	{
		this->x_r = new_x_r;
		this->x_l = new_x_l;
		this->y_d = new_y_d;
		this->y_u = new_y_u;
		this->z_b = new_z_b;
		this->z_f = new_z_f;
	}

	VisualCubicRubic::VisualCubicRubic()
	{
		this->helpCreation(2, 2, 0, 0, white);
		this->helpCreation(2, 2, 2, 1, yellow);
		this->helpCreation(2, 2, 0, 2, green);
		this->helpCreation(2, 2, 2, 3, blue);
		this->helpCreation(2, 2, 2, 4, red);
		this->helpCreation(2, 2, 0, 5, orange);
		
		this->matrix[0][0][0].Set_vert(-0.1, -0.3, 0.1, 0.3, 0.3, 0.1);
		this->matrix[0][1][0].Set_vert(0.1, -0.1, 0.1, 0.3, 0.3, 0.1);
		this->matrix[0][2][0].Set_vert(0.3, 0.1, 0.1, 0.3, 0.3, 0.1);
		this->matrix[1][0][0].Set_vert(-0.1, -0.3, -0.1, 0.1, 0.3, 0.1);
		this->matrix[1][1][0].Set_vert(0.1, -0.1, -0.1, 0.1, 0.3, 0.1);
		this->matrix[1][2][0].Set_vert(0.3, 0.1, -0.1, 0.1, 0.3, 0.1);
		this->matrix[2][0][0].Set_vert(-0.1, -0.3, -0.3, -0.1, 0.3, 0.1);
		this->matrix[2][1][0].Set_vert(0.1, -0.1, -0.3, -0.1, 0.3, 0.1);
		this->matrix[2][2][0].Set_vert(0.3, 0.1, -0.3, -0.1, 0.3, 0.1);
		
		this->matrix[0][0][1].Set_vert(-0.1, -0.3, 0.1, 0.3, 0.1, -0.1);
		this->matrix[0][1][1].Set_vert(0.1, -0.1, 0.1, 0.3, 0.1, -0.1);
		this->matrix[0][2][1].Set_vert(0.3, 0.1, 0.1, 0.3, 0.1, -0.1);
		this->matrix[1][0][1].Set_vert(-0.1, -0.3, -0.1, 0.1, 0.1, -0.1);
		this->matrix[1][1][1].Set_vert(0.1, -0.1, -0.1, 0.1, 0.1, -0.1);
		this->matrix[1][2][1].Set_vert(0.3, 0.1, -0.1, 0.1, 0.1, -0.1);
		this->matrix[2][0][1].Set_vert(-0.1, -0.3, -0.3, -0.1, 0.1, -0.1);
		this->matrix[2][1][1].Set_vert(0.1, -0.1, -0.3, -0.1, 0.1, -0.1);
		this->matrix[2][2][1].Set_vert(0.3, 0.1, -0.3, -0.1, 0.1, -0.1);
		
		this->matrix[0][0][2].Set_vert(-0.1, -0.3, 0.1, 0.3, -0.1, -0.3);
		this->matrix[0][1][2].Set_vert(0.1, -0.1, 0.1, 0.3, -0.1, -0.3);
		this->matrix[0][2][2].Set_vert(0.3, 0.1, 0.1, 0.3, -0.1, -0.3);
		this->matrix[1][0][2].Set_vert(-0.1, -0.3, -0.1, 0.1, -0.1, -0.3);
		this->matrix[1][1][2].Set_vert(0.1, -0.1, -0.1, 0.1, -0.1, -0.3);
		this->matrix[1][2][2].Set_vert(0.3, 0.1, -0.1, 0.1, -0.1, -0.3);
		this->matrix[2][0][2].Set_vert(-0.1, -0.3, -0.3, -0.1, -0.1, -0.3);
		this->matrix[2][1][2].Set_vert(0.1, -0.1, -0.3, -0.1, -0.1, -0.3);
		this->matrix[2][2][2].Set_vert(0.3, 0.1, -0.3, -0.1, -0.1, -0.3);
	}

	void cubic::exchangeForRotationR(const cubic& other)
	{
		this->f = not_found;
		this->f_ = not_found;
		this->u = not_found;
		this->u_ = not_found;
		this->r = not_found;
		this->l = not_found;
		this->f = other.u_;
		this->f_ = other.u;
		this->u = other.f;
		this->u_ = other.f_;
		this->r = other.r;
		this->l = other.l;
	}

	void cubic::exchangeForRotationR_(const cubic& other)
	{
		this->f = not_found;
		this->f_ = not_found;
		this->u = not_found;
		this->u_ = not_found;
		this->r = not_found;
		this->l = not_found;
		this->f = other.u;
		this->f_ = other.u_;
		this->u = other.f_;
		this->u_ = other.f;
		this->r = other.r;
		this->l = other.l;
	}

	void cubic::exchangeForRotationU(const cubic& other)
	{
		this->f = not_found;
		this->f_ = not_found;
		this->u = not_found;
		this->u_ = not_found;
		this->r = not_found;
		this->l = not_found;
		this->f = other.r;
		this->f_ = other.l;
		this->u = other.u;
		this->u_ = other.u_;
		this->r = other.f_;
		this->l = other.f;
	}

	void cubic::exchangeForRotationU_(const cubic& other)
	{
		this->f = not_found;
		this->f_ = not_found;
		this->u = not_found;
		this->u_ = not_found;
		this->r = not_found;
		this->l = not_found;
		this->f = other.l;
		this->f_ = other.r;
		this->u = other.u;
		this->u_ = other.u_;
		this->r = other.f;
		this->l = other.f_;
	}

	void cubic::exchangeForRotationF(const cubic& other)
	{
		this->f = not_found;
		this->f_ = not_found;
		this->u = not_found;
		this->u_ = not_found;
		this->r = not_found;
		this->l = not_found;
		this->f = other.f;
		this->f_ = other.f_;
		this->u = other.l;
		this->u_ = other.r;
		this->r = other.u;
		this->l = other.u_;
	}

	void cubic::exchangeForRotationF_(const cubic& other)
	{
		this->f = not_found;
		this->f_ = not_found;
		this->u = not_found;
		this->u_ = not_found;
		this->r = not_found;
		this->l = not_found;
		this->f = other.f;
		this->f_ = other.f_;
		this->u = other.r;
		this->u_ = other.l;
		this->r = other.u_;
		this->l = other.u;
	}

	void VisualCubicRubic::rotateR()
	{
		cubic tempOne;
		cubic tempTwo;
		tempOne = this->matrix[0][2][0];
		tempTwo = this->matrix[0][2][2];
		this->matrix[0][2][0].exchangeForRotationR(this->matrix[2][2][0]);
		this->matrix[0][2][2].exchangeForRotationR(tempOne);
		tempOne = this->matrix[2][2][2];
		this->matrix[2][2][2].exchangeForRotationR(tempTwo);
		this->matrix[2][2][0].exchangeForRotationR(tempOne);
		tempOne = this->matrix[1][2][0];
		tempTwo = this->matrix[0][2][1];
		this->matrix[1][2][0].exchangeForRotationR(this->matrix[2][2][1]);
		this->matrix[0][2][1].exchangeForRotationR(tempOne);
		tempOne = this->matrix[1][2][2];
		this->matrix[1][2][2].exchangeForRotationR(tempTwo);
		this->matrix[2][2][1].exchangeForRotationR(tempOne);
	}

	void VisualCubicRubic::rotateR_()
	{
		this->rotateR();
		this->rotateR();
		this->rotateR();
	}

	void VisualCubicRubic::rotateL()
	{
		this->rotateL_();
		this->rotateL_();
		this->rotateL_();
	}

	void VisualCubicRubic::rotateL_()
	{
		cubic tempOne;
		cubic tempTwo;
		tempOne = this->matrix[0][0][0];
		tempTwo = this->matrix[0][0][2];
		this->matrix[0][0][0].exchangeForRotationR(this->matrix[2][0][0]);
		this->matrix[0][0][2].exchangeForRotationR(tempOne);
		tempOne = this->matrix[2][0][2];
		this->matrix[2][0][2].exchangeForRotationR(tempTwo);
		this->matrix[2][0][0].exchangeForRotationR(tempOne);
		tempOne = this->matrix[1][0][0];
		tempTwo = this->matrix[0][0][1];
		this->matrix[1][0][0].exchangeForRotationR(this->matrix[2][0][1]);
		this->matrix[0][0][1].exchangeForRotationR(tempOne);
		tempOne = this->matrix[1][0][2];
		this->matrix[1][0][2].exchangeForRotationR(tempTwo);
		this->matrix[2][0][1].exchangeForRotationR(tempOne);
	}

	void VisualCubicRubic::rotateU()
	{
		cubic tempOne;
		cubic tempTwo;
		tempTwo = this->matrix[0][2][0];
		tempOne = this->matrix[0][2][2];
		this->matrix[0][2][2].exchangeForRotationU(this->matrix[0][0][2]);
		this->matrix[0][2][0].exchangeForRotationU(tempOne);
		tempOne = this->matrix[0][0][0];
		this->matrix[0][0][0].exchangeForRotationU(tempTwo);
		this->matrix[0][0][2].exchangeForRotationU(tempOne);
		tempTwo = this->matrix[0][1][0];
		tempOne = this->matrix[0][2][1];
		this->matrix[0][2][1].exchangeForRotationU(this->matrix[0][1][2]);
		this->matrix[0][1][0].exchangeForRotationU(tempOne);
		tempOne = this->matrix[0][0][1];
		this->matrix[0][0][1].exchangeForRotationU(tempTwo);
		this->matrix[0][1][2].exchangeForRotationU(tempOne);
	}

	void VisualCubicRubic::rotateU_()
	{
		this->rotateU();
		this->rotateU();
		this->rotateU();
	}

	void VisualCubicRubic::rotateD_()
	{
		this->rotateD();
		this->rotateD();
		this->rotateD();
	}

	void VisualCubicRubic::rotateD()
	{
		cubic tempOne;
		cubic tempTwo;
		tempTwo = this->matrix[2][2][0];
		tempOne = this->matrix[2][2][2];
		this->matrix[2][2][2].exchangeForRotationU(this->matrix[2][0][2]);
		this->matrix[2][2][0].exchangeForRotationU(tempOne);
		tempOne = this->matrix[2][0][0];
		this->matrix[2][0][0].exchangeForRotationU(tempTwo);
		this->matrix[2][0][2].exchangeForRotationU(tempOne);
		tempTwo = this->matrix[2][1][0];
		tempOne = this->matrix[2][2][1];
		this->matrix[2][2][1].exchangeForRotationU(this->matrix[2][1][2]);
		this->matrix[2][1][0].exchangeForRotationU(tempOne);
		tempOne = this->matrix[2][0][1];
		this->matrix[2][0][1].exchangeForRotationU(tempTwo);
		this->matrix[2][1][2].exchangeForRotationU(tempOne);
	}

	void VisualCubicRubic::rotateF()
	{
		cubic tempOne;
		cubic tempTwo;
		tempTwo = this->matrix[2][2][0];
		tempOne = this->matrix[0][2][0];
		this->matrix[0][2][0].exchangeForRotationF(this->matrix[0][0][0]);
		this->matrix[2][2][0].exchangeForRotationF(tempOne);
		tempOne = this->matrix[2][0][0];
		this->matrix[2][0][0].exchangeForRotationF(tempTwo);
		this->matrix[0][0][0].exchangeForRotationF(tempOne);
		tempTwo = this->matrix[1][2][0];
		tempOne = this->matrix[0][1][0];
		this->matrix[0][1][0].exchangeForRotationF(this->matrix[1][0][0]);
		this->matrix[1][2][0].exchangeForRotationF(tempOne);
		tempOne = this->matrix[2][1][0];
		this->matrix[2][1][0].exchangeForRotationF(tempTwo);
		this->matrix[1][0][0].exchangeForRotationF(tempOne);
	}

	void VisualCubicRubic::rotateF_()
	{
		this->rotateF();
		this->rotateF();
		this->rotateF();
	}

	void VisualCubicRubic::rotateB()
	{
		this->rotateB_();
		this->rotateB_();
		this->rotateB_();
	}

	void VisualCubicRubic::rotateB_()
	{
		cubic tempOne;
		cubic tempTwo;
		tempTwo = this->matrix[2][2][2];
		tempOne = this->matrix[0][2][2];
		this->matrix[0][2][2].exchangeForRotationF(this->matrix[0][0][2]);
		this->matrix[2][2][2].exchangeForRotationF(tempOne);
		tempOne = this->matrix[2][0][2];
		this->matrix[2][0][2].exchangeForRotationF(tempTwo);
		this->matrix[0][0][2].exchangeForRotationF(tempOne);
		tempTwo = this->matrix[1][2][2];
		tempOne = this->matrix[0][1][2];
		this->matrix[0][1][2].exchangeForRotationF(this->matrix[1][0][2]);
		this->matrix[1][2][2].exchangeForRotationF(tempOne);
		tempOne = this->matrix[2][1][2];
		this->matrix[2][1][2].exchangeForRotationF(tempTwo);
		this->matrix[1][0][2].exchangeForRotationF(tempOne);
	}

	void VisualCubicRubic::print()
	{
		this->matrix[0][0][0].print();
		this->matrix[0][1][0].print();
		this->matrix[0][2][0].print();
		this->matrix[1][0][0].print();
		this->matrix[1][1][0].print();
		this->matrix[1][2][0].print();
		this->matrix[2][0][0].print();
		this->matrix[2][1][0].print();
		this->matrix[2][2][0].print();
		///
		this->matrix[0][0][1].print();
		this->matrix[0][1][1].print();
		this->matrix[0][2][1].print();
		this->matrix[1][0][1].print();
		this->matrix[1][1][1].print();
		this->matrix[1][2][1].print();
		this->matrix[2][0][1].print();
		this->matrix[2][1][1].print();
		this->matrix[2][2][1].print();
		///
		this->matrix[0][0][2].print();
		this->matrix[0][1][2].print();
		this->matrix[0][2][2].print();
		this->matrix[1][0][2].print();
		this->matrix[1][1][2].print();
		this->matrix[1][2][2].print();
		this->matrix[2][0][2].print();
		this->matrix[2][1][2].print();
		this->matrix[2][2][2].print();
	}

	void VisualCubicRubic::randomGeneration()
	{
		int firstRandomCounter = 0;
		firstRandomCounter = 6;
		for (int i = 0; i < firstRandomCounter; i++)
		{
			int secondRandomCounter = 0;
			secondRandomCounter = rand() % 12;
			switch (secondRandomCounter)
			{
			case 0:
				this->rotateB();
				break;
			case 1:
				this->rotateB_();
				break;
			case 2:
				this->rotateD();
				break;
			case 3:
				this->rotateD_();
				break;
			case 4:
				this->rotateF();
				break;
			case 5:
				this->rotateF_();
				break;
			case 6:
				this->rotateL();
				break;
			case 7:
				this->rotateL_();
				break;
			case 8: 
				this->rotateR();
				break;
			case 9:
				this->rotateR_();
				break;
			case 10:
				this->rotateU();
				break;
			case 11:
				this->rotateU_();
				break;
			default:
				break;
			}
		}
	}

	void VisualCubicRubic::printCubic(int x, int y, int z)
	{
		this->matrix[x][y][z].print();
	}

	VisualCubicRubic::~VisualCubicRubic()
	{

	}

	void VisualCubicRubic::helpCreation(int size1, int size2, int size3, int mode, color newColor)
	{
		for (int i = 0; i <= size1; i++)
		{
			for (int j = 0; j <= size2; j++)
			{
				switch (mode)
				{
				case 0:
					this->matrix[size3][i][j].SetColor(newColor, 0);
					break;
				case 1:
					this->matrix[size3][i][j].SetColor(newColor, 1);
					break;
				case 2:
					this->matrix[i][j][size3].SetColor(newColor, 2);
					break;
				case 3:
					this->matrix[i][j][size3].SetColor(newColor, 3);
					break;
				case 4:
					this->matrix[i][size3][j].SetColor(newColor, 4);
					break;
				case 5:
					this->matrix[i][size3][j].SetColor(newColor, 5);
					break;
				default:
					break;
				}
			}
		}
	}

	bool VisualCubicRubic::isTrue()
	{
		bool flag = true;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (this->matrix[0][i][j].GetColoru() != this->matrix[0][1][1].GetColoru() || this->matrix[0][i][j].GetColoru() == not_found)
				{
					flag = false;
				}
			}
		}
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (this->matrix[2][i][j].GetColoru_() != this->matrix[2][1][1].GetColoru_() || this->matrix[2][i][j].GetColoru_() == not_found)
				{
					flag = false;
				}
			}
		}
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (this->matrix[i][j][0].GetColorf() != this->matrix[1][1][0].GetColorf() || this->matrix[i][j][0].GetColorf() == not_found)
				{
					flag = false;
				}
			}
		}
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (this->matrix[i][j][2].GetColorf_() != this->matrix[1][1][2].GetColorf_() || this->matrix[i][j][2].GetColorf_() == not_found)
				{
					flag = false;
				}
			}
		}
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (this->matrix[i][0][j].GetColorl() != this->matrix[1][0][1].GetColorl() || this->matrix[i][0][j].GetColorl() == not_found)
				{
					flag = false;
				}
			}
		}
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (this->matrix[i][2][j].GetColorr() != this->matrix[1][2][1].GetColorr() || this->matrix[i][2][j].GetColorr() == not_found)
				{
					flag = false;
				}
			}
		}
		return flag;
	}
}
