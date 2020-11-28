#pragma once
#include <glew.h>
#include <SOIL.h>
#include <string>
class Textures
{
public:
	Textures();
	~Textures();
	void SetTexture(const std::string& filen);
	void UseTexture(GLuint prog);
private:
	GLuint texture;
	int weight, height;
	unsigned char* image;
};

