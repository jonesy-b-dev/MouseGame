#pragma once
#include <Object/object.h>

class Food : public Engine::Object
{
public:
	Food(Engine::Transform transform, bool hasCollision) : Object(transform, hasCollision) {};
	void Start(sf::RenderWindow* window, std::vector<Object*>* objectList) override;

private:
	void Update() override;
	void Shutdown() override;


	// Gameplay properties
};

