#pragma once
#include "shader_basic.h"
class shader
{
public:
	shader(shader_basic* shade, const std::string& fn);
	~shader();
	void bind();
	GLuint GetProgram();
private:
	shader_basic* Shader;
};

