#version 330 core
layout (location = 0) in vec3 aPos;

uniform mat4 uTransform;

out vec3 sPos;

void main()
{
    gl_Position = uTransform * vec4(aPos, 1.0);
    sPos = aPos;
}
