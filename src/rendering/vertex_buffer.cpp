#include "vertex_buffer.h"
#include <glad/glad.h>

u32 quadVBO;

f32 quadVertices[] = {
  0.5f, 0.5f,
  0.5f, -0.5f,
  -0.5f, 0.5f,
  0.5f, -0.5f,
  -0.5f, -0.5f,
  -0.5f, 0.5f,
};

void createQuadRenderer() {
  if (!quadVBO) {
    glGenBuffers(1, &quadVBO);
    glBindBuffer(GL_ARRAY_BUFFER, quadVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), quadVertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(f32), (void *) 0);
    glEnableVertexAttribArray(0);
  }
}

void renderQuad(v2 position, Color color) {
  glBindBuffer(GL_ARRAY_BUFFER, quadVBO);
  glDrawArrays(GL_TRIANGLES, 0, 6);
}


void destroyQuadRenderer() {
  if (quadVBO) {
    glDeleteBuffers(1, &quadVBO);
  }
}
