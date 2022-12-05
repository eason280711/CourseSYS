set(SOURCES
    engine/src/Core/Application.cpp
    engine/src/Utils/Log.cpp
    engine/src/Utils/DataBase.cpp
    engine/src/State/State.cpp
    engine/src/State/StateEvent.cpp
    engine/src/Event/CourseEvent.cpp
    engine/src/Event/UserEvent.cpp
)

set(HEADERS
    engine/Engine.h
    engine/pch.h
    engine/src/Core/Application.h
    engine/src/Core/Core.h
    engine/src/Utils/DataBase.h
    engine/src/Core/EntryPoint.h
    engine/src/Utils/Log.h
    engine/src/Config/config.h
    engine/src/State/State.h
    engine/src/State/StateEvent.h
    engine/src/Event/Event.h
    engine/src/Event/UserEvent.h
    engine/src/Event/CourseEvent.h
)

add_library(engine SHARED ${SOURCES} ${HEADERS})

find_package(leveldb CONFIG REQUIRED)

target_link_libraries(engine
    leveldb::leveldb
)

target_include_directories(engine PRIVATE
    ${CMAKE_SOURCE_DIR}/engine
    ${CMAKE_SOURCE_DIR}/engine/src
    ${CMAKE_SOURCE_DIR}/engine/vendor/spdlog/include
)

target_compile_definitions(engine PRIVATE
)