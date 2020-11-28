#pragma once
#include "shader_basic.h"
class shader_without_gs: public shader_basic
{
public:
	shader_without_gs();
	~shader_without_gs();
	void Init(const std::string& file_name);
	void ShutDown();
	void bind();
	std::string load_shader(const std::string& filen);
	GLuint Create_Shader(const std::string& text, GLuint type);
	GLuint GetProgram();
private:
	GLuint shaders[2];
	GLuint prog;
};

