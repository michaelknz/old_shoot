#version 430
out vec4 FragColor;
uniform float del_alpha;
void main(){
    FragColor=vec4(1.0,1.0,0.0,(1.0-del_alpha));
}