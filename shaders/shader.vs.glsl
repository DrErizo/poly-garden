#version 330 core
uniform vec2 uWindowSize;

layout (location = 0) in vec2 aPos;
layout (location = 1) in float aSize;
layout (location = 2) in vec3 aColor;

out vec3 vColor;

void main(){
    vec2 ndc = (aPos / uWindowSize) * 2.0 - 1.0;
    gl_Position = vec4(ndc, 0.0, 1.0);
    gl_PointSize = aSize;
    vColor = aColor;
}
