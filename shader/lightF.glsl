#version 330 core
uniform vec3 emissiveColor;

out vec4 color;
void main()
{
    color = vec4(emissiveColor, 1.0f);
}