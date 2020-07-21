#include "config.h"
#include "../config/engine_config.h"
#include <json/json.hpp>

void loadConfigFile() {
  str configFile = loadFile("fox.json");
  if (configFile) {
    try {
      nlohmann::json configJson = nlohmann::json::parse(configFile);

      engineConfig.dataFolder = configJson.value("dataFolder", engineConfig.dataFolder);
    } catch (nlohmann::json::exception) {
      printf("Error: Could not parse fox.json\n");
    }
  }
}
