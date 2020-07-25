#include "texture.h"
#include "../config/engine_config.h"
#include <glad/glad.h>
#include <stb_image/stb_image.h>

std::map<std::string, Texture> textures;

Texture *getTexture(const std::string &textureName) {
  if (textures.count(textureName)) {
    return &textures[textureName];
  } else {
    return nullptr;
  }
}

b8 addTexture(const std::string &textureName, const std::string &path) {
  if (getTexture(textureName)) {
    return false;
  }

  std::string realPath = engineConfig.dataFolder + path;

  Texture texture = {0};
  texture.name = textureName;
  texture.path = realPath;

  textures[textureName] = texture;

  return true;
}

b8 loadTexture(const std::string &textureName) {
  Texture *texture = getTexture(textureName);
  if (!texture || texture->isLoaded) {
    return false;
  }

  glGenTextures(1, &texture->index);
  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, texture->index);

  char *data = loadFile(texture->path.c_str());
  printf("%s | %d\n", texture->path.c_str(), sizeof(data));
//  if (data) {
//    i32 format = GL_RGBA;
//    if (texture->channels == 3) {
//      format = GL_RGB;
//    }
//
//    glTexImage2D(GL_TEXTURE_2D, 0, format, texture->width, texture->height, 0, format, GL_UNSIGNED_BYTE, data);
//    glGenerateMipmap(GL_TEXTURE_2D);
//
////    stbi_image_free(data);
//    texture->isLoaded = true;
//  } else {
//    printf("ERROR: COULD NOT LOAD TEXTURE: %s\n", texture->path.c_str());
//    return false;
//  }

  return true;
}

b8 unloadTexture(const std::string &textureName) {
  return unloadTexture(getTexture(textureName)->index);
}

b8 unloadTexture(u32 textureIndex) {
  return 0;
}

void destroyTextures() {
  for (auto &texture: textures) {
    unloadTexture(texture.second.index);
  }
}

b8 useTexture(const std::string &textureName) {
  Texture *texture = getTexture(textureName);

  if (!texture || !texture->isLoaded) {
    return false;
  }

  glBindTexture(GL_TEXTURE_2D, texture->index);

  return true;
}

b8 useTexture() {
  glBindTexture(GL_TEXTURE_2D, 0);
  return true;
}
