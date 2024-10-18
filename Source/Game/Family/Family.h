#pragma once
#include <Object/object.h>
#include <User Interface/UIElement.h>

class Family : public Engine::Object
{
public:
	Family() {};
	Family(Engine::Transform transform, bool hasCollision, Engine::UIElement* hungerBar)
		: Object(transform, hasCollision),
		m_hungerbarRef(hungerBar)
	{};

	
private:
	std::vector<Object*> m_tempObjectList;
	void Start(sf::RenderWindow* window, std::vector<Object*>* objectList) override;
	void Update() override;
	void Shutdown() override;


	// Gameplay properties
public:
	float m_hunger = 100;
	void DeliverFood(int amount);

private:
	float m_hungerTimer = 0;
	float m_hungerSpeed = 0.5;
	float m_hungerIncrement = 10;
	Engine::UIElement* m_hungerbarRef;
	void UpdateHunger();

};

