#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec2 texCoord;

uniform mat4 MVP;

out vec2 oTexCoord;

int main()
{
    gl_Position = MVP * position;
    oTexCoord = texCoord;
}
