#include "engine.h"

void Engine::EngineCore::Start()
{
    shape = sf::CircleShape(100.f);
    window.create(sf::VideoMode(200, 200), "SFML works!");
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

        window.clear();
        window.draw(shape);
        window.display();
    }
    Shutdown();
}

void Engine::EngineCore::Shutdown()
{
}
