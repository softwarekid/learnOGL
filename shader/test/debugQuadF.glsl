#version 330 core

uniform sampler2D depthMap;
out vec4 color;
in vec2 OTexCoords;

void main()
{
    float depthVal = texture(depthMap, OTexCoords).r;
    color = vec4(vec3(depthVal), 1.0f); 
    // color = vec4(1.0f, 0.0f, 0.0f, 1.0f); 
}