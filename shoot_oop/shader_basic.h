#pragma once
#include <glew.h>
#include <string>
#include <fstream>
class shader_basic
{
public:
	shader_basic();
	~shader_basic();
	virtual void Init(const std::string& file_name);
	virtual void ShutDown();
	virtual void bind();
	virtual std::string load_shader(const std::string& filen);
	virtual GLuint Create_Shader(const std::string& text, GLuint type);
	virtual GLuint GetProgram();
};

