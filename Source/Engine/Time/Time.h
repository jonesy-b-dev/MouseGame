#pragma once
#include <SFML/Graphics.hpp>
namespace Engine
{
	class Time
	{
	public:
		static void UpdateTime();
		static float deltaTime;

	private:
		static sf::Clock clock;
	};
}
