#pragma once
#include <SDL.h>
#include <glew.h>
#include <string>
class display
{
public:
	display(int weight, int height, const std::string& name);
	~display();
	void Clear(float r, float g, float b, float a);
	void Swap();
private:
	SDL_Window* window;
	SDL_GLContext context;
};

