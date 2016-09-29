#version 330 core

in vec2 TexCoords;
uniform sampler2D maintex;
out vec4 color;

void main()
{
    vec4 outColor = texture(maintex, TexCoords);
    // if (outColor.a < 0.1)
    // {
    //     discard;
    // }    
    color = outColor;
}