#include "../base.h"
#include "../window/window.h"
#include "../rendering/renderer.h"

i32 main() {
  if (!createWindow(1024, 720, "Fox Engine", false)) {
    return -1;
  }

  initRenderer();

  while (isWindowRunning()) {
    updateRenderer();

    pollWindowEvents();
    swapWindowBuffers();
  }

  destroyRenderer();
  destroyWindow();

  return 0;
}
