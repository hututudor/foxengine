#pragma once

#include "../base.h"

b8 createWindow(u32 width, u32 height, str title, b8 fullscreen);
b8 isWindowRunning();
void destroyWindow();
void pollWindowEvents();
void swapWindowBuffers();