#include "Screen.h"

const char* vertexShaderFile = "Shaders/default.vert";
const char* fragmentShaderFile = "Shaders/default.frag";

Screen::Screen(int w, int h, const char* t)
{
	width = w;
	height = h;
	title = t;

	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	mainWindow = glfwCreateWindow(width, height, title, NULL, NULL);

	if (mainWindow == NULL)
	{
		std::cout << "failed to create window :(" << "\n";
		glfwTerminate();
	}

	glfwMakeContextCurrent(mainWindow);
	gladLoadGL();
	glViewport(0, 0, width, height);

	shaderProgram = Shader(vertexShaderFile, fragmentShaderFile);
}

int Screen::run()
{
	while (!glfwWindowShouldClose(mainWindow))
	{
		glClearColor(0.5f, 0.5f, 0.7f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(mainWindow);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}