#pragma once

#include "../base.h"

struct Shader {
  u32 index;
};

Shader *getShader(const std::string &shaderName);
b8 loadShader(const std::string &shaderName, const std::string &fragmentPath, const std::string &vertexPath);
void useShader(const std::string &shaderName);

void setShaderUniformV2(const std::string &shaderName, cstr name, glm::vec2 vec);
void setShaderUniformV3(const std::string &shaderName, cstr name, glm::vec3 vec);
void setShaderUniformV4(const std::string &shaderName, cstr name, glm::vec4 vec);
void setShaderUniformMat4(const std::string &shaderName, cstr name, glm::mat4 mat);