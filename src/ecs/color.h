#pragma once
#include "../base.h"
#include "component.h"

struct Color: Component {
  glm::vec4 color;
};