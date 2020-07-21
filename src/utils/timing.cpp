#include "timing.h"
#include "../config/engine_config.h"
#include <GLFW/glfw3.h>

f32 deltaTime;
f64 lastTime;

void initDeltaTime() {
  lastTime = glfwGetTime();
}

void updateDeltaTime() {
  f64 currentTime = glfwGetTime();
  deltaTime = currentTime - lastTime;
  lastTime = currentTime;

  if (engineConfig.displayFramesPerSecond) {
    printf("FPS: %d\n", (i32) (1 / deltaTime));
  }
}

f32 getDeltaTime() {
  return deltaTime;
}
