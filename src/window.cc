#include "window.h"
#include <iostream>
#include "DEBUG.h"
#include <GLFW/glfw3.h>

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
    glfwSetFramebufferSizeCallback(this->window, PolyGardenWindow::framebuffer_size_callback);
}
void PolyGardenWindow::framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    
    PolyGardenWindow* instance = static_cast<PolyGardenWindow*>(glfwGetWindowUserPointer(window));

    if (instance) {
        if (DEBUG) {
            std::cout << width << " x " << height << "\n";
        }
        
        instance->screenWidth = width;
        instance->screenHeight = height;

        float windowAspect = width / height;
        float contentAspect = 16.0f / 9.0f;
        if (windowAspect > contentAspect) {
            // Window is wider than content, letterbox top and bottom.
            float scale = height / (float)height * contentAspect;
            glViewport(0, (height - width * scale) / 2, width, width * scale);
        } else {
            // Window is taller than content, letterbox left and right.
            float scale = width / (float)height * (1.0f / contentAspect);
            glViewport((width - height * scale) / 2, 0, height * scale, height);
        }
        // Set up an orthographic projection matrix to match the content's aspect ratio.
        glOrtho(-contentAspect, contentAspect, -1, 1, -1, 1);
    }
}

PolyGardenWindow::~PolyGardenWindow(){
    glfwTerminate();
}

