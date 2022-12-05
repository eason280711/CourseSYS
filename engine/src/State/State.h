#pragma once
#include "Core/Core.h"
#include "Event/Event.h"
#include "pch.h"

namespace Engine {
    class State
    {
    public:
        void Init() {};
        void Transition() {};
		
        std::string getName() {return Name;};
        void setName(std::string name) { Name = name; };

        std::vector<Event*> GetTransList() {return TransList;};
        void setTransList(std::vector<Event*> list) { TransList = list; };
    private:
        std::string Name = "State";
        std::vector<Event*> TransList;
    };

    class StateManager : public Engine::RuntimeModule
    {
    public:
        ~StateManager() {};

        static void startUp();
        static void shutDown();
        static void Tick();

        static void Update(int code);

        inline static State*& GetCurState() { return CurState;}
    private:
        static State* CurState;
    };
}