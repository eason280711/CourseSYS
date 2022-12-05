#pragma once 

namespace Engine {

    class __declspec(dllexport) Application
    {
    public:
        Application();
        ~Application();

        void Run();
        void Init();
        void ShotDown();
    };

    Application* CreateApplication();
}