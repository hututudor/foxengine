#include "config.h"
#include "../config/engine_config.h"
#include <json/json.hpp>

void loadConfigFile() {
  str configFile = loadFile("fox.json");
  if (configFile) {
    try {
      nlohmann::json configJson = nlohmann::json::parse(configFile);

      engineConfig.dataFolder = configJson.value("dataFolder", engineConfig.dataFolder);

      engineConfig.windowTitle = configJson.value("windowTitle", engineConfig.windowTitle);
      engineConfig.windowWidth = configJson.value("windowWidth", engineConfig.windowWidth);
      engineConfig.windowHeight = configJson.value("windowHeight", engineConfig.windowHeight);

      engineConfig.displayFramesPerSecond = configJson.value("displayFramesPerSecond", engineConfig.displayFramesPerSecond);
      engineConfig.fullscreen = configJson.value("fullscreen", engineConfig.fullscreen);
      engineConfig.vSync = configJson.value("vSync", engineConfig.vSync);
    } catch (nlohmann::json::exception) {
      printf("Error: Could not parse fox.json\n");
    }
  }
}
