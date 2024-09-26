#include "Vector2.h"

Engine::Vector2 Engine::Vector2::Add(Vector2 one, Vector2 two)
{
	return Vector2(one.x + two.x, one.y + two.y);
}

Engine::Vector2 Engine::Vector2::Subtract(Vector2 one, Vector2 two)
{
	return Vector2(one.x - two.x, one.y - two.y);
}

Engine::Vector2 Engine::Vector2::Multiply(Vector2 one, Vector2 two)
{
	return Vector2(one.x * two.x, one.y * two.y);
}

Engine::Vector2 Engine::Vector2::Divide(Vector2 one, Vector2 two)
{
	return Vector2(one.x / two.x, one.y / two.y);
}
