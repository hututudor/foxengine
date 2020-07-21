#pragma once
#include "../base.h"

struct EngineConfig {
  std::string dataFolder = ".";

  std::string windowTitle = "Fox Engine";
  u32 windowWidth = 1024;
  u32 windowHeight = 720;

  b8 displayFramesPerSecond = false;
  b8 fullscreen = false;
  b8 vSync = false;
};

extern EngineConfig engineConfig;
