#include "renderer.h"
#include "vertex_array.h"
#include "vertex_buffer.h"
#include "../resources/shader.h"
#include "../ecs/world.h"
#include <glad/glad.h>

void initRenderer() {
  createGlobalVertexArray();
  bindGlobalVertexArray();
  createQuadRenderer();

  glEnable(GL_DEPTH_TEST);
}

void updateRenderer() {
  clearRenderBuffers();
  fillBufferWithColor({0.1, 0.4, 0.3, 1.0});

  static f32 ang = 0;
  ang += 1;

  useShader("default");
  bindGlobalVertexArray();

  auto view = world.view<Color>();

  for (auto entity: view) {
    auto &transform = world.get<Transform>(entity);
    auto &color = world.get<Color>(entity);

    renderQuad("default", color.color, glm::vec3(transform.position, transform.layer),
               transform.scale, transform.rotation);
  }
}

void destroyRenderer() {
  destroyGlobalVertexArray();
  destroyQuadRenderer();
}

void clearRenderBuffers() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void fillBufferWithColor(const glm::vec4 &color) {
  glClearColor(color.r, color.g, color.b, color.a);
}
