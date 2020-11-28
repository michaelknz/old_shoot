#pragma once
#include<vector>
#include<string>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
class Parser
{
public:
	Parser();
	~Parser();
	void push_new_mesh(const std::string& filen);
	std::vector<float> load_one_mesh(unsigned int i);
private:
	std::vector<std::vector<float>> meshes;
};

