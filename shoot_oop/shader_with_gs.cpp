#include "shader_with_gs.h"
shader_with_gs::shader_with_gs() {}

shader_with_gs::~shader_with_gs() {}

void shader_with_gs::Init(const std::string& file_name) {
	prog = glCreateProgram();
	shaders[0] = Create_Shader(load_shader(file_name + ".vs"), GL_VERTEX_SHADER);
	shaders[1] = Create_Shader(load_shader(file_name + ".gs"), GL_GEOMETRY_SHADER);
	shaders[2] = Create_Shader(load_shader(file_name + ".fs"), GL_FRAGMENT_SHADER);
	for (int i = 0; i < 3; ++i) {
		glAttachShader(prog, shaders[i]);
	}
	glLinkProgram(prog);

	GLint loglen;
	glGetProgramiv(prog, GL_INFO_LOG_LENGTH, &loglen);
	if (loglen > 0) {
		char* log = new char[loglen];
		GLsizei written;
		glGetProgramInfoLog(prog, loglen, &written, log);
		printf("%s\n", log);
		delete log;
	}
}

void shader_with_gs::ShutDown() {
	for (int i = 0; i < 3; ++i) {
		glDetachShader(prog, shaders[i]);
		glDeleteShader(shaders[i]);
	}
	glDeleteProgram(prog);
}

std::string shader_with_gs::load_shader(const std::string& filen) {
	std::ifstream file;
	file.open(filen.c_str());
	std::string line;
	std::string output;
	while (file.good()) {
		getline(file, line);
		output.append(line + '\n');
	}
	file.close();
	return output;
}

GLuint shader_with_gs::Create_Shader(const std::string& text, GLuint type) {
	GLuint Shader = glCreateShader(type);
	const char* p[1];
	p[0] = text.c_str();
	GLint l[1];
	l[0] = text.length();
	glShaderSource(Shader, 1, p, l);
	glCompileShader(Shader);
	return Shader;
}

void shader_with_gs::bind() {
	glUseProgram(prog);
}

GLuint shader_with_gs::GetProgram() {
	return prog;
}