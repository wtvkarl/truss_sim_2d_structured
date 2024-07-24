#ifndef MESH_CLASS_H
#define MESH_CLASS_H

#include <vector>
#include <iostream>
#include <fstream>
#include <string>

#include "Vertex.h"

class Mesh
{
	public:
		std::vector<Vertex> vertices = {};

		Mesh(const char* objFileName);

		void readOBJFile(const char* filename);
		
};

#endif // !MESH_CLASS_H


