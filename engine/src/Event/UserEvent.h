#pragma once
#include "Event.h"

namespace Engine {

    class UserLogInEvent : public Event
    {
        std::string ToString() {return "UserLogIn";};
        int NextStateCode() {return 1;};
        bool Handle() override;
    };

    class UserSignUpEvent : public Event
    {
        std::string ToString() {return "UserSignUp";};
        int NextStateCode() {return 0;};
        bool Handle() override;
    };

    class UserRePassEvent : public Event
    {
        std::string ToString() {return "UserRePass";};
        int NextStateCode() {return 0;};
        bool Handle() override;
    };

    class UserFGPassEvent : public Event
    {
        std::string ToString() {return "UserFGPass";};
        int NextStateCode() {return 0;};
        bool Handle() override;
    };

    class QuitEvent : public Event
    {
        std::string ToString() {return "Quit";};
        int NextStateCode() {return 1;};
        bool Handle() override;
    };
}