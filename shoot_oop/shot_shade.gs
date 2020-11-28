# version 430
layout(points) in;
layout(line_strip,max_vertices=2) out;

uniform float lazer_distance;

in VS_OUT{
    vec4 d;
}gs_in[];

void main(){
    gl_Position=gl_in[0].gl_Position;
    EmitVertex();
    gl_Position=lazer_distance*gs_in[0].d;
    EmitVertex();
    EndPrimitive();
}