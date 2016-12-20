#version 330 core

layout(location = 0) in vec3 vPosition;
layout(location = 1) in vec3 vNormal;
layout(location = 2) in vec3 vTexCoord;

out V2F
{
    vec3 position;
    vec3 normal;
    vec2 texCoord;
} vs_out;

uniform mat4 MVPMatrix;

void main()
{
    gl_Position = MVPMatrix * vPosition;
    vs_out.position = vPosition;
    vs_out.normal = normalize(vNormal);
    vs_out.texCoord = vTexCoord;
}
