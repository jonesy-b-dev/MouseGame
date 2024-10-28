#include "object.h"
#include "engine.h"
#include <iostream>

void Engine::Object::Start(sf::RenderWindow* window, std::vector<Object*>* objectList)
{
	// Set references
	m_gameObjectRef = objectList;
	m_window = window;

	// Check if a sprite path has been provided if yes load thetexture
	if (spritePath != "")
	{
		if (!texture.loadFromFile(spritePath.string()))
		{
			std::cerr << "Failed to load image\n";
			return;
		}
		sprite.setTexture(texture);
	}
	// Otherwise object has no sprite
	// std::cout << "Created object";

	sprite.setPosition(transform.position.x, transform.position.y);
	sprite.setScale(transform.scale.x, transform.scale.y);
	sprite.setRotation(transform.rotation);

	// Set the origin to the center of the sprite
	sf::Vector2u textureSize = texture.getSize();
    sprite.setOrigin(textureSize.x / 2.0f, textureSize.y / 2.0f);
}

void Engine::Object::Update()
{
	//std::cout << "Updated object\n";
	sprite.setPosition(transform.position.x, transform.position.y);
	sprite.setScale(transform.scale.x, transform.scale.y);
	sprite.setRotation(transform.rotation);

	DrawCollisionBox();
	m_window->draw(sprite);
}

void Engine::Object::Shutdown()
{
	std::cout << "Shutdown object";
}

Engine::Object* Engine::Object::CollidesWith(std::string tagToCompare)
{
	// Instantly return when object doesnt have collision
	if (!m_HasCollision) return false;
	for each (Object* gameObject in *m_gameObjectRef)
	{
		if (gameObject->GetTag() == tagToCompare)
		{
			if (sprite.getGlobalBounds().intersects(gameObject->sprite.getGlobalBounds()))
			{
				return gameObject;
			}
		}
	}
	return false;
}

void Engine::Object::UpdateTexture(const char* pathToNewTexture)
{
	if (pathToNewTexture != NULL)
	{
		if (!texture.loadFromFile(pathToNewTexture))
		{
			std::cerr << "Failed to load image\n";
			return;
		}
		sprite.setTexture(texture);
	}
}

void Engine::Object::DrawCollisionBox()
{
    sf::FloatRect spriteBounds = sprite.getGlobalBounds();
    // Create a rectangle shape for the bounding box
    sf::RectangleShape boundingBox;
    boundingBox.setSize(sf::Vector2f(spriteBounds.width, spriteBounds.height));
    boundingBox.setPosition(spriteBounds.left, spriteBounds.top);
    boundingBox.setFillColor(sf::Color::Transparent);
    boundingBox.setOutlineColor(sf::Color::Red);
    boundingBox.setOutlineThickness(1.0f);

	m_window->draw(boundingBox);
}
