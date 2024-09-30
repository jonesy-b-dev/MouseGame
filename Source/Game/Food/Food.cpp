#include "Food.h"
#include <iostream>

void Food::Start(sf::RenderWindow* window)
{
	spritePath = "Assets/Food.png";
	Object::Start(window);
	std::cout << "food start \n";
}

void Food::Update()
{
	std::cout << transform.position.x;
	Object::Update();
	std::cout << "Update fod\n";
}

void Food::Shutdown()
{
	Object::Shutdown();
}
