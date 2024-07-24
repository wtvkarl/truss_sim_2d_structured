#ifndef SCREEN_CLASS_H
#define SCREEN_CLASS_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <vector>
#include "ShaderClass.h"

class Screen
{
	public:

		int width, height;
		const char* title;
		GLFWwindow* mainWindow;
		Shader shaderProgram;

		Screen(int w, int h, const char* t);

		int run();
};

#endif // !SCREEN_CLASS_H
