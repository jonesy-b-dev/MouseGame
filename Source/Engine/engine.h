#pragma once
#include "Object/object.h"
#include <SFML/Graphics.hpp>
#include <vector>

namespace Engine
{
	class EngineCore
	{
	public: 
		void Start(const char* windowName, int width, int height);
	private:
		sf::RenderWindow window;
		std::vector<Object*> gameObjects;
		std::vector<Object*> uiObjects;
		void Update();
		void Shutdown();
	};
}
