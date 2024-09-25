#pragma once
#include "../Transform/Transform.h"
namespace Engine
{
	class Object
	{
	public:
		Transform transform;
		virtual void Start();
		virtual void Update();
		virtual void Shutdown();

	private:
		bool m_HasCollision;
	};
}
