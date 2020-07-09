#include "file.h"
#include <stdlib.h>
#include <stdio.h>

str loadFile(cstr path) {
  str buffer = nullptr;
  i32 length;
  FILE *file = fopen(path, "rb");

  if (file) {
    fseek(file, 0, SEEK_END);
    length = ftell(file);
    fseek(file, 0, SEEK_SET);
    buffer = (str) malloc((length + 1) * sizeof(u8));

    if (buffer) {
      fread((void *) buffer, sizeof(u8), length, file);
      buffer[length] = '\0';
    }

    fclose(file);
  } else {
    printf("ERROR: Could not open file %s\n", path);
  }

  return buffer;
}
