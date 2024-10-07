#pragma once
#include "../Transform/Transform.h"
#include <SFML/Graphics.hpp>
namespace Engine
{
	class Object
	{
	public:
		Object() {};
		Object(Engine::Transform transform, bool hasCollision) : transform(transform),  m_HasCollision(hasCollision){};
		Transform transform;
		virtual void Start(sf::RenderWindow* window);
		virtual void Update();
		virtual void Shutdown();
		void SetTag(std::string tagName) { tag = tagName; }
		
	protected:
		bool m_HasCollision;
		const char* spritePath = NULL;
		sf::Texture texture;
		sf::Sprite sprite;
		virtual void Collision();
		sf::RenderWindow* m_window;
		std::string tag;
	};
}
