#pragma once
#include <vector>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
class decals_maker
{
public:
	decals_maker();
	~decals_maker();
	void Init(std::vector<float> mesh);
	glm::vec3 dec_coord(glm::vec3 startp, glm::vec3 endp);
	bool is_coord_in_plane(glm::vec3 vertex);
private:
	glm::vec3 point;
	glm::vec3 normal;
};

