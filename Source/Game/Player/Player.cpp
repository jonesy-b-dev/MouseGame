#include "Player.h"
#include <math.h>
#include <Time/Time.h>
#include <iostream>

void Player::Start(sf::RenderWindow* window, std::vector<Object*>* objectList)
{
	// Add spritepath first before we call bassclass start
	SetTag("Mouse");
	spritePath = "Assets/MainMouse.png";
	Object::Start(window, objectList);
	//std::cout << "Player start\n";
}
void Player::Update()
{
	m_currentSpeed = m_defaultSpeed * (std::powf(m_reductionValue, m_foodinventory));
	HandleInput();
	Object* collidedObject = Object::CollidesWith("Food");
	if (collidedObject != false)
	{
		std::cout << "Collide" << std::endl;
		m_foodinventory++;
		collidedObject->deletionMark = true;
	}
	m_HungerbarRef->transform.scale.x = m_hunger / 100;

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
		transform.position.y -= m_currentSpeed * Engine::Time::deltaTime;
		transform.rotation = 270;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		transform.position.x -= m_currentSpeed * Engine::Time::deltaTime;
		transform.rotation = 180;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		transform.position.y += m_currentSpeed * Engine::Time::deltaTime;
		transform.rotation = 90;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		transform.position.x += m_currentSpeed * Engine::Time::deltaTime;
		transform.rotation = 0;
	}

	/// Other inputs
	// Eat
	// This can also be done usng Events, but ill need to pass in the whole event object into the player
	// this is simply easier to do and wont hurt performance anyways. Might change in future when needed since its not really scalable.
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
