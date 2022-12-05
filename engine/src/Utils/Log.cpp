#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Engine {
	
    std::shared_ptr<spdlog::logger> LogManager::s_CoreLogger;

    void LogManager::startUp()
    {
        spdlog::set_pattern("%^[%T] %n: %v%$");

        s_CoreLogger = spdlog::stdout_color_mt("ENGINE");

        s_CoreLogger->set_level(spdlog::level::trace);
    }

    void LogManager::shutDown()
    {
        s_CoreLogger->flush();
        spdlog::drop_all();
    }

    void LogManager::Tick()
    {
        
    }
}