#include "event_handler.h"

event_handler::event_handler() {

	is_first_mouse = true;
	pitch = 0.0f;
	yaw = -90.0f;
	is_mouse = true;

}

event_handler::~event_handler() {

}

Camera event_handler::KeyDown_Handler(Camera cam, SDL_Event Event, Transform* trans) {
	Camera camera = cam;
	if (Event.key.keysym.sym == SDLK_w) {
		camera.CameraPos += camera.CameraFront * camera.speed;
	}

	else if (Event.key.keysym.sym == SDLK_s) {
		camera.CameraPos -= camera.CameraFront * camera.speed;
	}

	else if (Event.key.keysym.sym == SDLK_a) {
		camera.CameraPos -= glm::normalize(glm::cross(camera.CameraFront, camera.CameraUp)) * camera.speed;
	}

	else if (Event.key.keysym.sym == SDLK_d) {
		camera.CameraPos += glm::normalize(glm::cross(camera.CameraFront, camera.CameraUp)) * camera.speed;
	}
	matrixes::veiw_matrix_update(trans, camera);
	return camera;
}

Camera event_handler::MouseMove_Handler(Camera cam, SDL_Event Event, Transform* trans, float sence) {
	Camera camera = cam;
	if (is_mouse) {
		if (is_first_mouse) {
			last_X = Event.motion.x;
			last_Y = Event.motion.y;
			last_Y *= (-1);
			is_first_mouse = false;
		}
		float X = Event.motion.x;
		float Y = Event.motion.y;
		Y *= (-1);
		float del_X = X - last_X;
		float del_Y = Y - last_Y;
		last_X = X;
		last_Y = Y;
		del_X *= sence;
		del_Y *= sence;
		pitch += del_Y;
		yaw += del_X;
		if (pitch >= 89.0f)
			pitch = 89.0f;
		if (pitch <= -89.0f)
			pitch = -89.0f;
		camera.CameraFront.x = cos(glm::radians(yaw));
		camera.CameraFront.y = sin(glm::radians(pitch));
		camera.CameraFront.z = cos(glm::radians(pitch)) * sin(glm::radians(yaw));
		matrixes::veiw_matrix_update(trans, camera);
	}
	return camera;
}

void event_handler::LeftMouseDown_Handler(std::vector<mesh*>* meshes, std::vector<shader*>* shaders, glm::vec3 gun_dir, glm::vec3 gun_pos, float lazer_distanse, std::vector<float>* dels_alpha) {
	glm::vec3 v = gun_pos;
	float* mas = &v.x;
	glm::vec3 gd = gun_dir;
	mesh* Mesh = new mesh(new mesh_point, mas, 3);
	meshes->push_back(Mesh);
	shader* Shader = new shader(new shader_with_gs, "shot_shade");
	Shader->bind();
	glUniform1f(glGetUniformLocation(Shader->GetProgram(), "lazer_distance"), lazer_distanse);
	dels_alpha->push_back(0.0f);
	glUniform3f(glGetUniformLocation(Shader->GetProgram(), "gun_dir"), gd.x, gd.y, gd.z);
	shaders->push_back(Shader);
}

void event_handler::RightMouseDown_Handler() {
	if (is_mouse)
		is_mouse = false;
	else {
		is_mouse = true;
		is_first_mouse = true;
	}
}
