#include "engine.h"
#include "../Game/Player/Player.h"
#include "../Game/Food/Food.h"
#include "../Game/FoodSpawner/FoodSpawner.h"
#include <Time/Time.h>
#include <iostream>

using namespace Engine;

void Engine::EngineCore::Start(const char* windowName, int width, int height)
{
    gameObjects.reserve(2);
    //uiObjects.reserve(2);
    Player player(Transform(Vector2(200, 200), 0, Vector2(0.2, 0.2)), true);
    foodSpawner = FoodSpawner(Transform(Vector2(0, 0), 0, Vector2(1, 1)), false, gameObjects);

    gameObjects.insert(gameObjects.end(), &foodSpawner);
    gameObjects.insert(gameObjects.end(), &player);

    window.create(sf::VideoMode(width, height), windowName);

    for each (Object* object in gameObjects)
    {
        object->Start(&window);
    }
    objectCount = gameObjects.size();

    // Load and set background
    if (!m_backgroundTex.loadFromFile(m_backgroundPath))
    {
	    std::cerr << "Failed to load background image\n";
    }
    m_background.setTexture(m_backgroundTex);
    Update();
}

// Main while loop
void Engine::EngineCore::Update()
{
    while (window.isOpen())
    {
        // Close when the close event is called
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                EngineCore::Shutdown();
            }
        }

        // Update the time class
        Engine::Time::UpdateTime();

        window.clear();

        // Render background first
        window.draw(m_background);
        
        // Call update for all the objects in the game (including rendering the items)
        for each (Object* object in gameObjects)
        {
            object->Update();
        }

        // Same for UI

        // Call post update functions here: 
        foodSpawner.PostUpdate();

        // Check if the amount of objects has been changed, if yes make sure they all have the window object
        if (gameObjects.size() > objectCount)
        {
            for each (Object* object in gameObjects)
            {
                object->Start(&window);
                objectCount = gameObjects.size();
            }
        }

        window.display();
    }
    Shutdown();
}

void Engine::EngineCore::Shutdown()
{
    for each (Object* object in gameObjects)
    {
        object->Shutdown();
    }
}
