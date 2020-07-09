#pragma once
#include "../base.h"

void createQuadRenderer();
void renderQuad(u32 shader, v2 position, Color color);
void destroyQuadRenderer();