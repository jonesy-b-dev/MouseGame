#include "engine.h"
#include "../Game/Player/Player.h"
#include "../Game/Food/Food.h"
#include <Time/Time.h>

using namespace Engine;

void Engine::EngineCore::Start(const char* windowName, int width, int height)
{
    gameObjects.reserve(2);
    //uiObjects.reserve(2);
    Player player(Transform(Vector2(200, 200), 0, Vector2(0.2, 0.2)), true);
    Food food(Transform(Vector2(200, 200), 2, Vector2(1, 1)), true);

    gameObjects.insert(gameObjects.end(), &food);
    gameObjects.insert(gameObjects.end(), &player);

    window.create(sf::VideoMode(width, height), windowName);
    for each (Object* object in gameObjects)
    {
        object->Start(&window);
    }

    Update();
}

void Engine::EngineCore::Update()
{
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Update the time class
        Engine::Time::UpdateTime();

        window.clear();

        for each (Object* object in gameObjects)
        {
            object->Update();
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
