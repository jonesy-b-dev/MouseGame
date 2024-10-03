#pragma once
#include <Object/Object.h>

class UI_PlayerHunger : public Engine::Object
{
public:
	UI_PlayerHunger(Engine::Transform transform, bool hasCollision) : Object(transform, hasCollision) {};

private:
	void Start(sf::RenderWindow* window) override;
	void Update() override;
	void Shutdown() override;

	
};

