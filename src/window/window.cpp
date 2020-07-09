#include "window.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

GLFWwindow* window;

b8 createWindow(u32 width, u32 height, cstr title, b8 fullscreen) {
  if(!glfwInit()) {
    return false;
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

  window = glfwCreateWindow(width, height, title, nullptr, nullptr);
  if(!window) {
    glfwTerminate();
    return false;
  }

  glfwMakeContextCurrent(window);

  if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    return 0;
  }

  return 1;
}

b8 isWindowRunning() {
  return !glfwWindowShouldClose(window);
}

void destroyWindow() {
  glfwTerminate();
}

void pollWindowEvents() {
  glfwPollEvents();
}

void swapWindowBuffers() {
  glfwSwapBuffers(window);
}
