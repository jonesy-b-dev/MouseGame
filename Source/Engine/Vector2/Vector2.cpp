#include "Vector2.h"

Engine::Vector2 Engine::Vector2::Add(Vector2 two)
{
	return Vector2(x + two.x, y + two.y);
}

Engine::Vector2 Engine::Vector2::Subtract(Vector2 two)
{
	return Vector2(x - two.x, y - two.y);
}

Engine::Vector2 Engine::Vector2::Multiply(Vector2 two)
{
	return Vector2(x * two.x, y * two.y);
}

Engine::Vector2 Engine::Vector2::Divide(Vector2 two)
{
	return Vector2(x / two.x, y / two.y);
}
