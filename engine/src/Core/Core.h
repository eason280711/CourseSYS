#pragma once

namespace Engine {

    class RuntimeModule
    {
    public:
        virtual ~RuntimeModule() {};

        virtual void startUp() = 0;
        virtual void shutDown() = 0;

        virtual void Tick() = 0;
    };
}