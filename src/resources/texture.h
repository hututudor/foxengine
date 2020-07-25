#pragma once

#include "../base.h"

struct Texture {
  u32 index;
  std::string name;
  std::string path;
  b8 isLoaded;

  i32 width;
  i32 height;
  i32 channels;
};

Texture *getTexture(const std::string &textureName);
b8 addTexture(const std::string &textureName, const std::string &path);
b8 loadTexture(const std::string &textureName);
b8 unloadTexture(const std::string &textureName);
b8 unloadTexture(u32 textureIndex);
void destroyTextures();
b8 useTexture(const std::string& textureName);
b8 useTexture();