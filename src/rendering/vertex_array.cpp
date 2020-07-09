#include "vertex_array.h"
#include "../base.h"
#include <glad/glad.h>

u32 vao;

void createGlobalVertexArray() {
  if (!vao) {
    glGenVertexArrays(1, &vao);
  }
}

void bindGlobalVertexArray() {
  glBindVertexArray(vao);
}

void destroyGlobalVertexArray() {
  if (vao) {
    glDeleteVertexArrays(1, &vao);
  }
}
