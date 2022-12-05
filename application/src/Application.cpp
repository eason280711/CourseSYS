#include <Engine.h>

Engine::Application* Engine::CreateApplication()
{
    return new Engine::Application();
}