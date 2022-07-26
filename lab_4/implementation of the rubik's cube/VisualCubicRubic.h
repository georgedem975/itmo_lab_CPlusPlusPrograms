#pragma once
#include <vector>
#include <iostream>
#include "glfw3.h"

namespace visualCubicRubic
{
	enum color
	{
		white,
		green,
		orange,
		blue,
		red,
		yellow,
		not_found
	};

	class cubic
	{
	public:
		cubic();
		~cubic();
		void SetColor(color newColor, int mode);
		color GetColorf();
		color GetColorf_();
		color GetColoru();
		color GetColoru_();
		color GetColorr();
		color GetColorl();
		float Get_x_r();
		float Get_x_l();
		float Get_y_d();
		float Get_y_u();
		float Get_z_f();
		float Get_z_b();
		void Set_vert(float new_x_r, float new_x_l, float new_y_d, float new_y_u, float new_z_f, float new_z_b);
		void print();
		void operator = (const cubic& other);
		void exchangeForRotationR(const cubic& other);
		void exchangeForRotationR_(const cubic& other);
		void exchangeForRotationU(const cubic& other);
		void exchangeForRotationU_(const cubic& other);
		void exchangeForRotationF(const cubic& other);
		void exchangeForRotationF_(const cubic& other);

	private:
		color f;
		color f_;
		color u;
		color u_;
		color r;
		color l;
		float x_r;
		float x_l;
		float y_d;
		float y_u;
		float z_f;
		float z_b;
		void printF_color();
		void printF__color();
		void printU_color();
		void printU__color();
		void printR_color();
		void printL_color();
	};

	class VisualCubicRubic
	{
	public:
		VisualCubicRubic();
		~VisualCubicRubic();
		bool isTrue();
		void print();
		void printCubic(int x, int y, int z);
		void rotateR();
		void rotateR_();
		void rotateL();
		void rotateL_();
		void rotateU();
		void rotateU_();
		void rotateD();
		void rotateD_();
		void rotateF();
		void rotateF_();
		void rotateB();
		void rotateB_();
		void randomGeneration();
		std::string way;
		bool flag = 1;

	private:
		cubic matrix[3][3][3];
		void helpCreation(int size1, int size2, int size3, int mode, color newColor);
	};
}

void rubicBfs(visualCubicRubic::VisualCubicRubic newCubicForBfs, std::string& way);