cmake_minimum_required(VERSION 3.16)
project(runtime)
project(engine)

set(CMAKE_C_STANDARD 99)

set(GLAD_FILES deps/glad/src/glad.c)
set(ENGINE_FILES src/utils/types.h src/math/v2.cpp src/math/v2.h src/window/window.cpp src/window/window.h src/rendering/renderer.cpp src/rendering/renderer.h src/math/color.cpp src/math/color.h src/math/color.cpp src/rendering/vertex_array.cpp src/rendering/vertex_array.h src/rendering/vertex_buffer.cpp src/rendering/vertex_buffer.h src/rendering/shader.cpp src/rendering/shader.h src/utils/file.cpp src/utils/file.h src/math/v3.cpp src/math/v3.h)
set(RUNTIME_FILES src/runtime/main.cpp)

add_subdirectory(deps/glfw)
include_directories(deps/glad/include)

add_library(engine STATIC "${ENGINE_FILES}" "${GLAD_FILES}")
add_executable(runtime "${RUNTIME_FILES}")

set_target_properties(engine PROPERTIES LINKER_LANGUAGE C)
set_target_properties(runtime PROPERTIES LINKER_LANGUAGE C)

target_link_libraries(engine glfw)
target_link_libraries(runtime engine)