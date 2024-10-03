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
        sf::Event event;
		sf::RenderWindow window;
		std::vector<Object*> gameObjects;
		// Seperate list for UI objects so we can render them easily on top of the rest
		std::vector<Object*> uiObjects;
		FoodSpawner foodSpawner;
		sf::Sprite m_background;
		sf::Texture m_backgroundTex;
		const char* m_backgroundPath = "Assets/Background.png";
		int objectCount = 0;

		void Update();
		void Shutdown();
	};
}
