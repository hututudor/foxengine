#pragma once

#include "../base.h"
#include "component.h"

struct Transform : Component {
  glm::vec2 position;
  glm::vec2 scale;
  f32 rotation;
  i32 layer;

  Transform() : position(glm::vec2(0, 0)), scale(glm::vec2(1, 1)), rotation(0), layer(0) {
  }
};