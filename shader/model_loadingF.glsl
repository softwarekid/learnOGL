#version 330 core

in vec2 oTexCoords;
uniform sampler2D texture_diffuse1;
out vec4 color;

void main()
{
    color = vec4(texture(texture_diffuse1, oTexCoords));
}