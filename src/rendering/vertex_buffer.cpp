#include "vertex_buffer.h"
#include "shader.h"
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

void renderQuad(u32 shader, glm::vec4 color, glm::vec3 position, glm::vec2 scale, f32 rotation) {
  glm::mat4 projection = glm::ortho(0.0, 1024.0, 0.0, 720.0, -100.0, 100.0);
  glm::mat4 view = glm::translate(glm::mat4(1.0f), -glm::vec3(-100, 0, 0));
  glm::mat4 model = glm::translate(glm::mat4(1.0f), position);
  model = glm::rotate(model, glm::radians(rotation), glm::vec3(0.0, 0.0, 1.0));
  model = glm::scale(model, glm::vec3(scale.x, scale.y, 1.0));
  glm::mat4 mvp = projection * view * model;

  setUniformV4(shader, "color", color);
  setUniformMat4(shader, "mvp", mvp);

  glBindBuffer(GL_ARRAY_BUFFER, quadVBO);
  glDrawArrays(GL_TRIANGLES, 0, 6);
}

void renderQuad(u32 shader) {
  renderQuad(shader, {1, 1, 1, 1}, glm::vec3(0, 0, 0), glm::vec2(1, 1), 0);
}

void destroyQuadRenderer() {
  if (quadVBO) {
    glDeleteBuffers(1, &quadVBO);
  }
}
