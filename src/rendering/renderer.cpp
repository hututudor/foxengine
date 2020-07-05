#include "renderer.h"
#include <glad/glad.h>

void clearRenderBuffers() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void fillBufferWithColor(const Color &color) {
  glClearColor(color.r, color.g, color.b, color.a);
}
