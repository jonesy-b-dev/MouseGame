#pragma once
#include "Object/object.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <Transform/Transform.h>
#include "../Game/FoodSpawner/FoodSpawner.h"
#include <Vector2/Vector2.h>
#include "../Game/GameInclude.h"

namespace Engine
{
	class EngineCore
	{
	public: 
		EngineCore() {};
		void Start(const char* windowName, int width, int height, const char* defaultFontPath);
	private:
        sf::Event event;
		sf::RenderWindow window;
		std::vector<Object*> gameObjects;
		// Seperate list for UI objects so we can render them easily on top of the rest
		std::vector<Object*> uiObjects;

		// Vector that holds the objects that need to be removed form the game
		std::vector<Object*> toRemoveObjects;

		sf::Sprite m_background;
		sf::Texture m_backgroundTex;
		const char* m_backgroundPath = "Assets/Background.png";

		sf::Font m_defaultFont;
		int objectCount = 0;


		// Objects placed here need to be passed to other classes, so definitions are here
		UIElement playerHungerBarText;
		UIElement playerHungerBar;
		FoodSpawner foodSpawner;
		EnemySpawner enemySpawner;

		void Update();
		void Shutdown();
	};
}
