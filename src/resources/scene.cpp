#include "scene.h"
#include "../ecs/world.h"
#include <json/json.hpp>

std::map<std::string, Scene> scenes;

Scene *getScene(const std::string &sceneName) {
  if (scenes.count(sceneName)) {
    return &scenes[sceneName];
  } else {
    return nullptr;
  }
}

b8 loadScene(const std::string &sceneName, const std::string &scenePath) {
  if (getScene(sceneName)) {
    return false;
  }

  std::string structure = loadFile(scenePath.c_str());

  Scene scene;
  scene.name = sceneName;
  scene.structure = structure;

  scenes[sceneName] = scene;

  return true;
}

void switchScene(const std::string &sceneName) {
  Scene *scene = getScene(sceneName);
  if (!scene) {
    printf("ERROR: NOT FOUND SCENE TO LOAD: %s", sceneName.c_str());
    return;
  }

  world.clear();

  try {
    nlohmann::json jsonData = nlohmann::json::parse(scene->structure);

    auto objects = jsonData["objects"];
    for (auto &object: objects) {
      std::string name = object.value("name", "object");
      entt::entity entity = world.create();
      auto components = object["components"];

      for (auto &component: components) {
        std::string type = component.value("type", "transform");

        if (type == "transform") {
          auto &transformComponent = world.emplace<Transform>(entity);

          transformComponent.position = glm::vec2(component["position"]["x"].get<f32>(),
                                                  component["position"]["y"].get<f32>());
          transformComponent.scale = glm::vec2(component["scale"]["x"].get<f32>(),
                                               component["scale"]["y"].get<f32>());
          transformComponent.rotation = component["rotation"].get<f32>();
          transformComponent.layer = component["layer"].get<f32>();
        } else if (type == "color") {
          auto &colorComponent = world.emplace<Color>(entity);

          colorComponent.color = glm::vec4(component["color"]["r"].get<f32>(), component["color"]["g"].get<f32>(),
                                           component["color"]["b"].get<f32>(), component["color"]["a"].get<f32>());
          colorComponent.color = colorComponent.color;
        }
      }
    }
  } catch (nlohmann::json::exception) {
    printf("Error: Could not parse scene %s\n", scene->name.c_str());
  }
}
