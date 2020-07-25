#include <glad/glad.h>
#include "window.h"
#include "../config/engine_config.h"
#include <stb_image/stb_image.h>

GLFWwindow *window;

b8 createWindow(u32 width, u32 height, cstr title, b8 fullscreen, b8 vSync) {
  if (!glfwInit()) {
    return false;
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

  GLFWmonitor *monitor = nullptr;

  if (fullscreen) {
    monitor = glfwGetPrimaryMonitor();
  }

  window = glfwCreateWindow(width, height, title, monitor, nullptr);
  if (!window) {
    glfwTerminate();
    return false;
  }

  glfwMakeContextCurrent(window);
  setVSync(vSync);

  glfwSetWindowSizeCallback(window, windowSizeCallback);

  if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
    return 0;
  }

  GLFWimage icon[1];
  icon[0].pixels = stbi_load((engineConfig.dataFolder + "logo.png").c_str(), &icon[0].width, &icon[0].height, 0, 4);
  glfwSetWindowIcon(window, 1, icon);
  stbi_image_free(icon[0].pixels);

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

void setVSync(b8 enabled) {
  glfwSwapInterval(enabled);
}

void windowSizeCallback(GLFWwindow *win, i32 width, i32 height) {
  engineConfig.windowWidth = width;
  engineConfig.windowHeight = height;

  glViewport(0, 0, width, height);
}
