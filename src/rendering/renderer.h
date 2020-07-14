#pragma once

#include "../base.h"

void initRenderer();
void updateRenderer();
void destroyRenderer();

void clearRenderBuffers();
void fillBufferWithColor(const glm::vec4 &color);