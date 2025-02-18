#include <iostream>
#include "renderer.h"
#include "glad/glad.h"
#include "shader.h"
#include <GLFW/glfw3.h>

PolyGardenRenderer::PolyGardenRenderer(){
    this->verticies = {
        -1, -1, -1,
         1, -1, -1,
        -1,  1, -1,
         1,  1, -1 
    };
    this->indicies = {
        0, 2, 3,
        0, 1, 3
    };

    this->uTrans = glm::mat4(1.0f);
    this->uTrans = glm::scale(this->uTrans, glm::vec3(0.3,0.3,0.3));
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cout << "Failed to initialize GLAD" << std::endl;
        return;
    }

    createBuffers();
    assignVertexAttribPointers();
}
PolyGardenRenderer::~PolyGardenRenderer(){
    glDeleteVertexArrays(1, &this->VAO);
    glDeleteBuffers(1, &this->VBO);
    glDeleteBuffers(1, &this->EBO);
    
}
void PolyGardenRenderer::render(){
        glClearColor(0.1, 0.1, 0.1, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        //glDepthMask(GL_TRUE);

        glBindVertexArray(this->VAO); 
        glDrawElements(GL_TRIANGLES, this->indicies.size(), GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
}
void PolyGardenRenderer::updatePhysics(float delta){
    //this->uTrans = glm::rotate(this->uTrans, 45.0f, glm::vec3(0,0,1));
}
void PolyGardenRenderer::createBuffers(){
    glGenVertexArrays(1, &this->VAO);
    glGenBuffers(1, &this->VBO);
    glGenBuffers(1, &this->EBO);
    glBindVertexArray(this->VAO);

    glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
    glBufferData(GL_ARRAY_BUFFER, this->verticies.size() * sizeof(float), this->verticies.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->indicies.size() * sizeof(unsigned int), this->indicies.data(), GL_STATIC_DRAW);
}
void PolyGardenRenderer::assignVertexAttribPointers(){
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0); 
}
