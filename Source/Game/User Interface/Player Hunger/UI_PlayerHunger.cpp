#include "UI_PlayerHunger.h"

void UI_PlayerHunger::Start(sf::RenderWindow* window, std::vector<Object*>* objectList)
{
	spritePath = "Assets/UI/HungerProgressBar.png";
	Object::Start(window, objectList);
}

void UI_PlayerHunger::Update()
{
	Object::Update();
}

void UI_PlayerHunger::Shutdown()
{
	Object::Shutdown();
}
