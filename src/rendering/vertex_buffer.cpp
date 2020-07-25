#include "vertex_buffer.h"
#include "../resources/shader.h"
#include "../resources/texture.h"
#include "../config/engine_config.h"
#include <glad/glad.h>

u32 quadVBO;

f32 quadVertices[] = {
  0.5f, 0.5f, 1.0f, 1.0f,
  0.5f, -0.5f, 1.0f, 0.0f,
  -0.5f, 0.5f, 0.0f, 1.0f,
  0.5f, -0.5f, 1.0f, 0.0f,
  -0.5f, -0.5f, 0.0f, 0.0f,
  -0.5f, 0.5f, 0.0f, 1.0f
};

void createQuadRenderer() {
  if (!quadVBO) {
    glGenBuffers(1, &quadVBO);
    glBindBuffer(GL_ARRAY_BUFFER, quadVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), quadVertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(f32), (void *) 0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(f32), (void *) (2 * sizeof(f32)));
    glEnableVertexAttribArray(1);
  }
}

void renderQuad(const std::string &shaderName, const std::string &textureName, glm::vec4 color, glm::vec3 position,
                glm::vec2 scale, f32 rotation) {
  glm::mat4 projection = glm::ortho(0.0, (f64) engineConfig.windowWidth, 0.0, (f64) engineConfig.windowHeight, -100.0,
                                    100.0);
  glm::mat4 view = glm::translate(glm::mat4(1.0f), -glm::vec3(-100, 0, 0));
  glm::mat4 model = glm::translate(glm::mat4(1.0f), position);
  model = glm::rotate(model, glm::radians(-rotation), glm::vec3(0.0, 0.0, 1.0));
  model = glm::scale(model, glm::vec3(scale.x, scale.y, 1.0));
  glm::mat4 mvp = projection * view * model;

  b8 hasTexture = textureName != "";

  setShaderUniformBool(shaderName, "hasTexture", hasTexture);
  setShaderUniformV4(shaderName, "color", color);
  setShaderUniformMat4(shaderName, "mvp", mvp);

  if (hasTexture) {
    useTexture(textureName);
  } else {
    useTexture();
  }

  glBindBuffer(GL_ARRAY_BUFFER, quadVBO);
  glDrawArrays(GL_TRIANGLES, 0, 6);
}

void renderQuad(const std::string &shaderName) {
  renderQuad(shaderName, "", {1, 1, 1, 1}, glm::vec3(0, 0, 0), glm::vec2(1, 1), 0);
}

void destroyQuadRenderer() {
  if (quadVBO) {
    glDeleteBuffers(1, &quadVBO);
  }
}
