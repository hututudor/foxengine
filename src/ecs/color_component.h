#pragma once

#include "../base.h"

struct ColorComponent {
  glm::vec4 color;

  ColorComponent() : color(glm::vec4(0, 0, 0, 0)) {
  }
};