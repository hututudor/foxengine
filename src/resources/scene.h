#pragma once

#include "../base.h"

struct Scene {
  std::string name;
  std::string structure;
};

Scene *getScene(const std::string &sceneName);
b8 loadScene(const std::string &sceneName, const std::string &scenePath);
void switchScene(const std::string &sceneName);