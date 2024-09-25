#pragma once
#include "../Transform/Transform.h"
class Object
{
public: 
	Transform transform;
	void Start();
	void Update();
	void Shutdown();

private:
	bool m_HasCollision;
};
