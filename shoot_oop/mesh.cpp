#include "mesh.h"

mesh::mesh(mesh_basic* mesh, float* buf, unsigned int num) {
	Mesh = mesh;
	Mesh->Init(buf,num);
}

mesh::~mesh() {
	Mesh->ShutDown();
	delete Mesh;
}

void mesh::Draw() {
	Mesh->Draw();
}