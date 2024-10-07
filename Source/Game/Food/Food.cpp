#include "Food.h"
#include <iostream>

void Food::Start(sf::RenderWindow* window, std::vector<Object*>* objectList)
{
	spritePath = "Assets/Food.png";
	Object::Start(window, objectList);
}

void Food::Update()
{
	Object::Update();
}

void Food::Shutdown()
{
	Object::Shutdown();
}
