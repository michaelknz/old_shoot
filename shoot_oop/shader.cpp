#include "shader.h"

shader::shader(shader_basic* shade, const std::string& fn) {
	Shader = shade;
	Shader->Init(fn);
}

shader::~shader() {
	Shader->ShutDown();
	delete Shader;
}

void shader::bind() {
	Shader->bind();
}

GLuint shader::GetProgram() {
	return Shader->GetProgram();
}