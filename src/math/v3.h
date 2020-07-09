#pragma once
#include "../base.h"

struct v2;

struct v3 {
  f32 x;
  f32 y;
  f32 z;
};

v3 addV3(v3 a, v3 b);
v3 subV3(v3 a, v3 b);
v3 mulV3(v3 a, f32 b);
v3 divV3(v3 a, f32 b);
v3 normalizeV3(v3 a);
f32 dotV3(v3 a, v3 b);
f32 squaredLenV3(v3 a);
f32 lenV3(v3 a);

v3 v2ToV3(v2 a);