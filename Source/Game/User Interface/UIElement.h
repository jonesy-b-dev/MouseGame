#pragma once
#include <Object/object.h>
class UIElement : public Engine::Object 
{
public:
	UIElement() {};
	UIElement(Engine::Transform transform, bool hasCollision, const char* spritePath) : Object(transform, hasCollision, spritePath) {};
private:
	void Start(sf::RenderWindow* window, std::vector<Object*>* objectList) override;
	void Update() override;
	void Shutdown() override;

};

