#include "matrixes.h"

matrixes::matrixes() {

	model = glm::mat4(1.0f);
	veiw = glm::mat4(1.0f);
	projection = glm::mat4(1.0f);
}

matrixes::~matrixes() {

}

void matrixes::rotate_model(float angle, glm::vec3 axis) {
	model = glm::rotate(model, glm::radians(angle), axis);
}

void matrixes::scale_model(glm::vec3 scale) {
	model = glm::scale(model, scale);
}

void matrixes::translate_model(glm::vec3 trans) {
	model = glm::translate(model, trans);
}

Transform matrixes::Create_matrixes(bool is_rotate, bool is_scale, bool is_trans, Camera cam, float angle, glm::vec3 axis, glm::vec3 scale, glm::vec3 trans) {
	if (is_rotate) {
		rotate_model(angle, axis);
	}

	if (is_trans) {
		translate_model(trans);
	}

	if (is_scale) {
		scale_model(scale);
	}

	veiw = glm::lookAt(cam.CameraPos, cam.CameraPos + cam.CameraFront, cam.CameraUp);
	projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

	Transform output;
	output.model = model;
	output.view = veiw;
	output.projection = projection;
	return output;
}

void matrixes::send_mat(GLuint prog, Transform trans) {
	glUniformMatrix4fv(glGetUniformLocation(prog, "model"), 1, GL_FALSE, glm::value_ptr(trans.model));
	glUniformMatrix4fv(glGetUniformLocation(prog, "veiw"), 1, GL_FALSE, glm::value_ptr(trans.view));
	glUniformMatrix4fv(glGetUniformLocation(prog, "projection"), 1, GL_FALSE, glm::value_ptr(trans.projection));
	glUniform3f(glGetUniformLocation(prog, "lightPos"), 0.0f, 0.0f, 0.0f);
}

void matrixes::veiw_matrix_update(Transform* trans, Camera cam) {
	trans->view = glm::lookAt(cam.CameraPos, cam.CameraPos + cam.CameraFront, cam.CameraUp);
}