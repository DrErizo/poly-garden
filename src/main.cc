#include <chrono>
#include <cstdlib>
#include "window.h"
#include "renderer.h"
#include "polyGarden.h"
#include "DEBUG.h"
#include "shader.h"
#include "libs.h"

void processInput(GLFWwindow *window);

bool drawWireframe = false;
float deltaTime = 0.001;
auto frameBegin = std::chrono::high_resolution_clock::now();
auto frameEnd = std::chrono::high_resolution_clock::now();

int main(){
    srand(time(NULL));
    PolyGardenWindow window(1920, 1080);
    PolyGarden garden(100,1920,1080);
    PolyGardenRenderer renderer(garden);
    Shader shader("../shaders/shader.vs.glsl", "../shaders/shader.fs.glsl");

    while (!glfwWindowShouldClose(window.getWindow())){
        frameBegin = std::chrono::high_resolution_clock::now();
        processInput(window.getWindow());

        garden.updatePhysics(deltaTime);
        renderer.rebuildBuffers();
        shader.use();
        renderer.render();
        glfwSwapBuffers(window.getWindow());
        glfwSwapInterval(0);
        glfwPollEvents();
        frameEnd = std::chrono::high_resolution_clock::now();
        deltaTime = std::chrono::duration<float>(frameEnd - frameBegin).count();
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
