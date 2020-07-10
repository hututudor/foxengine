#include <math.h>
#include "mat3.h"

mat3 makeIdentityMat3() {
  return {
    {
      {1, 0, 0},
      {0, 1, 0},
      {0, 0, 1},
    }
  };
}

mat3 makeProjectionMat3(f32 left, f32 right, f32 top, f32 bottom) {
  return {
    {
      {1 / (right - left), 0, 0},
      {0, 1 / (top - bottom), 0},
      {0, 0, 1}
    }
  };
}

mat3 makeScaleMat3(v3 a) {
  mat3 m = makeIdentityMat3();
  m.m[0][0] = a.x;
  m.m[1][1] = a.y;
  m.m[2][2] = a.z;
  return m;
}

mat3 makeScaleMat3(v2 a) {
  return makeScaleMat3(v2ToV3(a));
}

mat3 makeTranslationMat3(v3 a) {
  mat3 m = makeIdentityMat3();
  m.m[0][2] = a.x;
  m.m[1][2] = a.y;
  return m;
}

mat3 makeTranslationMat3(v2 a) {
  return makeTranslationMat3(v2ToV3(a));
}

mat3 makeRotationMat3(f32 angle) {
  float c = cos(angle);
  float s = sin(angle);

  mat3 m = makeIdentityMat3();
  m.m[0][0] = c;
  m.m[0][1] = -s;
  m.m[1][0] = s;
  m.m[1][1] = c;
  return m;
}

mat3 mulMat3(mat3 a, mat3 b) {
  mat3 m;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      m.m[i][j] = a.m[i][0] * b.m[0][j] + a.m[i][1] * b.m[1][j] + a.m[i][2] * b.m[2][j];
    }
  }
  return m;
}

v3 mulMat3(mat3 a, v3 b) {
  v3 res;
  res.x = a.m[0][0] * b.x + a.m[0][1] * b.y + a.m[0][2] * b.z;
  res.y = a.m[1][0] * b.x + a.m[1][1] * b.y + a.m[1][2] * b.z;
  res.z = a.m[2][0] * b.x + a.m[2][1] * b.y + a.m[2][2] * b.z;
  return res;
}

v2 mulMat3(mat3 a, v2 b) {
  return v3ToV2(mulMat3(a, v2ToV3(b)));
}
