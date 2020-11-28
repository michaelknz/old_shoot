#pragma once
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include <glew.h>
struct  Transform
{
	glm::mat4 model;
	glm::mat4 view;
	glm::mat4 projection;
};

struct  Camera
{
	glm::vec3 CameraPos;
	glm::vec3 CameraFront;
	glm::vec3 CameraUp;
	float speed;
};

class matrixes
{
public:
	matrixes();
	~matrixes();
	void rotate_model(float angle, glm::vec3 axis);
	void scale_model(glm::vec3 scale);
	void translate_model(glm::vec3 trans);
	Transform Create_matrixes(bool is_rotate, bool is_scale, bool is_trans, Camera cam, float angle, glm::vec3 axis, glm::vec3 scale, glm::vec3 trans);
	void send_mat(GLuint prog, Transform trans);
	static void veiw_matrix_update(Transform* trans, Camera cam);
private:
	glm::mat4 model;
	glm::mat4 veiw;
	glm::mat4 projection;
};

