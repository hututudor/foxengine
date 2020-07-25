#version 330 core
layout (location = 0) in vec2 pos;
layout (location = 1) in vec2 tex;

uniform vec4 color;
uniform mat4 mvp;
out vec4 PixelColor;
out vec2 TexCoord;

void main() {
  gl_Position = mvp * vec4(pos, 1.0, 1.0);
  PixelColor = color;
  TexCoord = tex;
}