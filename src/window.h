#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class PolyGardenWindow{
public:
    PolyGardenWindow(unsigned int width, unsigned int height);
    ~PolyGardenWindow();
    inline GLFWwindow* getWindow(){
        return this->window;
    }
    unsigned int screenWidth;
    unsigned int screenHeight;
private:
    GLFWwindow *window;
    static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
};
