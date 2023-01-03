cmake_minimum_required(VERSION 3.24)
project(RunnerServer)

include(FetchContent)

FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
        GIT_TAG 871ed52d350214a034f6ef8a3b8f51c5ce1bd400) # The commit hash for 1.9.0. Replace with the latest from: https://github.com/libcpr/cpr/releases
FetchContent_MakeAvailable(cpr)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz)
FetchContent_MakeAvailable(json)

set(CMAKE_CXX_STANDARD 20)

add_executable(RunnerServer src/main.cpp src/Server/Server.cpp src/Server/Headers/ServerHeader.h src/Helpers/Headers/HelperHeader.h src/Server/Http.cpp)

target_link_libraries(RunnerServer PRIVATE cpr::cpr)
target_link_libraries(RunnerServer PRIVATE nlohmann_json::nlohmann_json)