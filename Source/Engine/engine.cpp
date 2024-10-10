#include "engine.h"
#include <Time/Time.h>
#include <algorithm>
#include <iostream>

using namespace Engine;

void Engine::EngineCore::Start(const char* windowName, int width, int height, const char* defaultFontPath)
{
    // Load font
    if (!m_defaultFont.loadFromFile(defaultFontPath)) std::cerr << "Failed to load font\n";

    // Reserve space in the vectors because we know before how many items it will have initialy
    gameObjects.reserve(2);
    uiObjects.reserve(2);

    // Create game objects
    Player player(Transform(Vector2(200, 200), 0, Vector2(0.2, 0.2)), true, &playerHungerBar);
    foodSpawner = FoodSpawner(Transform(Vector2(0, 0), 0, Vector2(1, 1)), false);

    // Add objects to the object vector
    gameObjects.insert(gameObjects.end(), &foodSpawner);
    gameObjects.insert(gameObjects.end(), &player);

    // Create UI objects
    UIElement playerHungerBarBG(Transform(Vector2(10, 10), 0, Vector2(1, 1)), false, "Assets/UI/HungerBackGroundBar.png", &m_defaultFont);
    playerHungerBar = UIElement(Transform(Vector2(15, 15), 0, Vector2(1, 1)), false, "Assets/UI/HungerProgressBar.png", &m_defaultFont);

    // Add UI objects to the UI vector
    uiObjects.insert(uiObjects.end(), &playerHungerBarBG);
    uiObjects.insert(uiObjects.end(), &playerHungerBar);

    window.create(sf::VideoMode(width, height), windowName);

    for each (Object* gameObject in gameObjects)
    {
        gameObject->Start(&window, &gameObjects);
    }
    objectCount = gameObjects.size();

    for each (Object* uiObject in uiObjects)
    {
        uiObject->Start(&window, &gameObjects);
    }

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

        Engine::Time::UpdateTime();

        window.clear();

        // Render background first
        window.draw(m_background);
        
        // Call update for all the objects in the game (including rendering the items)
        for each (Object* gameObject in gameObjects)
        {
            gameObject->Update();
            if (gameObject->deletionMark)
            {
                toRemoveObjects.push_back(gameObject);
            }
        }

        // Same for UI
        for each (Object* uiObject in uiObjects)
        {
            uiObject->Update();
        }

        // Call post update functions here: 
        foodSpawner.PostUpdate();


        // Remove all objects from the list that have been marked for removal
        for each (Object* removedObject in toRemoveObjects)
        {
            auto it = std::find(gameObjects.begin(), gameObjects.end(), removedObject);
            gameObjects.erase(it);
            delete removedObject;
        }

        // Clear the vector of removed items
        toRemoveObjects.clear();

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

    for each (Object* uiObject in uiObjects)
    {
        uiObject->Shutdown();
    }
}
