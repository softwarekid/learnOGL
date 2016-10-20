#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 texCoord;

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projMatrix;

out VS_OUT
{
    vec3 fragPos;
    vec2 texCoord;
    vec3 normal;
} vs_out;

void main()
{
    gl_Position = projMatrix * viewMatrix * modelMatrix * vec4(position, 1.0f);
    vs_out.fragPos = vec3((modelMatrix * vec4(position, 1.0f)));
    vs_out.texCoord = texCoord;
    vs_out.normal =  transpose(inverse(mat3( modelMatrix))) * normal;
}
