#include "Engine/engine.h"
using namespace Engine;

int main()
{
    EngineCore engine;

    engine.Start("Mouse Game", 1300, 800, "Assets/Fonts/Hey Comic.ttf");

    return 0;
}