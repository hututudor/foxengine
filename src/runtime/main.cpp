#include "../base.h"
#include "../window/window.h"
#include "../rendering/renderer.h"

i32 main() {
  Color color = {0.1, 0.4, 0.3, 1.0};

  if (!createWindow(1024, 720, "Fox Engine", false)) {
    return -1;
  }

  while (isWindowRunning()) {
    clearRenderBuffers();
    fillBufferWithColor(color);

    pollWindowEvents();
    swapWindowBuffers();
  }

  destroyWindow();

  return 0;
}
