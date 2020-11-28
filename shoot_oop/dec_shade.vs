# version 430

layout(location=0) in vec3 position;
layout(location=2) in vec2 TexCoord;

uniform mat4 model;
uniform mat4 veiw;
uniform mat4 projection;

out vec2 TexCoords;

void main(){
    gl_Position=projection*veiw*model*vec4(position,1.0);
    TexCoords=TexCoord;
}