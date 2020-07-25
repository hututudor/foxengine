#pragma once

#include "../base.h"

struct TextureComponent {
  glm::vec4 color;
  std::string texture;

  TextureComponent() : color(glm::vec4(0, 0, 0, 0)), texture("default") {
  }
};