#pragma once

#include "../base.h"

void createQuadRenderer();
void renderQuad(u32 shader, glm::vec4 color, glm::vec3 position, glm::vec2 scale, f32 rotation);
void renderQuad(u32 shader);
void destroyQuadRenderer();