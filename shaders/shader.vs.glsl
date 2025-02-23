#version 330 core
layout (location = 0) in vec2 aPos;
layout (location = 1) in vec2 aDirection;
layout (location = 2) in vec3 aColor;

uniform mat4 uTransform;
uniform float uDeltaTime;

out vec3 vColor;
out vec2 vPos;
float speed = 1000;

void main(){
    //gl_Position = uTransform * vec4(aDirection * speed, 0.0f, 1.0f);
    vec2 newPosition = aPos + aDirection;
    gl_Position = uTransform * vec4(newPosition,0.0, 1.0);
    vColor = aColor;
}
