cmake_minimum_required(VERSION 3.15)
project(NormanCoreSdk VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# -------------------------------
# Dependencies (via vcpkg)
# -------------------------------
find_package(fmt CONFIG REQUIRED)
find_package(cpr CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)

# -------------------------------
# Source collection
# -------------------------------
file(GLOB_RECURSE SRC_FILES "src/*.cpp")

# -------------------------------
# Library target
# -------------------------------
add_library(normancoresdk SHARED ${SRC_FILES})

# Automatically export all symbols on Windows
# so we don’t need __declspec(dllexport)
set_target_properties(normancoresdk PROPERTIES
    WINDOWS_EXPORT_ALL_SYMBOLS ON
    OUTPUT_NAME "normancoresdk"
)

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

# -------------------------------
# Installation
# -------------------------------
include(GNUInstallDirs)

install(TARGETS normancoresdk
    EXPORT normancoresdkTargets
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(EXPORT normancoresdkTargets
    FILE normancoresdkTargets.cmake
    NAMESPACE norman::
    DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/normancoresdk
)

# -------------------------------
# Package config
# -------------------------------
include(CMakePackageConfigHelpers)

write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/normancoresdkConfigVersion.cmake"
    COMPATIBILITY SameMajorVersion
)

configure_package_config_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/normancoresdkConfig.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/normancoresdkConfig.cmake"
    INSTALL_DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/normancoresdk
)

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/normancoresdkConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/normancoresdkConfigVersion.cmake"
    DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/normancoresdk
)
