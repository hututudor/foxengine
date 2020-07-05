cmake_minimum_required(VERSION 3.16)
project(runtime)
project(engine)

set(CMAKE_CXX_STANDARD 14)

set(ENGINE_FILES src/utils/types.h src/math/v2.cpp src/math/v2.h)
set(RUNTIME_FILES src/runtime/main.cpp)

add_library(engine STATIC "${ENGINE_FILES}")
add_executable(runtime "${RUNTIME_FILES}")

set_target_properties(engine PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(runtime PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(runtime engine)