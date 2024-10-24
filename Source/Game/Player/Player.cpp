#include "Player.h"
#include <math.h>
#include <Time/Time.h>
#include <iostream>
#include "../Family/Family.h"

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

	if (m_health <= 0) Death();

	if (isDead) return;

	// Only execute when player alive
	m_currentSpeed = m_defaultSpeed * (std::powf(m_reductionValue, m_foodinventory));
	lastPosition = transform.position;
	HandleInput();

	// Rotate sprite towards way og moving
	Vector2 direction = transform.position.Subtract(lastPosition);

	// Check if they are both not 0 so the sprite doesnt rotate to 0deg when no input is provided
	if (direction.x != 0 || direction.y != 0)
	{
		float angleInRadians = std::atan2(direction.y, direction.x);
		transform.rotation = angleInRadians * (180.0f / 3.1415926535); // Transform to degrees
	}

	/// Collision
	// Food
	Object* foodObj = Object::CollidesWith("Food");
	if (foodObj != false)
	{
		m_pickUpSound.play();
		std::cout << "Collide" << std::endl;
		m_foodinventory++;
		m_inventoryCounterRef->SetText(std::to_string(m_foodinventory));
		foodObj->deletionMark = true;
		m_score++;
	}

	// Enemy
	Object* enemyObj = Object::CollidesWith("Enemy");
	if (enemyObj != false)
	{
		if (!m_isCollidingWithEnemy)
		{
			m_isCollidingWithEnemy = true;
			std::cout << "Collide enemy" << std::endl;
			m_health -= 10;
		}
	}
	else { m_isCollidingWithEnemy = false; }

	// Family
	Family* familyObj = dynamic_cast<Family*>(Object::CollidesWith("Family"));
	if (familyObj != false)
	{
		m_score += 5 * m_foodinventory;
		familyObj->DeliverFood(m_foodinventory);
		m_foodinventory = 0;
		m_inventoryCounterRef->SetText("o"); // when '0' set to 'o' because 0 is not in the font 
	}

	UpdateHunger();

	// Update health bar UI
	m_healthBarRef->transform.scale.x = m_health / 100;

	//std::string scoreText = "Score: " + std::to_string(m_score);
	m_playerScoreRef->SetText("Score: " + std::to_string(m_score));

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
	isDead = true;
	std::cout << "Player died\n";
}

void Player::Eat()
{
	if (m_foodinventory != 0)
	{
		m_foodinventory--;
		m_score++;
		m_hunger += 30;
		if (m_hunger > 100)
		{
			m_hunger = 100;
		}
		m_inventoryCounterRef->SetText(std::to_string(m_foodinventory));
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
	m_hungerbarRef->transform.scale.x = m_hunger / 100;
}

void Player::HandleInput()
{
	// Movement
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		transform.position.y -= m_currentSpeed * Engine::Time::deltaTime;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		transform.position.x -= m_currentSpeed * Engine::Time::deltaTime;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		transform.position.y += m_currentSpeed * Engine::Time::deltaTime;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		transform.position.x += m_currentSpeed * Engine::Time::deltaTime;
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
