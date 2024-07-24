#ifndef SHADER_CLASS_H
#define SHADER_CLASS_H

#include <glad/glad.h>
#include "FileReader.h"

class Shader
{
	public:
		GLuint ID;
		Shader();
		Shader(const char* vertexFile, const char* fragmentFile);

		void Activate();
		void Delete();


};

#endif // !SHADER_CLASS_H