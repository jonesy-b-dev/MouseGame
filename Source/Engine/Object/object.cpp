#include "object.h"
#include <iostream>
void Object::Start()
{
	std::cout << "Created object";
}

void Object::Update()
{
	std::cout << "Updated object\n";
}

void Object::Shutdown()
{
	std::cout << "Shutdown object";
}
