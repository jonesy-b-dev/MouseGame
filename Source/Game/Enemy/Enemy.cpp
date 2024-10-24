#include "Enemy.h"
#include <Time/Time.h>
#include <iostream>

using namespace Engine;

void Enemy::Start(sf::RenderWindow* window, std::vector<Object*>* objectList)
{
	spritePath = "Assets/Cat.png";

	// Set first target positon
	currentTarget = FindNewPosition();
	Object::Start(window, objectList);
}

void Enemy::Update()
{
	// Find new position when MoveToNewPosition returns true, this is when the enemy is at its target

	if (MoveToNewPosition(currentTarget))
	{
        m_elapsedTime += Engine::Time::deltaTime;
        if (m_elapsedTime >= m_waitTime)
        {
		    currentTarget = FindNewPosition();
            // Generate a new wait time
            m_waitTime = Engine::Random::RandomRange(1, 3);
        }
	}
	Object::Update();
}

void Enemy::Shutdown()
{
	Object::Shutdown();
}

Engine::Vector2 Enemy::FindNewPosition()
{
	return Engine::Vector2(Random::RandomRange(250, 1200), Random::RandomRange(50, 750));
}

// Lerp to new position
bool Enemy::MoveToNewPosition(Engine::Vector2 targetPosition)
{
    // Calculate the direction from the current position to the target position
    Engine::Vector2 direction = targetPosition.Subtract(transform.position);

    // Get the distance to the target
    float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    float angleInRadians = std::atan2(direction.y, direction.x);
    float inDegrees = angleInRadians * (180.0f / 3.1415926535);
	transform.rotation = angleInRadians * (180.0f / 3.1415926535); // Transform to degrees

    // Normalize the direction vector
    if (distance > 0)
    {
        direction.x /= distance;
        direction.y /= distance;
    }

    // If the enemy is close enough to the target, stop moving and return true (to find a new position)
    if (distance < Engine::Random::RandomRange(6, 12)) // Amount of pixels
    {
        return true;
    }

    // Move towards the target
    transform.position.x += direction.x * m_speed * distance * Engine::Time::deltaTime;
    transform.position.y += direction.y * m_speed * distance * Engine::Time::deltaTime;

    // Continue moving (return false)
    return false;
}


