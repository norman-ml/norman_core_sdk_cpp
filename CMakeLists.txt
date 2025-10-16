cmake_minimum_required(VERSION 3.10)
project(NormanCoreSdk VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Dependencies (vcpkg-managed)
find_package(fmt CONFIG REQUIRED)
find_package(cpr CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)

# Collect all source files recursively
file(GLOB_RECURSE SRC_FILES "src/*.cpp")

add_library(normancoresdk ${SRC_FILES})

target_include_directories(normancoresdk
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)


target_link_libraries(normancoresdk
    PUBLIC
        fmt::fmt
        cpr::cpr
        nlohmann_json::nlohmann_json
)

install(TARGETS normancoresdk
        EXPORT normancoresdkTargets
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin
        INCLUDES DESTINATION include)

install(DIRECTORY include/ DESTINATION include)

install(EXPORT normancoresdkTargets
        FILE normancoresdkTargets.cmake
        NAMESPACE norman::
        DESTINATION share/normancoresdk)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/normancoresdkConfigVersion.cmake"
    COMPATIBILITY SameMajorVersion
)

configure_package_config_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/normancoresdkConfig.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/normancoresdkConfig.cmake"
    INSTALL_DESTINATION share/normancoresdk
)

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/normancoresdkConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/normancoresdkConfigVersion.cmake"
    DESTINATION share/normancoresdk)
