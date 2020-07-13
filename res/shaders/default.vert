#version 330 core
layout (location = 0) in vec2 pos;

uniform vec4 color;
uniform mat4 mvp;
out vec4 PixelColor;

void main() {
  gl_Position = mvp * vec4(pos, 1.0, 1.0);
  PixelColor = color;
}