#pragma once
#include "Object/object.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <Transform/Transform.h>
#include "../Game/FoodSpawner/FoodSpawner.h"
#include <Vector2/Vector2.h>

namespace Engine
{
	class EngineCore
	{
	public: 
		EngineCore() {};
		void Start(const char* windowName, int width, int height);
	private:
		sf::RenderWindow window;
		std::vector<Object*> gameObjects;
		std::vector<Object*> uiObjects;
		FoodSpawner foodSpawner;
		int objectCount = 0;

		void Update();
		void Shutdown();
	};
}
