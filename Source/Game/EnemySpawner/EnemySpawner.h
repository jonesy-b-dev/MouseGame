#pragma once
#include <Object/object.h>
class EnemySpawner : public Engine::Object
{
public:
	EnemySpawner() {};
	EnemySpawner(Engine::Transform transform, bool hasCollision) : Object(transform, hasCollision) {};
	void PostUpdate();
	
private:
	std::vector<Object*> m_tempObjectList;
	void Start(sf::RenderWindow* window, std::vector<Object*>* objectList) override;
	void Update() override;
	void Shutdown() override;


	// Gameplay properties
private:
	void SpawnEnemy();
	float m_timeInterval = 0;
};

