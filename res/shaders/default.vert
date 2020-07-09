#version 330 core
layout (location = 0) in vec2 pos;

uniform vec4 color;
uniform vec3 position;
out vec4 PixelColor;

void main() {
  vec3 finalPosition = vec3(pos, 0.0) + position;

  gl_Position = vec4(finalPosition, 1.0);
  PixelColor = color;
}