#include <chrono>
#include <cstdlib>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "window.h"
#include "renderer.h"
#include "polyGarden.h"
#include "DEBUG.h"
#include "shader.h"

void processInput(GLFWwindow *window);

bool drawWireframe = false;
float deltaTime = 0.001;
auto frameBegin = std::chrono::high_resolution_clock::now();
auto frameEnd = std::chrono::high_resolution_clock::now();

int main(){
    srand(time(NULL));
    PolyGardenWindow window(1920, 1080);
    PolyGarden garden(10,1920,1080,3);
    PolyGardenRenderer renderer(garden);
    Shader shader("../shaders/shader.vs.glsl", "../shaders/shader.fs.glsl");

    while (!glfwWindowShouldClose(window.getWindow())){
        frameBegin = std::chrono::high_resolution_clock::now();
        processInput(window.getWindow());
        shader.setMat4("uTransform", renderer.getTransform());
        shader.setFloat("uDeltaTime", deltaTime);

        shader.use();
        renderer.updatePhysics(deltaTime);
        renderer.render();
        glfwSwapBuffers(window.getWindow());
        glfwSwapInterval(0);
        glfwPollEvents();
        frameEnd = std::chrono::high_resolution_clock::now();
        float deltaTime = std::chrono::duration<float>(frameEnd - frameBegin).count();
        if(DEBUG){
            printf("fps: %g\n",1 / deltaTime);
        }
    }
    return 0;
}

void processInput(GLFWwindow *window){
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
        glfwSetWindowShouldClose(window, true);
    }
    if (glfwGetKey(window, GLFW_KEY_F1) == GLFW_PRESS){
        DEBUG = !DEBUG;
    }
    if (glfwGetKey(window, GLFW_KEY_V) == GLFW_PRESS){
        (drawWireframe) ? glPolygonMode(GL_FRONT_AND_BACK, GL_LINE) : glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        drawWireframe = !drawWireframe;
    }
}
