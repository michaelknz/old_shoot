# version 430

layout(location=0) in vec3 position;

out vec3 Color;

uniform mat4 model;
uniform mat4 projection;

void main(){
    gl_Position=projection*model*vec4(position,1.0);
    Color=vec3(1.0,1.0,1.0);
}