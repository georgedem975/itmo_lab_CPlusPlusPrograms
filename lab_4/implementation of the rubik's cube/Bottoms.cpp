#include "Bottoms.h"
#include "glfw3.h"

namespace bottom
{
	void CreateBottomPlay()
	{
		glBegin(GL_QUADS);
		glColor3f(1, 1, 1);
		glVertex3f(0.5, 0.7, -0.5);
		glVertex3f(0.8, 0.7, -0.5);
		glVertex3f(0.8, 0.5, -0.5);
		glVertex3f(0.5, 0.5, -0.5);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0, 0, 0);
		glVertex3f(0.62, 0.65, -0.51);
		glVertex3f(0.62, 0.55, -0.51);
		glVertex3f(0.72, 0.6, -0.51);
		glEnd();
	}
	
	void CreateBottomExit()
	{
		glBegin(GL_QUADS);
		glColor3f(1, 1, 1);
		glVertex3f(0.5, 0.4, -0.5);
		glVertex3f(0.8, 0.4, -0.5);
		glVertex3f(0.8, 0.2, -0.5);
		glVertex3f(0.5, 0.2, -0.5);
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(0,0,0);
		glVertex3f(0.6, 0.35, -0.51);
		glVertex3f(0.65, 0.35, -0.51);
		glVertex3f(0.65, 0.25, -0.51);
		glVertex3f(0.6, 0.25, -0.51);
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(0, 0, 0);
		glVertex3f(0.67, 0.31, -0.51);
		glVertex3f(0.72, 0.31, -0.51);
		glVertex3f(0.72, 0.29, -0.51);
		glVertex3f(0.67, 0.29, -0.51);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0, 0, 0);
		glVertex3f(0.68, 0.33, -0.51);
		glVertex3f(0.66, 0.3, -0.51);
		glVertex3f(0.68, 0.27, -0.51);
		glEnd();

	}

	void CreateBottomThisPosition(int positionOfBottom)
	{
		if (positionOfBottom % 2 == 0)
		{
			glBegin(GL_QUADS);
			glColor3f(1,1,1);
			glVertex3f(0.45, 0.75, -0.49);
			glVertex3f(0.85, 0.75, -0.49);
			glVertex3f(0.85, 0.45, -0.49);
			glVertex3f(0.45, 0.45, -0.49);
			glEnd();
		}
		else
		{
			glBegin(GL_QUADS);
			glColor3f(1, 1, 1);
			glVertex3f(0.45, 0.45, -0.49);
			glVertex3f(0.85, 0.45, -0.49);
			glVertex3f(0.85, 0.15, -0.49);
			glVertex3f(0.45, 0.15, -0.49);
			glEnd();
		}
	}

	void CreateBottomFreeMode()
	{
		glBegin(GL_QUADS);
		glColor3f(1, 1, 1);
		glVertex3f(0.5, 0.8, -0.5);
		glVertex3f(0.8, 0.8, -0.5);
		glVertex3f(0.8, 0.6, -0.5);
		glVertex3f(0.5, 0.6, -0.5);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0, 0, 0);
		glVertex3f(0.6, 0.75, -0.51);
		glVertex3f(0.7, 0.7, -0.51);
		glVertex3f(0.6, 0.65, -0.51);
		glEnd();
	}

	void CreateBottomII()
	{
		glBegin(GL_QUADS);
		glColor3f(1, 1, 1);
		glVertex3f(0.5, 0.5, -0.5);
		glVertex3f(0.8, 0.5, -0.5);
		glVertex3f(0.8, 0.3, -0.5);
		glVertex3f(0.5, 0.3, -0.5);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0, 0, 0);
		glVertex3f(0.6, 0.45, -0.51);
		glVertex3f(0.65, 0.4, -0.51);
		glVertex3f(0.7, 0.45, -0.51);
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(0, 0, 0);
		glVertex3f(0.6, 0.34, -0.51);
		glVertex3f(0.7, 0.34, -0.51);
		glVertex3f(0.7, 0.32, -0.51);
		glVertex3f(0.6, 0.32, -0.51);
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(0, 0, 0);
		glVertex3f(0.7, 0.36, -0.51);
		glVertex3f(0.72, 0.36, -0.51);
		glVertex3f(0.72, 0.32, -0.51);
		glVertex3f(0.7, 0.32, -0.51);
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(0, 0, 0);
		glVertex3f(0.58, 0.36, -0.51);
		glVertex3f(0.6, 0.36, -0.51);
		glVertex3f(0.6, 0.32, -0.51);
		glVertex3f(0.58, 0.32, -0.51);
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(0, 0, 0);
		glVertex3f(0.64, 0.45, -0.51);
		glVertex3f(0.66, 0.45, -0.51);
		glVertex3f(0.66, 0.475, -0.51);
		glVertex3f(0.64, 0.475, -0.51);
		glEnd();
	}

	void CreateBottomComputerVision()
	{
		glBegin(GL_QUADS);
		glColor3f(1, 1, 1);
		glVertex3f(0.5, 0.2, -0.5);
		glVertex3f(0.8, 0.2, -0.5);
		glVertex3f(0.8, 0, -0.5);
		glVertex3f(0.5, 0, -0.5);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0, 0, 0);
		glVertex3f(0.6, 0.15, -0.51);
		glVertex3f(0.7, 0.1, -0.51);
		glVertex3f(0.6, 0.05, -0.51);
		glEnd();
	}

	void CreateBottomToMainMenu()
	{
		glBegin(GL_QUADS);
		glColor3f(1, 1, 1);
		glVertex3f(0.5, -0.1, -0.5);
		glVertex3f(0.8, -0.1, -0.5);
		glVertex3f(0.8, -0.3, -0.5);
		glVertex3f(0.5, -0.3, -0.5);
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(0, 0, 0);
		glVertex3f(0.6, -0.15, -0.51);
		glVertex3f(0.65, -0.15, -0.51);
		glVertex3f(0.65, -0.25, -0.51);
		glVertex3f(0.6, -0.25, -0.51);
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(0, 0, 0);
		glVertex3f(0.67, -0.19, -0.51);
		glVertex3f(0.72, -0.19, -0.51);
		glVertex3f(0.72, -0.21, -0.51);
		glVertex3f(0.67, -0.21, -0.51);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0, 0, 0);
		glVertex3f(0.68, -0.17, -0.51);
		glVertex3f(0.66, -0.2, -0.51);
		glVertex3f(0.68, -0.23, -0.51);
		glEnd();
	}

	void CreateBottomThisPositionInMainMenu(int positionOfBottom)
	{
		switch (positionOfBottom)
		{
		case 0:
			glBegin(GL_QUADS);
			glColor3f(1, 1, 1);
			glVertex3f(0.45, 0.85, -0.49);
			glVertex3f(0.85, 0.85, -0.49);
			glVertex3f(0.85, 0.55, -0.49);
			glVertex3f(0.45, 0.55, -0.49);
			glEnd();
			break;
		case 1:
			glBegin(GL_QUADS);
			glColor3f(1, 1, 1);
			glVertex3f(0.45, 0.55, -0.49);
			glVertex3f(0.85, 0.55, -0.49);
			glVertex3f(0.85, 0.25, -0.49);
			glVertex3f(0.45, 0.25, -0.49);
			glEnd();
			break;
		case 2:
			glBegin(GL_QUADS);
			glColor3f(1, 1, 1);
			glVertex3f(0.45, 0.25, -0.49);
			glVertex3f(0.85, 0.25, -0.49);
			glVertex3f(0.85, -0.05, -0.49);
			glVertex3f(0.45, -0.05, -0.49);
			glEnd();
			break;
		case 3:
			glBegin(GL_QUADS);
			glColor3f(1, 1, 1);
			glVertex3f(0.45, -0.05, -0.49);
			glVertex3f(0.85, -0.05, -0.49);
			glVertex3f(0.85, -0.35, -0.49);
			glVertex3f(0.45, -0.35, -0.49);
			glEnd();
			break;
		default:
			break;
		}
	}
}