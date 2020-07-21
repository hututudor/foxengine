#include "shader.h"
#include <glad/glad.h>

static void checkShaderCompilation(u32 shaderId, cstr type);
static void checkProgramCompilation(u32 programId);

std::map<std::string, Shader> shaders;

Shader *getShader(const std::string &shaderName) {
  if (shaders.count(shaderName)) {
    return &shaders[shaderName];
  } else {
    return nullptr;
  }
}

b8 loadShader(const std::string &shaderName, const std::string &fragmentPath, const std::string &vertexPath) {
  Shader *s = getShader(shaderName);
  if (s) {
    return false;
  }

  str vertexCode = loadFile(vertexPath.c_str());
  str fragmentCode = loadFile(fragmentPath.c_str());

  if (!vertexCode || !fragmentCode) {
    return false;
  }

  u32 vertexId, fragmentId;

  vertexId = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexId, 1, &vertexCode, nullptr);
  glCompileShader(vertexId);
  checkShaderCompilation(vertexId, "VERTEX");

  fragmentId = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentId, 1, &fragmentCode, nullptr);
  glCompileShader(fragmentId);
  checkShaderCompilation(fragmentId, "FRAGMENT");

  u32 program = glCreateProgram();
  glAttachShader(program, vertexId);
  glAttachShader(program, fragmentId);
  glLinkProgram(program);
  checkProgramCompilation(program);

  glDeleteShader(vertexId);
  glDeleteShader(fragmentId);

  Shader shader;
  shader.fragmentPath = fragmentPath;
  shader.vertexPath = vertexPath;
  shader.index = program;

  shaders[shaderName] = shader;

  return true;
}

void useShader(const std::string &shaderName) {
  Shader *shader = getShader(shaderName);

  if (shader) {
    glUseProgram(shader->index);
  }
}

void setShaderUniformV2(const std::string &shaderName, cstr name, glm::vec2 vec) {
  Shader *shader = getShader(shaderName);

  if (shader) {
    i32 location = glGetUniformLocation(shader->index, name);
    if (location != -1) {
      glUniform2f(location, vec.x, vec.y);
    }
  }
}

void setShaderUniformV3(const std::string &shaderName, cstr name, glm::vec3 vec) {
  Shader *shader = getShader(shaderName);

  if (shader) {
    i32 location = glGetUniformLocation(shader->index, name);
    if (location != -1) {
      glUniform3f(location, vec.x, vec.y, vec.z);
    }
  }
}

void setShaderUniformV4(const std::string &shaderName, cstr name, glm::vec4 vec) {
  Shader *shader = getShader(shaderName);

  if (shader) {
    i32 location = glGetUniformLocation(shader->index, name);
    if (location != -1) {
      glUniform4f(location, vec.x, vec.y, vec.z, vec.w);
    }
  }
}

void setShaderUniformMat4(const std::string &shaderName, cstr name, glm::mat4 mat) {
  Shader *shader = getShader(shaderName);

  if (shader) {
    i32 location = glGetUniformLocation(shader->index, name);
    if (location != -1) {
      glUniformMatrix4fv(location, 1, GL_FALSE, &mat[0][0]);
    }
  }
}

static void checkShaderCompilation(u32 shaderId, cstr type) {
  i32 success;
  char infoLog[1024];

  glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);

  if (!success) {
    glGetShaderInfoLog(shaderId, 1024, NULL, infoLog);
    printf("ERROR::SHADER_COMPILATION_ERROR of type: %s\n%s\n", type, infoLog);
  }
}

void checkProgramCompilation(u32 programId) {
  i32 success;
  char infoLog[1024];

  glGetProgramiv(programId, GL_LINK_STATUS, &success);

  if (!success) {
    glGetProgramInfoLog(programId, 1024, NULL, infoLog);
    printf("ERROR::PROGRAM_LINKING_ERROR of type: PROGRAM\n%s\n", infoLog);
  }
}