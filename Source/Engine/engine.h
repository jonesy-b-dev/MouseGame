#pragma once
#include "Object/object.h"
#include <SFML/Graphics.hpp>
#include <vector>

namespace Engine
{
	class EngineCore
	{
	public: 
		void Start();
	private:
		std::vector<Object> gameObjects;
		std::vector<Object> uiObjects;
		sf::RenderWindow window;
		sf::CircleShape shape;
		void Update();
		void Shutdown();
	};
}
