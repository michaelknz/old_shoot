# version 430

layout(location=0) in vec3 position;
layout(location=1) in vec3 norm;

out vec3 color;
out vec3 normal;
out vec3 Pos;

uniform mat4 model;
uniform mat4 veiw;
uniform mat4 projection;

void main(){
    gl_Position=projection*veiw*model*vec4(position,1.0);
    color=vec3(0.0,1.0,1.0);
    normal=mat3(transpose(inverse(model)))*norm;
    Pos=vec3(model*vec4(position,1.0));
}