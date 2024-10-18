#include "Family.h"
#include <Time/Time.h>

void Family::Start(sf::RenderWindow* window, std::vector<Object*>* objectList)
{
	spritePath = "Assets/House.png";
	
	// Set origin to center left
	sf::Vector2u textureSize = texture.getSize();
	sprite.setOrigin(0, textureSize.y / 2);

	Object::Start(window, objectList);
}

void Family::Update()
{
	UpdateHunger();
	Object::Update();
}

void Family::Shutdown()
{
	Object::Shutdown();
}

void Family::DeliverFood(int amount)
{
	m_hunger += amount * m_hungerIncrement;
	if (m_hunger > 100) m_hunger = 100;
}

void Family::UpdateHunger()
{
	m_hungerTimer += Engine::Time::deltaTime;
	if (m_hungerTimer >= m_hungerSpeed)
	{
		m_hunger--;
		m_hungerTimer = 0;
		if (m_hunger == 0)
		{
			//Death();
		}
	}
	m_hungerbarRef->transform.scale.x = m_hunger / 100;
}
