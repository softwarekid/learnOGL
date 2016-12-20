#version 330 core
layout (location = 0) out vec3 gPosition;
layout (location = 1) out vec3 gNormal;
layout (location = 2) out vec4 gAlbedoSpec;

in V2F
{
    vec3 position;
    vec3 normal;
    vec2 texCoord;
} fs_in;

uniform sampler2D textureDiffuse;
uniform sampler2D textureSpec;

void main()
{
    gPosition = fs_in.position;
    gNormal = normalize(fs_in.normal);
    gAlbedoSpec.rgb = texture(textureDiffuse, fs_in.texCoord).rgb;
    gAlbedoSpec.a = texture(textureSpec, fs_in.texCoord).r;
}
