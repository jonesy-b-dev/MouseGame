#include "FoodSpawner.h"
#include <iostream>
#include <Time/Time.h>
#include <Random/Random.h>
#include <Transform/Transform.h>
#include <Vector2/Vector2.h>
#include "../Food/Food.h"

using namespace Engine;

void FoodSpawner::PostUpdate()
{
    if (m_tempObjectList.size() != 0)
    {
        std::copy(m_tempObjectList.begin(), m_tempObjectList.end(), std::back_inserter(*m_gameObjectRef));
        m_tempObjectList.clear();
    }
}

void FoodSpawner::Start(sf::RenderWindow* window, std::vector<Object*>* objectList)
{
    Object::Start(window, objectList);
}

void FoodSpawner::Update()
{
    SpawnFood();
}

void FoodSpawner::Shutdown()
{
}

void FoodSpawner::SpawnFood()
{
    m_timeInterval += Engine::Time::deltaTime; 

    if (m_timeInterval > 1)
    {
        if (Engine::Random::RandomRange(2, 3) == 3)
        {
            //std::cout << "spawned food\n";
            Food* foodToAdd = new Food(Transform(Vector2(Random::RandomRange(100, 1200), Random::RandomRange(100, 700)), 0, Vector2(0.1, 0.1)), true);
            m_tempObjectList.insert(m_tempObjectList.end(), foodToAdd);
            foodToAdd->Start(m_window, m_gameObjectRef);
            foodToAdd->SetTag("Food");
        }
        m_timeInterval = 0;
    }
}
