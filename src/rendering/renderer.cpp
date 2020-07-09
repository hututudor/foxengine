#include "renderer.h"
#include "vertex_array.h"
#include "vertex_buffer.h"
#include "shader.h"
#include <glad/glad.h>

u32 defaultShader;

void initRenderer() {
  createGlobalVertexArray();
  bindGlobalVertexArray();
  createQuadRenderer();

  defaultShader = loadShader("../res/shaders/default.vert", "../res/shaders/default.frag");

  if(defaultShader == -1) {
    printf("COULD NOT LOAD DEFAULT SHADER");
  }
}

void updateRenderer() {
  Color color = {0.1, 0.4, 0.3, 1.0};

  clearRenderBuffers();
  fillBufferWithColor(color);

  useShader(defaultShader);
  bindGlobalVertexArray();
  renderQuad({0, 0}, {0.5, 0, 1, 1});
  renderQuad({0.2, 0.1}, {0.5, 0, 1, 1});
}

void destroyRenderer() {
  destroyGlobalVertexArray();
  destroyQuadRenderer();
}

void clearRenderBuffers() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void fillBufferWithColor(const Color &color) {
  glClearColor(color.r, color.g, color.b, color.a);
}
