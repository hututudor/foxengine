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
  clearRenderBuffers();
  fillBufferWithColor({0.1, 0.4, 0.3, 1.0});

  useShader(defaultShader);
  bindGlobalVertexArray();
  renderQuad(defaultShader, {0, 0}, {0.5, 0, 0.2, 1});
  renderQuad(defaultShader, {0.2, -0.3}, {0.7, 0.4, 0.2, 1});
  renderQuad(defaultShader, {0.4, 0.1}, {0.4, 0.2, 0.5, 1});
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
