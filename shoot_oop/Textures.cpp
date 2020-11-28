#include "Textures.h"

Textures::Textures() {}

Textures::~Textures() {}

void Textures::SetTexture(const std::string& filen) {
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	image = SOIL_load_image(filen.c_str(), &weight, &height, 0, SOIL_LOAD_RGB);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, weight, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glGenerateTextureMipmap(texture);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Textures::UseTexture(GLuint prog) {
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture);
	glUniform1i(glGetUniformLocation(prog, "Texture"), 0);
}