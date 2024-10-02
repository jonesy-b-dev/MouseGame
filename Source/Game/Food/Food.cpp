#include "Food.h"
#include <iostream>

void Food::Start(sf::RenderWindow* window)
{
	spritePath = "Assets/Food.png";
	Object::Start(window);
}

void Food::Update()
{
	Object::Update();
}

void Food::Shutdown()
{
	Object::Shutdown();
}
