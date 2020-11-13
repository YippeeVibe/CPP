cmake_minimum_required(VERSION 3.5)
project(HelloCpp LANGUAGES CXX)

find_program(CCACHE_FOUND ccache)
if(CCACHE_FOUND)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK ccache)
    message("####ccache has loaded!")
else()
    message("####ccache has unloaded!")
endif()

message("####current system: ${CMAKE_SYSTEM_NAME}")
message("####current cxx_compiler ${CMAKE_CXX_COMPILER}")

if(UNIX)
    add_definitions(-DUNIX)
elseif(WIN32)
    add_definitions(-DWIN32)
endif()

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(memory
    )
set(tem
    )
set(typerich
    Code/typerich/z_time_during_constexpr.h
    Code/typerich/z_time_during.h
)
add_executable(${PROJECT_NAME}
  Code/main.cpp
  ${memory}
  ${tem}
  ${typerich}
)