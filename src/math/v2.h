#pragma once
#include "../base.h"

struct v3;

struct v2 {
  f32 x;
  f32 y;
};

v2 addV2(v2 a, v2 b);
v2 subV2(v2 a, v2 b);
v2 mulV2(v2 a, f32 b);
v2 divV2(v2 a, f32 b);
v2 normalizeV2(v2 a);
f32 dotV2(v2 a, v2 b);
f32 squaredLenV2(v2 a);
f32 lenV2(v2 a);

v2 v3ToV2(v3 a);