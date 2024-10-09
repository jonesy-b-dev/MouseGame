#include "UIElement.h"

void UIElement::Start(sf::RenderWindow* window, std::vector<Object*>* objectList)
{
	spritePath = "Assets/UI/HungerProgressBar.png";
	Object::Start(window, objectList);
}

void UIElement::Update()
{
	Object::Update();
}

void UIElement::Shutdown()
{
	Object::Shutdown();
}
