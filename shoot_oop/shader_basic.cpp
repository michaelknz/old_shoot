#include "shader_basic.h"

shader_basic::shader_basic() {}

shader_basic::~shader_basic() {}

void shader_basic::Init(const std::string& file_name) {}

void shader_basic::ShutDown() {}

std::string shader_basic::load_shader(const std::string& filen) {
	return "It's basic class method";
}

GLuint shader_basic::Create_Shader(const std::string& text, GLuint type) {
	return 0;
}

void shader_basic::bind() {}

GLuint shader_basic::GetProgram() {
	return 0;
}
