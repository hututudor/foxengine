#pragma once

#include "../base.h"

struct v2 {
  f32 x;
  f32 y;
};

struct v2i {
  i32 x;
  i32 y;
};

struct v2u {
  u32 x;
  u32 y;
};

v2 addV2(v2 x, v2 y);
v2 subV2(v2 x, v2 y);
v2 mulV2(v2 x, f32 y);
v2 divV2(v2 x, f32 y);
v2 normalizeV2(v2 x);
f32 dotV2(v2 x, v2 y);
f32 squaredLenV2(v2 x);
f32 lenV2(v2 x);