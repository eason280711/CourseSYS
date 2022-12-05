#pragma once
#include "pch.h"

namespace Engine {
    class Event
    {
    public:
        virtual ~Event() {};
        virtual std::string ToString() = 0;
        virtual bool Handle() = 0;
        virtual int NextStateCode() = 0;
    };
}