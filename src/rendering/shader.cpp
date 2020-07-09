#include "shader.h"
#include <glad/glad.h>

static void checkShaderCompilation(u32 shaderId, cstr type);
static void checkProgramCompilation(u32 programId);

u32 loadShader(cstr vertexPath, cstr fragmentPath) {
  str vertexCode = loadFile(vertexPath);
  str fragmentCode = loadFile(fragmentPath);

  if(!vertexCode || !fragmentCode) {
    return -1;
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

  return program;
}

void useShader(u32 index) {
  glUseProgram(index);
}

static void checkShaderCompilation(u32 shaderId, cstr type) {
  i32 success;
  char infoLog[1024];

  glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);

  if (!success){
    glGetShaderInfoLog(shaderId, 1024, NULL, infoLog);
    printf("ERROR::SHADER_COMPILATION_ERROR of type: %s\n%s\n", type, infoLog);
  }
}

void checkProgramCompilation(u32 programId) {
  i32 success;
  char infoLog[1024];

  glGetProgramiv(programId, GL_LINK_STATUS, &success);

  if (!success){
    glGetProgramInfoLog(programId, 1024, NULL, infoLog);
    printf("ERROR::PROGRAM_LINKING_ERROR of type: PROGRAM\n%s\n", infoLog);
  }
}
