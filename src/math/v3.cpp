#include "v3.h"
#include <math.h>

v3 addV3(v3 a, v3 b) {
  v3 res = {a.x + b.x, a.y + b.y, a.z + b.z};
  return res;
}

v3 subV3(v3 a, v3 b) {
  v3 res = {a.x - b.x, a.y - b.y, a.z - b.z};
  return res;
}

v3 mulV3(v3 a, f32 b) {
  v3 res = {a.x * b, a.y * b, a.z * b};
  return res;
}

v3 divV3(v3 a, f32 b) {
  v3 res = {a.x / b, a.y / b, a.z / b};
  return res;
}

v3 normalizeV3(v3 a) {
  f32 len = lenV3(a);
  return divV3(a, len);
}

f32 dotV3(v3 a, v3 b) {
  return a.x * b.x + a.y * b.y + a.z * b.z;
}

f32 squaredLenV3(v3 a) {
  return a.x * a.x + a.y * a.y + a.z * a.z;
}

f32 lenV3(v3 a) {
  return sqrt(squaredLenV3(a));
}

v3 v2ToV3(v2 a) {
  return v3({a.x, a.y, 0});
}
