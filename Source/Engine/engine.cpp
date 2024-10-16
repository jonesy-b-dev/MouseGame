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
    gameObjects.reserve(4);
    uiObjects.reserve(6);

    // Create game objects
    Player player(Transform(Vector2(200, 200), 0, Vector2(0.2, 0.2)), true, &playerHungerBar, &playerHealthBar);
    foodSpawner = FoodSpawner(Transform(Vector2(0, 0), 0, Vector2(1, 1)), false);
    enemySpawner = EnemySpawner(Transform(Vector2(100, 100), 0, Vector2(1, 1)), true);
    Family family(Transform(Vector2(0, 420), 0, Vector2(1, 1)), true, &familyHungerBar);
    family.SetTag("Family");

    // Add objects to the object vector
    gameObjects.insert(gameObjects.end(), &foodSpawner);
    gameObjects.insert(gameObjects.end(), &player);
    gameObjects.insert(gameObjects.end(), &enemySpawner);
    gameObjects.insert(gameObjects.end(), &family);

    // Create UI objects

    // Hunger
    UIElement playerHungerBarBG(Transform(Vector2(1119, 10), 0, Vector2(1, 1)), false, "Assets/UI/HungerBackGroundBar.png", &m_defaultFont);
    playerHungerBar = UIElement(Transform(Vector2(1124, 15), 0, Vector2(1, 1)), false, "Assets/UI/HungerProgressBar.png", &m_defaultFont);
    UIElement playerHungerBarText(Transform(Vector2(1164, 16), 0, Vector2(1, 1)), false, NULL, &m_defaultFont);
    playerHungerBarText.SetText("Hunger");


    // Health
    UIElement playerHealthBarBG(Transform(Vector2(939, 10), 0, Vector2(1, 1)), false, "Assets/UI/HungerBackGroundBar.png", &m_defaultFont);
    playerHealthBar = UIElement(Transform(Vector2(944, 15), 0, Vector2(1, 1)), false, "Assets/UI/HealthProgressBar.png", &m_defaultFont);
    playerHealthBarText = UIElement(Transform(Vector2(984, 16), 0, Vector2(1, 1)), false, NULL, &m_defaultFont);
    playerHealthBarText.SetText("Health");

    // Family hunger
    UIElement familyHungerBarBG(Transform(Vector2(10, 10), 0, Vector2(1, 1)), false, "Assets/UI/HungerBackGroundBar.png", &m_defaultFont);
    familyHungerBar = UIElement(Transform(Vector2(15, 15), 0, Vector2(1, 1)), false, "Assets/UI/FamHungerProgressBar.png", &m_defaultFont);
    UIElement familiyHungerBarText(Transform(Vector2(55, 16), 0, Vector2(1, 1)), false, NULL, &m_defaultFont);
    familiyHungerBarText.SetText("Hunger");


    // Add UI objects to the UI vector
    // Hunger
    uiObjects.insert(uiObjects.end(), &playerHungerBarBG);
    uiObjects.insert(uiObjects.end(), &playerHungerBar);
    uiObjects.insert(uiObjects.end(), &playerHungerBarText);

    // Health
    uiObjects.insert(uiObjects.end(), &playerHealthBarBG);
    uiObjects.insert(uiObjects.end(), &playerHealthBar);
    uiObjects.insert(uiObjects.end(), &playerHealthBarText);

    // Fam Hunger
    uiObjects.insert(uiObjects.end(), &familyHungerBarBG);
    uiObjects.insert(uiObjects.end(), &familyHungerBar);
    uiObjects.insert(uiObjects.end(), &familiyHungerBarText);
    
    // Create the window
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
        enemySpawner.PostUpdate();


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
