#include "../base.h"
#include "../window/window.h"
#include "../rendering/renderer.h"
#include "../parser/config.h"
#include "../ecs/world.h"

i32 main() {
  if (!createWindow(1024, 720, "Fox Engine", false)) {
    return -1;
  }

  initRenderer();
  loadConfigFile();

  entt::entity orangeObj= world.create();
  auto& orangeTransform = world.emplace<Transform>(orangeObj);
  orangeTransform.position = glm::vec2(100.0, 100.0);
  orangeTransform.scale = glm::vec2(100.0, 50.0);
  orangeTransform.rotation = 45;
  auto& orangeColor = world.emplace<Color>(orangeObj);
  orangeColor.color = glm::vec4(1.0f, 0.5f, 0.0f, 1.0f);


  while (isWindowRunning()) {
    updateRenderer();

    pollWindowEvents();
    swapWindowBuffers();
  }

  destroyRenderer();
  destroyWindow();

  return 0;
}
