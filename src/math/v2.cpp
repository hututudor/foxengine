#include "v2.h"
#include <cmath>

v2 addV2(v2 x, v2 y) {
  v2 res = {x.x + y.x, x.y + y.y};
  return res;
}

v2 subV2(v2 x, v2 y) {
  v2 res = {x.x - y.x, x.y - y.y};
  return res;
}

v2 mulV2(v2 x, f32 y) {
  v2 res = {x.x * y, x.y * y};
  return res;
}

v2 divV2(v2 x, f32 y) {
  v2 res = {x.x / y, x.y / y};
  return res;
}

f32 squaredLenV2(v2 x) {
  return x.x * x.x + x.y * x.y;
}

f32 lenV2(v2 x) {
  return sqrt(squaredLenV2(x));
}

v2 normalizeV2(v2 x) {
  f32 len = lenV2(x);
  return divV2(x, len);
}

f32 dotV2(v2 x, v2 y) {
  return x.x * y.x + x.y * y.y;
}
