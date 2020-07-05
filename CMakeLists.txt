cmake_minimum_required(VERSION 3.16)
project(runtime)
project(engine)

set(CMAKE_CXX_STANDARD 14)

set(GLAD_FILES deps/glad/src/glad.c)
set(ENGINE_FILES src/utils/types.h src/math/v2.cpp src/math/v2.h src/window/window.cpp src/window/window.h src/rendering/renderer.cpp src/rendering/renderer.h src/math/color.cpp src/math/color.h src/math/color.cpp)
set(RUNTIME_FILES src/runtime/main.cpp)

add_subdirectory(deps/glfw)
include_directories(deps/glad/include)

add_library(engine STATIC "${ENGINE_FILES}" "${GLAD_FILES}")
add_executable(runtime "${RUNTIME_FILES}")

set_target_properties(engine PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(runtime PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(engine glfw)
target_link_libraries(runtime engine)