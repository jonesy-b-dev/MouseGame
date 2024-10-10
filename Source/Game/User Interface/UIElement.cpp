#include "UIElement.h"

void UIElement::SetText(std::string text)
{
	m_text.setString(text);
}

void UIElement::Start(sf::RenderWindow* window, std::vector<Object*>* objectList)
{
	Object::Start(window, objectList);
	sprite.setOrigin(0, 0);
}

void UIElement::Update()
{
	Object::Update();
}

void UIElement::Shutdown()
{
	Object::Shutdown();
}
