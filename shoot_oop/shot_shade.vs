# version 430
layout(location=0) in vec3 position;

uniform mat4 model;
uniform mat4 veiw;
uniform mat4 projection;

uniform vec3 gun_dir;

out VS_OUT{
    vec4 d;

}vs_out;

void main(){
    gl_Position=projection*veiw*model*vec4(position,1.0);
    vs_out.d=projection*veiw*(model*vec4(gun_dir,0.0)+model*vec4(position,1.0));
}