#include "loader.h"
#include "../config/engine_config.h"
#include "shader.h"
#include "scene.h"
#include <json/json.hpp>

void loadResources() {
  std::string resourcesConfigFilePath = engineConfig.dataFolder + "data.json";
  str resourcesConfigFile = loadFile(resourcesConfigFilePath.c_str());

  if (resourcesConfigFile) {
    try {
      nlohmann::json resourcesJson = nlohmann::json::parse(resourcesConfigFile);

      auto shaders = resourcesJson["shaders"];
      for (auto &shader: shaders) {
        std::string name = shader.value("name", "default");
        std::string fragment = engineConfig.dataFolder + shader.value("fragment", "");
        std::string vertex = engineConfig.dataFolder + shader.value("vertex", "");

        loadShader(name, fragment, vertex);
      }

      auto scenes = resourcesJson["scenes"];
      for (auto &scene: scenes) {
        std::string name = scene.value("name", "default");
        std::string path = engineConfig.dataFolder + scene.value("path", "");

        loadScene(name, path);
      }
    } catch (nlohmann::json::exception) {
      printf("Error: Could not parse %s\n", resourcesConfigFilePath.c_str());
    }
  }
}

void destroyResources() {

}
