#pragma once
#include "../base.h"

u32 loadShader(cstr vertexPath, cstr fragmentPath);
void useShader(u32 index);

void setUniformColor(u32 index, cstr name, Color color);
void setUniformV2(u32 index, cstr name, v2 vec);
void setUniformV3(u32 index, cstr name, v3 vec);