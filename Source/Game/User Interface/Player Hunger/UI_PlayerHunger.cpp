#include "UI_PlayerHunger.h"

void UI_PlayerHunger::Start(sf::RenderWindow* window)
{
	spritePath = "Assets/UI/HungerProgressBar.png";
	Object::Start(window);
}

void UI_PlayerHunger::Update()
{
	Object::Update();
}

void UI_PlayerHunger::Shutdown()
{
	Object::Shutdown();
}
