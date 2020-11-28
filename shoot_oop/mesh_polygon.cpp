#include "mesh_polygon.h"

mesh_polygon::mesh_polygon() {}

mesh_polygon::~mesh_polygon() {}

void mesh_polygon::Init(float* pos, unsigned int num) {
	number = num;
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);

	glBindVertexArray(vao);

	glBindBuffer(GL_ARRAY_BUFFER,vbo);
	glBufferData(GL_ARRAY_BUFFER, num * sizeof(float), pos, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3*sizeof(float)));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6*sizeof(float)));
	glEnableVertexAttribArray(2);

	glBindVertexArray(vao);

}

void mesh_polygon::Draw() {
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, number / 8);
	glBindVertexArray(0);
}

void mesh_polygon::ShutDown() {
	glDeleteBuffers(1, &vbo);
	glDeleteVertexArrays(1, &vao);
}