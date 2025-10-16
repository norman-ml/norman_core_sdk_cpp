cmake_minimum_required(VERSION 3.10)
project(NormanCoreSdk LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Dependencies (vcpkg-managed)
find_package(fmt CONFIG REQUIRED)
find_package(cpr CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)

# Collect all source files recursively
file(GLOB_RECURSE SRC_FILES "src/*.cpp")


# Build target
add_executable(NormanCoreSdk main.cpp ${SRC_FILES})

# Public include path points to "include"
target_include_directories(NormanCoreSdk
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Link dependencies
target_link_libraries(NormanCoreSdk
    PRIVATE
        fmt::fmt
        cpr::cpr
        nlohmann_json::nlohmann_json
)

# (Optional) Set output folders
set_target_properties(NormanCoreSdk PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY_DEBUG   ${CMAKE_SOURCE_DIR}/bin/Debug
    RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/bin/Release
)
