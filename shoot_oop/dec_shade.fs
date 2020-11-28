# version 430

out vec4 FragColor;

in vec2 TexCoords;

uniform sampler2D Texture;

void main(){
    FragColor=texture(Texture,TexCoords);
}