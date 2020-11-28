#include "decals_maker.h"

decals_maker::decals_maker(){}

decals_maker::~decals_maker(){}

void decals_maker::Init(std::vector<float> mesh) {
	point = glm::vec3(mesh[0], mesh[1], mesh[2]);
	for (int i = 8; i < mesh.size(); i += 8) {
		if (point.z < mesh[i + 2]) {
			point = glm::vec3(mesh[i], mesh[i + 1], mesh[i + 2]);
		}
	}
	normal = glm::vec3(0.0f, 0.0f, 1.0f);
}

glm::vec3 decals_maker::dec_coord(glm::vec3 startp, glm::vec3 endp) {
	glm::vec3 plane_vertex = point;
	glm::vec3 CA = plane_vertex - startp;
	float CN = glm::dot(CA, normal * glm::vec3(-1, -1, -1));
	glm::vec3 CV = endp - startp;
	float CM = glm::dot(CV, normal * glm::vec3(-1, -1, -1));
	float K = CN / CM;
	glm::vec3 out = glm::vec3(CV.x * K, CV.y * K, CV.z * K);
	return out;
}
