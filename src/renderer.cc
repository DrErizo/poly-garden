#include <iostream>
#include "renderer.h"
#include "glad/glad.h"
#include "shader.h"
#include <GLFW/glfw3.h>

PolyGardenRenderer::PolyGardenRenderer(PolyGarden &garden){
    this->verticies.reserve(garden.amount * 60);
    this->indicies.reserve(garden.amount * 6);

    int offset = 0;
    for (int i = 0; i < garden.amount; ++i) {
        Ball ball = garden.ballz[i];
        float x = ball.x;
        float y = ball.y;
        float size = ball.size;
        float directionX = sinf(ball.angle);
        float directionY = cosf(ball.angle);
        float colorR = (rand() % 255) / 255.0f;
        float colorG = (rand() % 255) / 255.0f;
        float colorB = (rand() % 255) / 255.0f;
        

        //verticies
        int values[4][2] = {{-1, -1}, {1, -1}, {-1,  1}, {1,  1}};
        for(int j = 0; j < 4 ; ++j){
            this->verticies.push_back(values[j][0]);
            this->verticies.push_back(values[j][1]);

            //direction
            this->verticies.push_back(directionX);
            this->verticies.push_back(directionY);
           
            //color
            this->verticies.push_back(colorR);
            this->verticies.push_back(colorG);
            this->verticies.push_back(colorB);
        }

        //indices
        this->indicies.push_back(offset);    
        this->indicies.push_back(offset + 1);
        this->indicies.push_back(offset + 2);
        this->indicies.push_back(offset + 1);
        this->indicies.push_back(offset + 3);
        this->indicies.push_back(offset + 2);
        

        offset += 7; 
    }
    this->uTrans = glm::mat4(1.0f);
    this->uTrans = glm::scale(this->uTrans, glm::vec3(0.1,0.1,0.1));
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
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
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
    glBindBuffer(GL_ARRAY_BUFFER, this->VBO); 

    //position
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)0);

    //direction
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)(2 * sizeof(float)));

    //color
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)(4 * sizeof(float)));

    glBindBuffer(GL_ARRAY_BUFFER, 0); 
}
