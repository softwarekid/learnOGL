#version 330 core

in VS_OUT
{
    vec3 FragPos;
    vec3 Normal;
    vec2 TexCoords;
    vec4 FragPosLightSpace;
} fs_in;


uniform sampler2D diffuseTexture;
uniform sampler2DShadow depthMap;
uniform vec3 lightPos;
uniform vec3 viewPos;


out vec4 FragColor;

float ShadowCalculation(vec4 fragPosLightSpace, vec3 normal, vec3 lightDir)
{
    vec3 projCoords = fragPosLightSpace.xyz/fragPosLightSpace.w;
    projCoords = projCoords * 0.5f + 0.5f;
    float currentDepth = projCoords.z;
    float bias = max(0.05f * (1.0f - dot(lightDir, normal)), 0.005f);
    float closestDepth = texture(depthMap, vec3(projCoords.xy, currentDepth - bias));
    float shadow = closestDepth;
    // float shadow  = currentDepth > closestDepth ? 1.0f :0.0f;

    // float shadow = currentDepth - bias > closestDepth  ? 1.0 : 0.0;     

    // float shadow = 0.0f;
    // vec2 texelSize = 1.0 / textureSize(depthMap, 0);
    // for(int x = -1; x <= 1; ++x)
    // {
    //     for(int y = -1; y <= 1; ++y)
    //     {
    //         float pcfDepth = texture(depthMap, projCoords.xy + vec2(x, y) * texelSize).r; 
    //         shadow += currentDepth - bias > pcfDepth ? 1.0 : 0.0;        
    //     }    
    // }
    // shadow /= 9.0;

    if(currentDepth > 1.0f)
    {
        shadow = 1.0f;
    } 

    return 1- shadow;
}

void main()
{
    vec3 color = texture(diffuseTexture, fs_in.TexCoords).rgb;
    vec3 normal = normalize(fs_in.Normal);
    vec3 lightColor = vec3(1.0f);

    // ambient
    vec3 ambient = 0.3 * color;

    // diffuse
    vec3 lightDir = normalize(lightPos - fs_in.FragPos);
    float diff = max(dot(lightDir, normal), 0.0f);
    vec3 diffuse = diff * lightColor;

    // specular
    vec3 viewDir = normalize(viewPos - fs_in.FragPos);
    vec3 halfDir = normalize(lightDir + viewDir);
    float spec = pow(max(dot(normal, halfDir), 0.0f), 64.0f);
    vec3 specular = spec * lightColor;

    // calculate shadow
    float shadow = ShadowCalculation(fs_in.FragPosLightSpace, normal, lightDir);
    vec3 lighting = (ambient + (1.0f - shadow) * (diffuse + specular)) * color;
    FragColor = vec4(lighting, 1.0f);
}