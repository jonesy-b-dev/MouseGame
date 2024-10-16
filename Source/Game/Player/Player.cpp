#include "Player.h"
#include <math.h>
#include <Time/Time.h>
#include <iostream>

void Player::Start(sf::RenderWindow* window, std::vector<Object*>* objectList)
{
	// Add spritepath first before we call bassclass start
	SetTag("Mouse");
	spritePath = "Assets/MainMouse.png";

	if (!m_soundBuffer.loadFromFile("Assets/Audio/PickupFood.ogg"))
	{
	   std::cerr << "Failed to load audio file of player\n";
	}
	m_pickUpSound.setBuffer(m_soundBuffer);

	Object::Start(window, objectList);
	//std::cout << "Player start\n";
}
void Player::Update()
{
	// Always render the object
	Object::Update();

	if (m_isDead) return;
	// Only execute when player alive
	m_currentSpeed = m_defaultSpeed * (std::powf(m_reductionValue, m_foodinventory));
	HandleInput();

	// Collision
	Object* foodObj = Object::CollidesWith("Food");
	if (foodObj != false)
	{
		m_pickUpSound.play();
		std::cout << "Collide" << std::endl;
		m_foodinventory++;
		foodObj->deletionMark = true;
	}
	Object* enemyObj = Object::CollidesWith("Enemy");
	if (enemyObj != false)
	{
		if (!m_isCollidingWithEnemy)
		{
			m_isCollidingWithEnemy = true;
			std::cout << "Collide enemy" << std::endl;
			m_health -= 20;
		}
	}
	else { m_isCollidingWithEnemy = false; }

	UpdateHunger();
	// Update health bar UI
	m_HealthBarRef->transform.scale.x = m_health / 100;

	if (m_health <= 0) Death();

	//std::cout << "Player update\n";
}
void Player::Shutdown()
{
	Object::Shutdown();
	//std::cout << "Player shut\n";
}

void Player::Death()
{
	UpdateTexture("Assets/MainMouseDead.png");
	m_isDead = true;
	std::cout << "Player died\n";
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

void Player::UpdateHunger()
{
	m_hungerTimer += Engine::Time::deltaTime;
	if (m_hungerTimer >= m_hungerSpeed)
	{
		m_hunger--;
		m_hungerTimer = 0;
		if (m_hunger == 0)
		{
			Death();
		}
	}
	m_HungerbarRef->transform.scale.x = m_hunger / 100;
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
        if (!m_keyEPressed)
        {
            Eat();
            m_keyEPressed = true;  // Mark key as pressed
        }
    }
    else m_keyEPressed = false;  // Reset when the key is released
}
