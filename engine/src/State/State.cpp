#include "State.h"
#include "Utils/Log.h"
#include "StateEvent.h"

#include "pch.h"

namespace Engine {
    State* StateManager::CurState;

    void StateManager::Update(int code)
    {
        switch (code)
        {
        case 0:
            CurState->setName(LoginState::ToString());
            CurState->setTransList(LoginState::GetTransList());
            break;
        case 1:
            CurState->setName(HomePageState::ToString());
            CurState->setTransList(HomePageState::GetTransList());
            break;
        case 2:
            CurState->setName(CourseListState::ToString());
            CurState->setTransList(CourseListState::GetTransList());
            break;
        case 3:
            CurState->setName(OwnCourseState::ToString());
            CurState->setTransList(OwnCourseState::GetTransList());
            break;
        default:
            break;
        }
        return;
    }

    void StateManager::startUp()
    {
        LoginState::Init();
        HomePageState::Init();
        CourseListState::Init();
		OwnCourseState::Init();

        CurState = new State;
        
        Update(0);

    }

    void StateManager::shutDown()
    {

    }

    std::string fmt(std::string At, std::string Msg)
    {
        At.resize(15, ' ');
		return "[" + At + "] " + Msg;
    }

    void StateManager::Tick()
    {
        int input;

        ENGINE_CORE_TRACE("{0}", fmt(StateManager::GetCurState()->getName(),"Action code:"));
		
        auto TransList = StateManager::GetCurState()->GetTransList();
        for(int i = 0;i < TransList.size();i++)
        {
            std::cout << fmt(TransList[i]->ToString(), "key: " + std::to_string(i)) << std::endl;
        }

		std::cout << "Pick an action:";
        std::cin >> input;
        
        if(input >= TransList.size() || input < 0)
        {
            ENGINE_CORE_ERROR("{0}", "Input type Error!");
            exit(3);
        }

        if(TransList[input]->Handle())
        {
            ENGINE_CORE_INFO("{0}", "Event handle success!");
            Update(TransList[input]->NextStateCode());
        }
        else
        {
            ENGINE_CORE_ERROR("{0}", "Event handle failed!");
        }

    }
}