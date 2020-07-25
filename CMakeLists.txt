cmake_minimum_required(VERSION 3.16)
project(runtime)
project(engine)

set(CMAKE_CXX_STANDARD 17)

set(GLAD_FILES deps/glad/src/glad.c)
set(ENGINE_FILES src/utils/types.h src/window/window.cpp src/window/window.h src/rendering/renderer.cpp src/rendering/renderer.h src/rendering/vertex_array.cpp src/rendering/vertex_array.h src/rendering/vertex_buffer.cpp src/rendering/vertex_buffer.h src/utils/file.cpp src/utils/file.h src/ecs/world.cpp src/ecs/world.h src/ecs/component.h src/ecs/transform.h src/ecs/color.h src/parser/config.cpp src/parser/config.h src/config/engine_config.h src/config/engine_config.cpp src/resources/shader.cpp src/resources/shader.h src/resources/loader.cpp src/resources/loader.h src/utils/timing.cpp src/utils/timing.h src/resources/scene.cpp src/resources/scene.h src/resources/texture.cpp src/resources/texture.h deps/stb_image/include/stb_image/stb_image.h)
set(RUNTIME_FILES src/runtime/main.cpp)

add_subdirectory(deps/glfw)
add_subdirectory(deps/glm)
include_directories(deps/glad/include)
include_directories(deps/entt/include)
include_directories(deps/json/include)
include_directories(deps/stb_image/include)

add_library(engine STATIC "${ENGINE_FILES}" "${GLAD_FILES}")
add_executable(runtime "${RUNTIME_FILES}")

set_target_properties(engine PROPERTIES LINKER_LANGUAGE C)
set_target_properties(runtime PROPERTIES LINKER_LANGUAGE C)

target_link_libraries(engine glfw glm)
target_link_libraries(runtime engine)