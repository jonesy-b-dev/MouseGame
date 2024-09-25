#include "engine.h"
#include <../Game/Player/Player.h>

void Engine::EngineCore::Start()
{
    Player player;
    gameObjects.insert(gameObjects.begin(), &player);

    shape = sf::CircleShape(100.f);
    window.create(sf::VideoMode(1300, 800), "SFML works!");
    for each (Object* object in gameObjects)
    {
        object->Start();
    }
    shape.setFillColor(sf::Color::Green);

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

        for each (Object* object in gameObjects)
        {
            object->Update();
        }

        window.clear();
        window.draw(shape);
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
