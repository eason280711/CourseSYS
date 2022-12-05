set(SOURCES
    application/src/Application.cpp
)

set(HEADERS
)

add_executable(application ${SOURCES} ${HEADERS})

add_dependencies(application
  engine
)

target_link_libraries(application
  engine
)

target_include_directories(application PRIVATE
    ${CMAKE_SOURCE_DIR}/engine
    ${CMAKE_SOURCE_DIR}/engine/src
)

target_compile_definitions(application PRIVATE
)