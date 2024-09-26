#include "engine.h"
#include <../Game/Player/Player.h>
using namespace Engine;

void Engine::EngineCore::Start(const char* windowName, int width, int height)
{
    Player player(Transform(Vector2(5, 5), 0, Vector2(1, 1)), true);

    gameObjects.insert(gameObjects.begin(), &player);

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
