#pragma once
#include <string>
#include <vector>
#include <filesystem>
#include "../Transform/Transform.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

namespace Engine
{
	class Object
	{
	public:
		Object() {};
		Object(Engine::Transform transform, bool hasCollision) : transform(transform),  m_HasCollision(hasCollision){};
		Object(Engine::Transform transform, bool hasCollision, std::filesystem::path spritePath) : transform(transform),  m_HasCollision(hasCollision), spritePath(spritePath) {};
		Transform transform;
		virtual void Start(sf::RenderWindow* window, std::vector<Object*>* objectList);
		virtual void Update();
		virtual void Shutdown();
		void SetTag(std::string tagName) { tag = tagName; }
		std::string GetTag() { return tag; }
		// When this is set to true the object will be removed when the frame is finished
		bool deletionMark = false;

		
	protected:
		bool m_HasCollision;
		std::filesystem::path spritePath = "";
		sf::Texture texture;
		sf::Sprite sprite;
		sf::RenderWindow* m_window;
		std::vector<Object*>* m_gameObjectRef;
		std::string tag;
		sf::SoundBuffer m_soundBuffer;

		virtual Engine::Object* CollidesWith(std::string tagToCompare);
		void UpdateTexture(const char* pathToNewTexture);
		void DrawCollisionBox();
	};
}
