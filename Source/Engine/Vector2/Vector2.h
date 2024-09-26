#pragma once
namespace Engine
{
	class Vector2
	{
	public:
		float x, y;
		Vector2(float x, float y) : x(x), y(y) {}
		Vector2 Add(Vector2 one, Vector2 two);
		Vector2 Subtract(Vector2 one, Vector2 two);
		Vector2 Multiply(Vector2 one, Vector2 two);
		Vector2 Divide(Vector2 one, Vector2 two);
	};
}
