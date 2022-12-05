#pragma once
#include "State.h"
#include "Event/Event.h"

namespace Engine {

    class LoginState : public State
    {
    public:
        ~LoginState() {};
        static void Init();
        static void Transition();
        static std::string ToString() {return "LoginState";};

        inline static std::vector<Event*>& GetTransList() { return TransList;}
    private:
        static std::vector<Event*> TransList;
    };

    class HomePageState : public State
    {
    public:
        ~HomePageState() {};
        static void Init();
        static void Transition();
        static std::string ToString() {return "HomePageState";};

        inline static std::vector<Event*>& GetTransList() { return TransList;}
    private:
        static std::vector<Event*> TransList;
    };

    class CourseListState : public State
    {
    public:
        ~CourseListState() {};
        static void Init();
        static void Transition();
        static std::string ToString() {return "CourseListState";};

        inline static std::vector<Event*>& GetTransList() { return TransList;}
    private:
        static std::vector<Event*> TransList;
    };

    class OwnCourseState : public State
    {
    public:
        ~OwnCourseState() {};
        static void Init();
        static void Transition();
        static std::string ToString() {return "OwnCourseState";};

        inline static std::vector<Event*>& GetTransList() { return TransList;}
    private:
        static std::vector<Event*> TransList;
    };
}