#include "../base.h"
#include "../window/window.h"
#include "../rendering/renderer.h"
#include "../ecs/world.h"

i32 main() {
  if (!createWindow(1024, 720, "Fox Engine", false)) {
    return -1;
  }

  initRenderer();

  entt::entity orangeObj= world.create();
  auto& orangeTransform = world.emplace<Transform>(orangeObj);
  orangeTransform.position = glm::vec2(100.0, 100.0);
  orangeTransform.scale = glm::vec2(100.0, 50.0);
  orangeTransform.rotation = 45;
  auto& orangeColor = world.emplace<Color>(orangeObj);
  orangeColor.color = glm::vec4(1.0f, 0.5f, 0.0f, 1.0f);

//  entt::entity greenObj = world.create();
//  auto& greenTransform = world.emplace<Transform>(greenObj);
//  greenTransform.position = glm::vec2(200.0, 500.0);
//  greenTransform.scale = glm::vec2(100.0, 50.0);
//  greenTransform.rotation = 15;
//  auto& greenColor = world.emplace<Color>(greenObj);
//  greenColor.color = glm::vec4(1.0f, 0.5f, 0.0f, 1.0f);

  while (isWindowRunning()) {
    updateRenderer();

    pollWindowEvents();
    swapWindowBuffers();
  }

  destroyRenderer();
  destroyWindow();

  return 0;
}
