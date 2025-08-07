cmake_minimum_required(VERSION 3.31)
project(sample-meshcore-through-cmake-fetchcontent)

set(CMAKE_CXX_STANDARD 20)

### MeshCore ###
add_compile_definitions(GLM_ENABLE_EXPERIMENTAL)
set(MESHCORE_BUILD_DEMOS OFF)
include(FetchContent)
set(CMAKE_TOOLCHAIN_FILE=${CMAKE_TOOLCHAIN_FILE})
FetchContent_Declare(MeshCore
        GIT_REPOSITORY https://github.com/JonasTollenaere/MeshCore.git
        GIT_TAG        v0.1.2
)
FetchContent_MakeAvailable(MeshCore)

add_executable(sample main.cpp)
target_link_libraries(sample MeshCore)