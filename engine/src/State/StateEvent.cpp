#pragma once
#include "StateEvent.h"
#include "Event/CourseEvent.h"
#include "Event/UserEvent.h"

namespace Engine {
    std::vector<Event*> LoginState::TransList;
    void LoginState::Init()
    {
        TransList.push_back(new UserLogInEvent());
        TransList.push_back(new UserSignUpEvent());
        TransList.push_back(new UserRePassEvent());
        TransList.push_back(new UserFGPassEvent());
    }
    void LoginState::Transition()
    {

    }

    std::vector<Event*> HomePageState::TransList;
    void HomePageState::Init()
    {
        TransList.push_back(new AddCourseEvent());
        TransList.push_back(new GetOwnCourseEvent());
        TransList.push_back(new SearchCourseEvent());
    }
    void HomePageState::Transition()
    {
        
    }

    std::vector<Event*> CourseListState::TransList;
    void CourseListState::Init()
    {
        TransList.push_back(new SearchCourseEvent());
        TransList.push_back(new QuitEvent());
    }
    void CourseListState::Transition()
    {
        
    }

    std::vector<Event*> OwnCourseState::TransList;
    void OwnCourseState::Init()
    {
        TransList.push_back(new QuitEvent());
    }
    void OwnCourseState::Transition()
    {
        
    }
}