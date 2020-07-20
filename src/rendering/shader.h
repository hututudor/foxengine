#pragma once
#include "../base.h"

u32 loadShader(cstr vertexPath, cstr fragmentPath);
void useShader(u32 index);

void setUniformV2(u32 index, cstr name, glm::vec2 vec);
void setUniformV3(u32 index, cstr name, glm::vec3 vec);
void setUniformV4(u32 index, cstr name, glm::vec4 vec);
void setUniformMat4(u32 index, cstr name, glm::mat4 mat);