#pragma once
#include <Object/object.h>
#include <iostream>

class Player : public Engine::Object
{
public:
	Player(Engine::Transform transform, bool hasCollision) : Object(transform, hasCollision) {};

private:
	void Start(sf::RenderWindow* window) override;
	void Update() override;
	void Shutdown() override;
};
