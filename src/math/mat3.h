#pragma once

#include "../base.h"

struct mat3 {
  f32 m[3][3];
};

mat3 makeIdentityMat3();
mat3 makeProjectionMat3(f32 left, f32 right, f32 top, f32 bottom);
mat3 makeScaleMat3(v3 a);
mat3 makeScaleMat3(v2 a);
mat3 makeTranslationMat3(v3 a);
mat3 makeTranslationMat3(v2 a);
mat3 makeRotationMat3(f32 angle);
mat3 mulMat3(mat3 a, mat3 b);
v3 mulMat3(mat3 a, v3 b);
v2 mulMat3(mat3 a, v2 b);
