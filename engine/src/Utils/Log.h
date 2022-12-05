#pragma once
#include "Core/Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace Engine {

    class LogManager : public Engine::RuntimeModule
    {
    public:
        ~LogManager() {};

        static void startUp();
        static void shutDown();
        void Tick();

        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
    };
}

#define ENGINE_CORE_TRACE(...) ::Engine::LogManager::GetCoreLogger()->trace(__VA_ARGS__);
#define ENGINE_CORE_INFO(...) ::Engine::LogManager::GetCoreLogger()->info(__VA_ARGS__);
#define ENGINE_CORE_WARN(...) ::Engine::LogManager::GetCoreLogger()->warn(__VA_ARGS__);
#define ENGINE_CORE_ERROR(...) ::Engine::LogManager::GetCoreLogger()->error(__VA_ARGS__);
#define ENGINE_CORE_FATAL(...) ::Engine::LogManager::GetCoreLogger()->fatal(__VA_ARGS__);