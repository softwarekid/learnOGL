#version 330 core
in vec4 FragPos;
uniform vec3 lightPos;
uniform float far_plane;

void main()
{
    // since cube map is sampled by direction, the depth value should
    // be the euclidian distance, not z value
    float lightDis = length(FragPos.xyz - lightPos);

    // since the default depth value stored are within the range (0,1)
    lightDis = lightDis / far_plane;

    gl_FragDepth = lightDis;
}
