#include "Time.h"

float Engine::Time::deltaTime = 0;
sf::Clock Engine::Time::clock;

void Engine::Time::UpdateTime()
{
	deltaTime = clock.restart().asSeconds();
}
