#include "Screen.h"

#include "VAO.h"
#include "VBO.h"
#include "EBO.h"

#include "Mesh.h"

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
}

int Screen::run()
{
	Shader shaderProgram(vertexShaderFile, fragmentShaderFile);

	/* instead of passing just floats, we can pass a Vertex object that holds all the
	*  position data,
	*  color data, (more for later)
	*/

	/*VAO mainVAO;
	mainVAO.Bind();

	VBO mainVBO(testVerts);
	EBO mainEBO(testIndices);

	mainVAO.LinkAttrib(mainVBO, 0, 1, GL_FLOAT, 0, (void*)0);

	mainVAO.Unbind();
	mainVBO.Unbind();
	mainEBO.Unbind();*/

	Mesh cube("Meshes/cube.obj");

	while (!glfwWindowShouldClose(mainWindow))
	{
		glClearColor(0.5f, 0.5f, 0.7f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//mainVAO.Bind();
		//glDrawElements(GL_TRIANGLES, 4, GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(mainWindow);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}