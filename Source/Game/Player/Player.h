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


	// Gameplay variables
public:
private:
	float m_speed = 140;
	float m_health = 100;
	void HandleInput();
};
