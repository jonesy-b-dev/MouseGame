#include "UIElement.h"

void UIElement::SetText(std::string text)
{
	m_text.setFont(*m_fontRef);
	m_text.setString(text);
	m_text.setCharacterSize(24);
	m_text.setFillColor(sf::Color::White);
}

void UIElement::Start(sf::RenderWindow* window, std::vector<Object*>* objectList)
{
	Object::Start(window, objectList);
	sprite.setOrigin(0, 0);
}

void UIElement::Update()
{
	m_text.setPosition(transform.position.x, transform.position.y);
	m_text.setScale(transform.scale.x, transform.scale.y);
	m_text.setRotation(transform.rotation);

	Object::Update();
	m_window->draw(m_text);
}

void UIElement::Shutdown()
{
	Object::Shutdown();
}
