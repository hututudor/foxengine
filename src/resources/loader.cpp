#include "loader.h"
#include "../config/engine_config.h"
#include "shader.h"
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
    } catch (nlohmann::json::exception) {
      printf("Error: Could not parse %s\n", resourcesConfigFilePath.c_str());
    }
  }
}

void destroyResources() {

}
