#pragma once
#include <vector>
#include <Object/object.h>
#include <Transform/Transform.h>
#include <Vector2/Vector2.h>

class FoodSpawner : public Engine::Object
{
public:
	FoodSpawner() {};
	FoodSpawner(Engine::Transform transform, bool hasCollision) : Object(transform, hasCollision) {};
	void PostUpdate();
	
private:
	std::vector<Object*> m_tempObjectList;
	void Start(sf::RenderWindow* window, std::vector<Object*>* objectList) override;
	void Update() override;
	void Shutdown() override;


	// Gameplay properties
private:
	void SpawnFood();
	float m_timeInterval = 0;
};
