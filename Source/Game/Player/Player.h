#pragma once
#include <Object/object.h>
#include <iostream>

class Player : public Engine::Object
{
	void Start(sf::RenderWindow* window) override;
	void Update() override;
	void Shutdown() override;
};
