#pragma once

extern Engine::Application* Engine::CreateApplication();

int main(int argc,char** argv)
{	
    auto app = Engine::CreateApplication();
    app->Init();
    app->Run();
    app->ShotDown();
    delete app;
}