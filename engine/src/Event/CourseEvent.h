#pragma once
#include "Event.h"

namespace Engine {

    class AddCourseEvent : public Event
    {
        std::string ToString() {return "AddCourse";};
        int NextStateCode() {return 1;};
        bool Handle() override;
    };

    class GetCourseInfoEvent : public Event
    {
        std::string ToString() {return "GetCourse";};
        int NextStateCode() {return 4;};
        bool Handle() override;
    };

    class GetOwnCourseEvent : public Event
    {
        std::string ToString() {return "GetOwnCourse";};
        int NextStateCode() {return 3;};
        bool Handle() override;
    };

    class SearchCourseEvent : public Event
    {
        std::string ToString() {return "SearchCourse";};
        int NextStateCode() {return 2;};
        bool Handle() override;
    };
}