#include "mesh_point.h"

mesh_point::mesh_point() {}

mesh_point::~mesh_point() {}

void mesh_point::Init(float* pos, unsigned int num) {
	number = num;
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);

	glBindVertexArray(vao);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, num * sizeof(float), pos, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindVertexArray(vao);

}

void mesh_point::Draw() {
	glBindVertexArray(vao);
	glDrawArrays(GL_POINTS, 0, number / 3);
	glBindVertexArray(0);
}

void mesh_point::ShutDown() {
	glDeleteBuffers(1, &vbo);
	glDeleteVertexArrays(1, &vao);
}
