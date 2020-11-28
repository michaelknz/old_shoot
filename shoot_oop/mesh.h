#pragma once
#include "mesh_basic.h"
#include <glew.h>
class mesh
{
public:
	mesh(mesh_basic* mesh, float* buf, unsigned int num);
	~mesh();
	void Draw();
private:
	mesh_basic* Mesh;
};

