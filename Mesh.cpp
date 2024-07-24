#include "Mesh.h"

Mesh::Mesh(const char* filename)
{
	readOBJFile(filename);
}

//we should not include OBJ files within the project itself, it should just be in the folder
//program throws LNK 1107 otherwise.

void Mesh::readOBJFile(const char* filename)
{
	std::ifstream objFile(filename);

	if (!objFile.is_open())
	{
		printf("could not open file \"%s\"", filename);
		return;
	}

	while (!objFile.eof())
	{
		std::string line;
		std::getline(objFile, line);
		if (line[0] == 'v')
		{
			std::cout << line << "\n";
		}
	}

	return;
}