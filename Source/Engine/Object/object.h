#pragma once
#include "../Transform/Transform.h"
#include <SFML/Graphics.hpp>
namespace Engine
{
	class Object
	{
	public:
		Transform transform;
		virtual void Start(sf::RenderWindow* window);
		virtual void Update();
		virtual void Shutdown();
		Object(Engine::Transform transform, bool hasCollision) : transform(transform),  m_HasCollision(hasCollision){};
	protected:
		bool m_HasCollision;
		const char* spritePath = NULL;
		sf::Texture texture;
		sf::Sprite sprite;
		virtual void Collision();
	private:
		sf::RenderWindow* m_window;
	};
}
