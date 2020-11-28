#pragma once
#include "mesh_basic.h"
#include <glew.h>
class mesh_point:public mesh_basic
{
public:
	mesh_point();
	~mesh_point();
	void Init(float* pos, unsigned int num);
	void ShutDown();
	void Draw();
private:
	GLuint vao;
	GLuint vbo;
	unsigned int number;
};

