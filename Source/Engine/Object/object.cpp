#include "object.h"
#include <iostream>
void Engine::Object::Start()
{
	std::cout << "Created object";
}

void Engine::Object::Update()
{
	std::cout << "Updated object\n";
}

void Engine::Object::Shutdown()
{
	std::cout << "Shutdown object";
}
