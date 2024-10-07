#pragma once
#include <Object/object.h>

class Player : public Engine::Object
{
public:
	Player(Engine::Transform transform, bool hasCollision) : Object(transform, hasCollision) {};

private:
	void Start(sf::RenderWindow* window, std::vector<Object*>* objectList) override;
	void Update() override;
	void Shutdown() override;

	// Gameplay properties
private:
	bool m_isSafe = true;
	float m_hunger = 10;
	float m_speed = 140;
	float m_health = 100;
	int m_foodinventory = 10;
	bool keyEPressed = false;
	void Death();
	void Eat();
	void HandleInput();
};
