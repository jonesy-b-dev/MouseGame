#pragma once
#include <SFML/Graphics.hpp>
#include <Object/object.h>
#include <Transform/Transform.h>
#include <Vector2/Vector2.h>
#include "../Game/FoodSpawner/FoodSpawner.h"
#include "../Game/GameInclude.h"
#include <vector>

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
		// Inventory
		UIElement inventoryText;

		// Hunger
		UIElement playerHungerBar;

		//Health
		UIElement playerHealthBarText;
		UIElement playerHealthBar;

		// Score
		UIElement playerScoreText;

		// Family
		UIElement familyHungerBar;

		FoodSpawner foodSpawner;
		EnemySpawner enemySpawner;

		void Update();
		void Shutdown();
	};
}
