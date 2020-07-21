#pragma once

#include "../base.h"

void createQuadRenderer();
void renderQuad(const std::string &shaderName, glm::vec4 color, glm::vec3 position, glm::vec2 scale, f32 rotation);
void renderQuad(const std::string &shaderName);
void destroyQuadRenderer();