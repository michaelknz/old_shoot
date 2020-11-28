#include "Parser.h"

Parser::Parser() {}

Parser::~Parser() {}

void Parser::push_new_mesh(const std::string& filen) {
	Assimp::Importer importer;
	const aiScene* Scene = importer.ReadFile(filen, NULL);
	std::vector<float> buf;
	aiMesh* mesh;
	for (int i = 0; i < Scene->mNumMeshes; ++i) {
		mesh = Scene->mMeshes[i];
		for (int j = 0; j < mesh->mNumFaces; ++j) {
			const aiFace& face = mesh->mFaces[j];
			for (int e = 0; e < face.mNumIndices; ++e) {
				unsigned int index = face.mIndices[e];
				aiVector3D pos = mesh->mVertices[index];
				aiVector3D norm = mesh->mNormals[index];
				buf.push_back(pos.x);
				buf.push_back(pos.y);
				buf.push_back(pos.z);
				buf.push_back(norm.x);
				buf.push_back(norm.y);
				buf.push_back(norm.z);
				buf.push_back(mesh->mTextureCoords[0][index].x);
				buf.push_back(mesh->mTextureCoords[0][index].y);
			}
		}
		meshes.push_back(buf);
		buf.clear();
	}
}
std::vector<float> Parser::load_one_mesh(unsigned int i) {
	return meshes[i];
}
