#include "Cube.h"

int main()
{
	GLFWwindow* window;

	Cube a(0.2);

	if (!glfwInit())
		return -1;

	window = glfwCreateWindow(640, 480, "CUBIC-RUBIC GAME", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	int i = 0;
	bool flagToStartRotateR = false;
	bool flagToStartRotateL = false;
	bool flagToStartRotateU = false;
	bool flagToStartRotateD = false;

	glEnable(GL_DEPTH_TEST);

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		if (!a.isTrueCube())
		{
			exit(1);
		}

		if (flagToStartRotateR && !flagToStartRotateL &&
			!flagToStartRotateU && !flagToStartRotateD)
		{
			a.rotateR(i);
		}
		if (flagToStartRotateL && !flagToStartRotateR &&
			!flagToStartRotateU && !flagToStartRotateD)
		{
			a.rotateL(i);
		}
		if (flagToStartRotateU && !flagToStartRotateL &&
			!flagToStartRotateR && !flagToStartRotateD)
		{
			a.rotateU(i);
		}
		if (flagToStartRotateD && !flagToStartRotateL &&
			!flagToStartRotateU && !flagToStartRotateR)
		{
			a.rotateD(i);
		}
		
		if (!flagToStartRotateR && !flagToStartRotateL &&
			!flagToStartRotateU && !flagToStartRotateD)
		{
			a.print();
		}

		i++;

		if (i == 91)
		{
			i = 0;
			if (flagToStartRotateR)
			{
				a.R();
			}
			else if (flagToStartRotateL)
			{
				a.L();
			}
			else if (flagToStartRotateU)
			{
				a.U();
			}
			else if (flagToStartRotateD)
			{
				a.D();
			}
			flagToStartRotateR = false;
			flagToStartRotateL = false;
			flagToStartRotateU = false;
			flagToStartRotateD = false;
		}

		if (GetAsyncKeyState(VK_UP))
		{
			flagToStartRotateU = true;
		}
		if (GetAsyncKeyState(VK_DOWN))
		{
			flagToStartRotateD = true;
		}
		if (GetAsyncKeyState(VK_LEFT))
		{
			flagToStartRotateL = true;
		}
		if (GetAsyncKeyState(VK_RIGHT))
		{
			flagToStartRotateR = true;
		}

		Sleep(10);

		glfwSwapBuffers(window);

		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}