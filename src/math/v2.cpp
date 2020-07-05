#include "v2.h"
#include <math.h>

v2 addV2(v2 a, v2 b) {
  v2 res = {a.x + b.x, a.y + b.y};
  return res;
}

v2 subV2(v2 a, v2 b) {
  v2 res = {a.x - b.x, a.y - b.y};
  return res;
}

v2 mulV2(v2 a, f32 b) {
  v2 res = {a.x * b, a.y * b};
  return res;
}

v2 divV2(v2 a, f32 b) {
  v2 res = {a.x / b, a.y / b};
  return res;
}

f32 squaredLenV2(v2 a) {
  return a.x * a.x + a.y * a.y;
}

f32 lenV2(v2 a) {
  return sqrt(squaredLenV2(a));
}

v2 normalizeV2(v2 a) {
  f32 len = lenV2(a);
  return divV2(a, len);
}

f32 dotV2(v2 a, v2 b) {
  return a.x * b.x + a.y * b.y;
}
