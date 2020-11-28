#pragma once
#include "matrixes.h"
#include <SDL.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include <glew.h>
#include <vector>
#include "mesh.h"
#include "mesh_point.h"
#include "shader.h"
#include "shader_with_gs.h"
class event_handler
{
public:
	event_handler();
	~event_handler();
	Camera KeyDown_Handler(Camera cam, SDL_Event event, Transform* trans);
	Camera MouseMove_Handler(Camera cam, SDL_Event Event, Transform* trans, float sence);
	void LeftMouseDown_Handler(std::vector<mesh*>* meshes, std::vector<shader*>*shaders, glm::vec3 gun_dir, glm::vec3 gun_pos, float lazer_distanse, std::vector<float>* dels_alpha);
	void RightMouseDown_Handler();
private:
	float last_X;
	float last_Y;
	bool is_first_mouse;
	float pitch;
	float yaw;
	bool is_mouse;
};

