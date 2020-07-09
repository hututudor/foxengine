#version 330 core
layout (location = 0) in vec2 pos;

uniform vec4 color;
uniform vec2 position;
out vec4 PixelColor;

void main() {
  vec2 finalposition = pos + position;

  gl_Position = vec4(finalposition, 1.0, 1.0);
  PixelColor = color;
}