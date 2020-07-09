#pragma once
#include "../base.h"

void createQuadRenderer();
void renderQuad(u32 shader, v3 position, Color color);
void renderQuad(u32 shader, v2 position, Color color);
void renderQuad(u32 shader, v3 position);
void renderQuad(u32 shader, v2 position);
void destroyQuadRenderer();