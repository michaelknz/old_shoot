# version 430

in vec3 color;
in vec3 normal;
in vec3 Pos;

uniform vec3 lightPos;


out vec4 FragColor;

void main(){
    vec3 Ambient=color*vec3(0.1,0.1,0.1);
    vec3 lightDir=normalize(lightPos-Pos);
    vec3 Normal=normalize(normal);
    float diff=max(dot(lightDir,Normal),0.0);
    vec3 Diffuse=color*diff*vec3(0.5,0.5,0.5);
    FragColor=vec4(Ambient+Diffuse,1.0);
}