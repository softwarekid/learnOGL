#version 330 core
layout(location = 0) in vec3 position;

uniform mat4 modelTrans;

void main()
{
    gl_Position = modelTrans * vec4(position, 1.0f);
}