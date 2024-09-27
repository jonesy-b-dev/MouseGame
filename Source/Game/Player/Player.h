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
	bool m_isSafe = true;
	float m_hunger = 100;
	float m_speed = 140;
	float m_health = 100;
	int m_foodinventory = 0;
	void Death();
	void Eat();
	void HandleInput();
};
