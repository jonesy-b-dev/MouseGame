#pragma once
#include <vector>
#include <Object/object.h>
#include <Transform/Transform.h>
#include <Vector2/Vector2.h>

class FoodSpawner : public Engine::Object
{
public:
	//FoodSpawner() {};
	FoodSpawner() : Object(Engine::Transform(), false), m_gameObjectRef(nullptr) {}
	FoodSpawner(Engine::Transform transform, bool hasCollision, std::vector<Object*>& gameObjects)
		: Object(transform, hasCollision), m_gameObjectRef(&gameObjects) {};
	void PostUpdate();
	
private:
	std::vector<Object*>* m_gameObjectRef;
	std::vector<Object*> m_tempObjectList;
	void Start(sf::RenderWindow* window) override;
	void Update() override;
	void Shutdown() override;


	// Gameplay properties
private:
	void SpawnFood();
	float m_timeInterval = 0;
};
