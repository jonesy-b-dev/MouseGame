#include "object.h"
#include "engine.h"
#include <iostream>

void Engine::Object::Start(sf::RenderWindow* window)
{
	m_window = window;
	// Check if a sprite path has been provided if yes load thetexture
	if (spritePath != NULL)
	{
		if (!texture.loadFromFile(spritePath))
		{
			std::cerr << "Failed to load image\n";
			return;
		}
		sprite.setTexture(texture);
	}
	// Otherwise object has no sprite
	std::cout << "Created object";
}

void Engine::Object::Update()
{
	//std::cout << "Updated object\n";
	sprite.setPosition(transform.position.x, transform.position.y);
	sprite.setScale(transform.scale.x, transform.scale.y);
	m_window->draw(sprite);
}

void Engine::Object::Shutdown()
{
	std::cout << "Shutdown object";
}

void Engine::Object::Collision()
{
	
}
