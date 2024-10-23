#pragma once
#include <Object/object.h>
#include <User Interface/UIElement.h>
using namespace Engine;

class Player : public Engine::Object
{
public:
	Player(Engine::Transform transform, bool hasCollision, UIElement* hungerBar, UIElement* healthBar, UIElement* inventoryCount)
		: Object(transform, hasCollision), 
		m_hungerbarRef(hungerBar), 
		m_healthBarRef(healthBar),
		m_inventoryCounterRef(inventoryCount) {};
		

private:
	void Start(sf::RenderWindow* window, std::vector<Object*>* objectList) override;
	void Update() override;
	void Shutdown() override;

	// Gameplay properties
public:
	void Death();
	bool isDead = false;

private:
	bool m_isSafe = true;
	float m_hunger = 100;
	UIElement* m_hungerbarRef;
	UIElement* m_healthBarRef;
	UIElement* m_inventoryCounterRef;


	// Current speed wil vary from value, default always stays the same
	float m_currentSpeed = 140;
	float m_defaultSpeed = 140;
	float m_reductionValue = 0.90; // With how much the speed is going to get multiplied for each item in the inventory

	float m_health = 100;
	bool m_isCollidingWithEnemy = false;
	int m_foodinventory = 0;
	bool m_keyEPressed = false;
	float m_hungerTimer = 0;
	float m_hungerSpeed = 0.5; // Amount of seconds hunger will go down by 1

	// Audio
	sf::Sound m_pickUpSound;
	void Eat();
	void UpdateHunger();
	void HandleInput();
};
