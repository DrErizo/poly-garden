#include <glad/glad.h>
#include <GLFW/glfw3.h>

class PolyGardenWindow{
public:
    PolyGardenWindow(unsigned int width, unsigned int height);
    ~PolyGardenWindow();
    inline GLFWwindow* &getWindow(){
        return this->window;
    }
private:
    unsigned int screenWidth;
    unsigned int screenHeight;
    GLFWwindow *window;
};
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
