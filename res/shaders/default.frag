#version 330 core
in vec4 PixelColor;
in vec2 TexCoord;
out vec4 FragColor;

uniform sampler2D tex;
uniform bool hasTexture;

void main() {
  if(hasTexture) {
    FragColor = texture(tex, TexCoord) * PixelColor;
  } else {
    FragColor = PixelColor;
  }
}