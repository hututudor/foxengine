#pragma once

#include "../base.h"

struct TransformComponent {
  glm::vec2 position;
  glm::vec2 scale;
  f32 rotation;
  i32 layer;

  TransformComponent() : position(glm::vec2(0, 0)), scale(glm::vec2(1, 1)), rotation(0), layer(0) {
  }
};