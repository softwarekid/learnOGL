#version 330 core
struct Material {
    sampler2D diffuse;
    sampler2D specular;
    float shininess;
}; 

struct Light {
    vec3 position;
  
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

uniform Material material;
uniform Light light;  

in vec3 oNormal;
in vec3 oPos;
in vec2 myTexCoord;

out vec4 color;

uniform vec3 lightColor;
uniform vec3 objectColor;
uniform vec3 viewerPos;

void main()
{
    vec3 ambient = vec3(texture(material.diffuse, myTexCoord)) * light.ambient;

    vec3 norm =normalize(oNormal);
    vec3 lightDir = normalize(light.position - oPos);
    float coefDiffuse = max(dot(norm, lightDir), 0.0f);
    vec3 diffuse = coefDiffuse * light.diffuse * vec3(texture(material.diffuse, myTexCoord));

    vec3 viewerDir = normalize(viewerPos - oPos);
    vec3 reflectDir = reflect(-lightDir, norm);

    float coefSpec = pow(max(dot(viewerDir, reflectDir), 0.0f), material.shininess);
    vec3 specular = vec3(texture(material.specular, myTexCoord)) * coefSpec * light.specular;

    vec3 result = ambient + diffuse + specular;
    color = vec4(result, 1.0f);
}