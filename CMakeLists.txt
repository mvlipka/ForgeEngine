cmake_minimum_required(VERSION 3.26)

# Set the path to the vcpkg toolchain file
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake"
        CACHE STRING "Vcpkg toolchain file")

project(ForgeEngine VERSION 0.1.0)

# Use C++23 standard
set(CMAKE_CXX_STANDARD 23)

# Find the SFML package before declaring targets
find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)

# Find imgui-sfml
find_package(ImGui-SFML CONFIG REQUIRED)


# Define the shared library
add_library(ForgeLibrary SHARED lib/Game.h lib/Game.cpp
        lib/world_space/Sprite.cpp
        lib/world_space/Sprite.h
        lib/world_space/GameObject.cpp
        lib/world_space/GameObject.h
        lib/world_space/Vector2D.cpp
        lib/world_space/Vector2D.h
        lib/world_space/Renderable.cpp
        lib/world_space/Renderable.h
        lib/input/InputSystem.cpp
        lib/input/InputSystem.h
        lib/input/InputEvent.cpp
        lib/input/InputEvent.h)

# Include directories for the library target
target_include_directories(ForgeLibrary PRIVATE ${PROJECT_SOURCE_DIR}/lib)

# Link SFML with ForgeLibrary
target_link_libraries(ForgeLibrary PRIVATE sfml-system sfml-network sfml-graphics sfml-window)

# Link imgui-sfml
target_link_libraries(ForgeLibrary PRIVATE ImGui-SFML::ImGui-SFML)

# Set properties for ForgeLibrary
set_target_properties(ForgeLibrary PROPERTIES
        PREFIX ""
        OUTPUT_NAME "ForgeEngine"
)