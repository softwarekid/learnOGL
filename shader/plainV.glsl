#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
// layout (location = 2) in vec3 color;
layout (location = 2) in vec2 texCoord;

uniform mat4 modelMatrix;
uniform mat4 MVPMatrix;
out vec3 oNormal;
out vec3 oPos;

// out vec3 myColor;
out vec2 myTexCoord;

void main()
{
    gl_Position = MVPMatrix * vec4(position, 1.0f);
    oPos = vec3(modelMatrix * vec4(position, 1.0f));
    // the formal transform should be :
    // oNormal = mat3(tranpose(inverse(modelMatrix))) * normal;
    oNormal = normal;
    // myColor = color;
    myTexCoord = texCoord;
}