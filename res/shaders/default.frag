#version 330 core
in vec4 PixelColor;
in vec2 TexCoord;
out vec4 FragColor;

uniform sampler2D tex;

void main() {
  FragColor = texture(tex, TexCoord);
}