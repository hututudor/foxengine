#include "renderer.h"
#include "vertex_array.h"
#include "vertex_buffer.h"
#include "../resources/shader.h"
#include "../resources/texture.h"
#include "../ecs/world.h"
#include <glad/glad.h>

void initRenderer() {
  createGlobalVertexArray();
  bindGlobalVertexArray();
  createQuadRenderer();

  glEnable(GL_DEPTH_TEST);
  glEnable(GL_BLEND);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void updateRenderer() {
  clearRenderBuffers();
  fillBufferWithColor({0.1, 0.4, 0.3, 1.0});

  static f32 ang = 0;
  ang += 0.01;

  useShader("default");
  bindGlobalVertexArray();

  auto colorComponents = world.view<ColorComponent>();
  for (auto entity: colorComponents) {
    auto &transform = world.get<TransformComponent>(entity);
    auto &color = world.get<ColorComponent>(entity);

    renderQuad("default", "", color.color, glm::vec3(transform.position, transform.layer),
               transform.scale, transform.rotation);
  }

  auto textureComponents = world.view<TextureComponent>();
  for (auto &entity: textureComponents) {
    auto &transform = world.get<TransformComponent>(entity);
    auto &texture = world.get<TextureComponent>(entity);

    renderQuad("default", texture.texture, texture.color, glm::vec3(transform.position, transform.layer),
               transform.scale, ang);
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
