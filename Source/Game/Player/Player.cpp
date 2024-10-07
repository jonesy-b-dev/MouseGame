#include "Player.h"
#include <Time/Time.h>
#include <iostream>

void Player::Start(sf::RenderWindow* window, std::vector<Object*>* objectList)
{
	// Add spritepath first before we call bassclass start
	spritePath = "Assets/MainMouse.png";
	Object::Start(window, objectList);
	//std::cout << "Player start\n";
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
	//std::cout << "Player shut\n";
}

void Player::Eat()
{
	if (m_foodinventory != 0)
	{
		m_foodinventory--;
		m_hunger += 30;
		if (m_hunger > 100)
		{
			m_hunger = 100;
		}
	}
	std::cout << m_hunger << " inv:" << m_foodinventory << "\n";
}

void Player::HandleInput()
{
	// Movement
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

	/// Other inputs
	// Eat
	// This can also be done usng Events, but ill need to pass in the whole event object into the player
	// this is simply easier to do and wont hurt performance anyways. Might change in future when needed.
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
    {
        if (!keyEPressed)
        {
            Eat();
            keyEPressed = true;  // Mark key as pressed
        }
    }
    else keyEPressed = false;  // Reset when the key is released
}
