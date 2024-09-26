#pragma once
#include "../Vector2/Vector2.h"
namespace Engine
{
	class Transform
	{
	public:
		Vector2 position;
		float rotation;
		Vector2 scale;

		Transform(Vector2 position, float rotation, Vector2 scale) : position(position), rotation(rotation), scale(scale) {}
	};
}
