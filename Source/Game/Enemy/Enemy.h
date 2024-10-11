#pragma once
#include <Object/object.h>
#include <Random/Random.h>

class Enemy : public Engine::Object
{
public:
	Enemy() {};
	Enemy(Engine::Transform transform, bool hasCollision) : Object(transform, hasCollision) {};
	void Start(sf::RenderWindow* window, std::vector<Object*>* objectList) override;
	
private:
	void Update() override;
	void Shutdown() override;

	// Gameplay properties
private:
	float m_speed = 0.5;
	bool test = false;

	// Timeing variables for waiting inbetween moving
	float m_waitTime = Engine::Random::RandomRange(1, 3);
	float m_elapsedTime = 0;
	Engine::Vector2 currentTarget;
	Engine::Vector2 FindNewPosition();
	bool MoveToNewPosition(Engine::Vector2 position);
};

