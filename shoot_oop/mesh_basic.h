#pragma once
class mesh_basic
{
public:
	mesh_basic();
	~mesh_basic();
	virtual void Init(float* pos, unsigned int num);
	virtual void Draw();
	virtual void ShutDown();
};

