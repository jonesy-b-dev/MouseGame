#include "Family.h"
#include <Time/Time.h>
#include "../Game/Player/Player.h"
#include <iostream>

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
	if (m_hunger == 0)
	{
	    // Find the first Player in the vector using a lamda function that checks if the found object can be casted to a Player type
	    auto it = std::find_if(m_gameObjectRef->begin(), m_gameObjectRef->end(), [](Object* obj) {
	        return dynamic_cast<Player*>(obj) != nullptr; // return true if the cast was succesfull
	    });
	
		// If the find_if didnt find anything it returns m_gameObjects->end() so check if thats the case
	    if (it != m_gameObjectRef->end()) 
		{
	        Player* player = dynamic_cast<Player*>(*it);
	        if (!player->isDead) 
			{
	            player->Death();  // Now you can call Player-specific methods
	        }
	    }
		else 
		{
	        std::cout << "Player not found" << std::endl;
	    }
	}
	else if (m_hungerTimer >= m_hungerSpeed)
	{
		m_hunger--;
		m_hungerTimer = 0;
		m_hungerbarRef->transform.scale.x = m_hunger / 100;
	}
}
