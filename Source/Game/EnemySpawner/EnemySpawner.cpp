#include "EnemySpawner.h"
#include "../Enemy/Enemy.h"
#include <Time/Time.h>
#include <Random/Random.h>

using namespace Engine;

void EnemySpawner::PostUpdate()
{
    if (m_tempObjectList.size() != 0)
    {
        std::copy(m_tempObjectList.begin(), m_tempObjectList.end(), std::back_inserter(*m_gameObjectRef));
        m_tempObjectList.clear();
    }
}

void EnemySpawner::Start(sf::RenderWindow* window, std::vector<Object*>* objectList)
{
    Object::Start(window, objectList);
}

void EnemySpawner::Update()
{
    SpawnEnemy();
}

void EnemySpawner::Shutdown()
{
    Object::Shutdown();
}

void EnemySpawner::SpawnEnemy()
{
    m_timeInterval += Engine::Time::deltaTime; 

    if (m_timeInterval > 0.3)
    {
        if (Engine::Random::RandomRange(2, 3) == 3)
        {
            //std::cout << "spawned food\n";
            Enemy* enemyToAdd = new Enemy(Transform(Vector2(Random::RandomRange(250, 1300), Random::RandomRange(100, 700)), 0, Vector2(0.3, 0.3)), true);
            m_tempObjectList.insert(m_tempObjectList.end(), enemyToAdd);
            enemyToAdd->Start(m_window, m_gameObjectRef);
            enemyToAdd->SetTag("Enemy");
        }
        m_timeInterval = 0;
    }
}
