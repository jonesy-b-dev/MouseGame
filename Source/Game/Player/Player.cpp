#include "Player.h"

void Player::Start(sf::RenderWindow* window)
{
	// Add spritepath first before we call bassclass start
	spritePath = "Assets/MainMouse.png";
	Object::Start(window);
	std::cout << "Player start\n";
}
void Player::Update()
{
	Object::Update();
	//std::cout << "Player update\n";
}
void Player::Shutdown()
{
	Object::Shutdown();
	std::cout << "Player shut\n";
}
