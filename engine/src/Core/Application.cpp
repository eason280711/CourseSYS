#include "Application.h"
#include "Utils/DataBase.h"
#include "Utils/Log.h"
#include "State/StateEvent.h"
#include "Config/config.h"
#include "pch.h"

#include <leveldb/db.h>

using namespace std;

namespace Engine {
    Application::Application() {};
    Application::~Application() {};

    void Application::Run()
    {
        
        ENGINE_CORE_INFO("{0}", "Engine Ver 1.0.0 !");

        while (true)
        {
            StateManager::Tick();
        }
    };

    void Application::Init()
    {
        LogManager::startUp();
        StateManager::startUp();
    }

    void Application::ShotDown()
    {
        LogManager::shutDown();
        StateManager::shutDown();
    }
}