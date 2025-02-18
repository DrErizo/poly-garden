#include "window.h"
#include <iostream>
#include "DEBUG.h"
#include <GLFW/glfw3.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    if(DEBUG){
        std::cout << width << " x " <<height << "\n";
    }
    glViewport(0, 0, width, height);
}
PolyGardenWindow::PolyGardenWindow(unsigned int width, unsigned int height) : screenWidth(width), screenHeight(height){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    this->window = glfwCreateWindow(width, height, "PolyGarden | Erizo", NULL, NULL); 
    if (window == NULL){
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return;
    }
    glfwMakeContextCurrent(this->window);
    glfwSetWindowUserPointer(this->window,this);
    glfwSetFramebufferSizeCallback(this->window, framebuffer_size_callback);
}

PolyGardenWindow::~PolyGardenWindow(){
    glfwTerminate();
}

