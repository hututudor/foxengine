#include "renderer.h"
#include "vertex_array.h"
#include "vertex_buffer.h"
#include "shader.h"
#include "../ecs/world.h"
#include <glad/glad.h>

u32 defaultShader;

void initRenderer() {
  createGlobalVertexArray();
  bindGlobalVertexArray();
  createQuadRenderer();

  defaultShader = loadShader("../res/shaders/default.vert", "../res/shaders/default.frag");

  if (defaultShader == -1) {
    printf("COULD NOT LOAD DEFAULT SHADER");
  }

  glEnable(GL_DEPTH_TEST);
}

void updateRenderer() {
  clearRenderBuffers();
  fillBufferWithColor({0.1, 0.4, 0.3, 1.0});

  static f32 ang = 0;
  ang += 1;

  useShader(defaultShader);
  bindGlobalVertexArray();

  auto view = world.view<Color>();

  for (auto entity: view) {
    auto &transform = world.get<Transform>(entity);
    auto &color = world.get<Color>(entity);

    renderQuad(defaultShader, color.color, glm::vec3(transform.position, transform.layer),
               transform.scale, transform.rotation);
  }

//  renderQuad(defaultShader, glm::vec4(0.5, 0, 0.2, 1.0), glm::vec3(100.0, 100.0, 10.0), glm::vec2(50.0, 50.0), ang);
//  renderQuad(defaultShader, glm::vec4(0.7, 0.4, 0.2, 1), glm::vec3(120.0, 110.0, 1.0), glm::vec2(50.0, 50.0), ang + 25);
//  renderQuad(defaultShader, glm::vec4(0.4, 0.2, 0.5, 1), glm::vec3(150.0, 180.0, 12.0), glm::vec2(50.0, 50.0), ang - 25);
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
