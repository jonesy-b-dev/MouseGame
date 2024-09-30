#include "Player.h"
#include <Time/Time.h>
#include <iostream>

void Player::Start(sf::RenderWindow* window)
{
	// Add spritepath first before we call bassclass start
	spritePath = "Assets/MainMouse.png";
	Object::Start(window);
	std::cout << "Player start\n";
}
void Player::Update()
{
	HandleInput();
	Object::Update();
	//std::cout << "Player update\n";
}
void Player::Shutdown()
{
	Object::Shutdown();
	std::cout << "Player shut\n";
}

void Player::HandleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		transform.position.y -= m_speed * Engine::Time::deltaTime;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		transform.position.x -= m_speed * Engine::Time::deltaTime;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		transform.position.y += m_speed * Engine::Time::deltaTime;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		transform.position.x += m_speed * Engine::Time::deltaTime;
	}
}
