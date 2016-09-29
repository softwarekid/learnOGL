#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec3 color;
layout (location = 3) in vec2 texCoord;

uniform mat4 MVPMatrix;

out vec3 myColor;
out vec2 myTexCoord;

void main()
{
    gl_Position = MVPMatrix * vec4(position, 1.0f);
    myColor = color;
    myTexCoord = vec2(texCoord.x, 1- texCoord.y);
}
