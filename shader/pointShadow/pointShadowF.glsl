#version 330 core
out vec4 fragColor;

in VS_OUT
{
    vec3 fragPos;
    vec2 texCoord;
    vec3 normal;
} fs_in;

uniform sampler2D diffuseTexture;
uniform samplerCube depthMap;

uniform vec3 lightPos;
uniform vec3 viewPos;
uniform float farPlane;

float ShadowCalculation(vec3 fragPos_)
{
    vec3 fragToLight = fragPos_ - lightPos;
    float closestDepth = texture(depthMap, lightPos).r;
    closestDepth = closestDepth * farPlane;

    float curDepth = length(fragToLight);
    float bias = 0.05f;
    float shadow = curDepth - bias > closestDepth?1.0f:0.0f;

    return shadow;
}

void main()
{
    vec3 color = texture(diffuseTexture , fs_in.texCoord).rgb;
    vec3 normal = normalize(fs_in.normal);

    vec3 ambient = 0.3 * color;
    vec3 lightColor = vec3(0.3f);

    vec3 lightDir = normalize(lightPos - fs_in.fragPos);
    float diff = max(dot(lightDir, normal), 0.0);
    vec3 diffuse = diff * lightColor;

    vec3 viewDir = normalize(viewPos - fs_in.fragPos);
    vec3 halfwayDir = normalize(lightDir + viewDir);
    float spec = pow(max(dot(normal, halfwayDir), 0.0), 64.0);
    vec3 specular = spec * lightColor;

    float shadow = ShadowCalculation(fs_in.fragPos);
    vec3 lighting = (ambient + (1.0 - shadow) * (diffuse + specular)) * color;
}
