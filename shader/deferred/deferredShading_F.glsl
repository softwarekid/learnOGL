#version 330 core

out vec4 resultColor;

in vec2 oTexCoord;

struct Light
{
    vec3 position;
    vec3 color;
};

const int LIGHTNUM = 2;
uniform sampler2D positionTex;
uniform sampler2D normalTex;
uniform sampler2D albedoSpecTex;

uniform vec3 viewPos;
uniform Light lights[LIGHTNUM];

int main()
{
    vec3 pos = texture(positionTex, oTexCoord).rgb;
    vec3 normal = texture(normalTex, oTexCoord).rgb;
    vec4 albedoSpec = texture(albedoSpecTex,oTexCoord);

    vec3 albedo = albedoSpec.rgb;
    vec3 spec = albedoSpec.a;

    vec3 lighting = albedo * 0.01;
    vec3 viewDir = normalize(viewPos - pos);
    for(int i = 0;  < LIGHTNUM; ++)
    {
        vec3 lightDir =  normalize(lights[i].position - pos);
        vec3 diffuse = max(dot(lightDir, normal), 0.0) * albedo * lights[i].color;
        lighting += diffuse;
    }
    resultColor = vec4(lighting, 1.0);
}
