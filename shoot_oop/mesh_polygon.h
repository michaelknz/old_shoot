#pragma once
#include "mesh_basic.h"
#include <glew.h>
class mesh_polygon:public mesh_basic
{
public:
	mesh_polygon();
	~mesh_polygon();
	void Init(float* pos, unsigned int num);
	void ShutDown();
	void Draw();
private:
	GLuint vao;
	GLuint vbo;
	unsigned int number;
};

