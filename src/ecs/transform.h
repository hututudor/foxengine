#pragma once
#include "../base.h"
#include "component.h"

struct Transform: Component {
  glm::vec2 position;
  glm::vec2 scale;
  f32 rotation;
  i32 layer;
};