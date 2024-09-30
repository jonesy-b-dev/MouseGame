#pragma once
#include <vector>
#include <Object/object.h>

class FoodSpawner : public Engine::Object
{
public:
	//FoodSpawner(Engine::Transform transform, bool hasCollision, std::vector<Object> gameObjects) : Object(transform, hasCollision), gameObjectRef(gameObjects) {};
	FoodSpawner(Engine::Transform transform, bool hasCollision) : Object(transform, hasCollision) {};

private:
	std::vector<Object>* m_gameObjectRef;
	void Start(sf::RenderWindow* window) override;
	void Update() override;
	void Shutdown() override;


	// Gameplay properties
	void SpawnFood();

};

