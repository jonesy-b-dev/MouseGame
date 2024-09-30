#pragma once
#include <Object/object.h>

class Food : public Engine::Object
{
public:
	Food(Engine::Transform transform, bool hasCollision) : Object(transform, hasCollision) {};

private:
	void Start(sf::RenderWindow* window) override;
	void Update() override;
	void Shutdown() override;


	// Gameplay properties
};

