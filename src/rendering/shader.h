#pragma once
#include "../base.h"

u32 loadShader(cstr vertexPath, cstr fragmentPath);
void useShader(u32 index);

void setUniformColor(u32 index, cstr name, Color color);
void setUniformV2(u32 index, cstr name, glm::vec2 vec);
void setUniformV3(u32 index, cstr name, glm::vec3 vec);
void setUniformMat4(u32 index, cstr name, glm::mat4 mat);