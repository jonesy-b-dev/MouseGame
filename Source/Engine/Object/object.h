#pragma once
#include <string>
#include <vector>
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
		virtual void Start(sf::RenderWindow* window, std::vector<Object*>* objectList);
		virtual void Update();
		virtual void Shutdown();
		void SetTag(std::string tagName) { tag = tagName; }
		std::string GetTag() { return tag; }
		
	protected:
		bool m_HasCollision;
		const char* spritePath = NULL;
		sf::Texture texture;
		sf::Sprite sprite;
		sf::RenderWindow* m_window;
		std::vector<Object*>* m_gameObjectRef;
		std::string tag;
		virtual Engine::Object* CollidesWith(std::string tagToCompare);
	};
}
