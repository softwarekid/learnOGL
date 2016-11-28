#version 330 core

in vec3 FragPos;
uniform float farPlane;
uniform vec3 lightPos;

void main()
{
    float lightDis = length(FragPos - lightPos);
    lightDis = lightDis / farPlane;
    gl_FragDepth = lightDis;
}
