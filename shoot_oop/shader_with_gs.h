#pragma once
#include "shader_basic.h"
class shader_with_gs:public shader_basic
{
public:
	shader_with_gs();
	~shader_with_gs();
	void Init(const std::string& file_name);
	void ShutDown();
	std::string load_shader(const std::string& filen);
	void bind();
	GLuint Create_Shader(const std::string& text, GLuint type);
	GLuint GetProgram();
private:
	GLuint prog;
	GLuint shaders[3];
};

