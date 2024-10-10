#pragma once
#include <Object/object.h>
#include <string>
class UIElement : public Engine::Object 
{
public:
	UIElement() {};
	UIElement(Engine::Transform transform, bool hasCollision, const char* spritePath, sf::Font* font) 
		: Object(transform, hasCollision, spritePath),  m_fontRef(font){};
	void SetText(std::string text);
private:
	void Start(sf::RenderWindow* window, std::vector<Object*>* objectList) override;
	void Update() override;
	void Shutdown() override;

private:
	sf::Font* m_fontRef;
	sf::Text m_text;
};

