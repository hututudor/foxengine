#include "loader.h"
#include "../config/engine_config.h"
#include "shader.h"
#include "scene.h"
#include "texture.h"
#include <json/json.hpp>

struct ShaderToLoad {
  std::string name;
  std::string fragment;
  std::string vertex;
};

struct SceneToLoad {
  std::string name;
  std::string path;
};

struct TextureToLoad {
  std::string name;
  std::string path;
};

std::vector<ShaderToLoad> shadersToLoad;
std::vector<SceneToLoad> scenesToLoad;
std::vector<TextureToLoad> texturesToLoad;

void loadShaders(const nlohmann::json &resourcesJson) {
  auto shaders = resourcesJson["shaders"];
  for (auto &shader: shaders) {
    std::string name = shader.value("name", "default");
    std::string fragment = engineConfig.dataFolder + shader.value("fragment", "");
    std::string vertex = engineConfig.dataFolder + shader.value("vertex", "");

    shadersToLoad.push_back({name, fragment, vertex});
  }
}

void loadScenes(const nlohmann::json &resourcesJson) {
  auto scenes = resourcesJson["scenes"];
  for (auto &scene: scenes) {
    std::string name = scene.value("name", "default");
    std::string path = engineConfig.dataFolder + scene.value("path", "");

    scenesToLoad.push_back({name, path});
  }
}

void loadTextures(const nlohmann::json &resourcesJson) {
  auto textures = resourcesJson["textures"];
  for (auto &texture: textures) {
    std::string name = texture.value("name", "default");
    std::string path = engineConfig.dataFolder + texture.value("path", "");

    texturesToLoad.push_back({name, path});
  }
}

void loadResources() {
  std::string resourcesConfigFilePath = engineConfig.dataFolder + "data.json";
  str resourcesConfigFile = loadFile(resourcesConfigFilePath.c_str());

  if (resourcesConfigFile) {
    try {
      nlohmann::json resourcesJson = nlohmann::json::parse(resourcesConfigFile);
      std::thread shadersThread(loadShaders, resourcesJson);
      std::thread scenesThread(loadScenes, resourcesJson);
      std::thread texturesThread(loadTextures, resourcesJson);

      shadersThread.join();
      scenesThread.join();
      texturesThread.join();

      for (auto &shaderToLoad: shadersToLoad) {
        loadShader(shaderToLoad.name, shaderToLoad.fragment, shaderToLoad.vertex);
      }

      for (auto &sceneToLoad: scenesToLoad) {
        loadScene(sceneToLoad.name, sceneToLoad.path);
      }

      for (auto &textureToLoad: texturesToLoad) {
        addTexture(textureToLoad.name, textureToLoad.path);
      }
    } catch (nlohmann::json::exception) {
      printf("Error: Could not parse %s\n", resourcesConfigFilePath.c_str());
    }
  }
}

void destroyResources() {
  destroyTextures();
}
