#version 330 core

in vec3 myColor;
in vec2 myTexCoord;

out vec4 color;
uniform sampler2D boxTexture;
uniform sampler2D faceTexture;

void main()
{
    color = mix(texture(boxTexture, myTexCoord), texture(faceTexture,  myTexCoord), 1.0);
    // color =texture(faceTexture, myTexCoord);
}