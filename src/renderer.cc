#include <cstdio>
#include "renderer.h"
#include "shader.h"
#include "libs.h"

struct BallData {
    glm::vec2 pos;
    float size;
    glm::vec3 color;
};

PolyGardenRenderer::PolyGardenRenderer(PolyGarden &garden) : garden(garden){

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cout << "Failed to initialize GLAD" << std::endl;
        return;
    }
    glEnable(GL_PROGRAM_POINT_SIZE);
    createBuffers();
    assignVertexAttribPointers();

}
PolyGardenRenderer::~PolyGardenRenderer(){
    glDeleteVertexArrays(1, &this->VAO);
    glDeleteBuffers(1, &this->VBO);
    
}
void PolyGardenRenderer::render(){
        glClearColor(0, 0, 0, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        glBindVertexArray(this->VAO); 
        glDrawArrays(GL_POINTS, 0 ,garden.balls.size());
        glBindVertexArray(0);
}
void PolyGardenRenderer::rebuildBuffers() {
    std::vector<BallData> ballsData;
    ballsData.reserve(garden.balls.size());

    for (auto &ball : garden.balls) {
        BallData data;
        data.pos = ball.pos;
        data.size = ball.size;
        data.color = ball.color;
        ballsData.push_back(data);
        //printf("x: %g, y: %g\n", ball.pos.x, ball.pos.y);
    }

    glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
    glBufferData(GL_ARRAY_BUFFER, ballsData.size() * sizeof(BallData), ballsData.data(), GL_DYNAMIC_DRAW);
}

void PolyGardenRenderer::createBuffers(){
    glGenVertexArrays(1, &this->VAO);
    glGenBuffers(1, &this->VBO);

    glBindVertexArray(this->VAO);
    glBindBuffer(GL_ARRAY_BUFFER, this->VBO);

    glBufferData(GL_ARRAY_BUFFER, garden.balls.size() * sizeof(BallData), nullptr, GL_DYNAMIC_DRAW);
}
void PolyGardenRenderer::assignVertexAttribPointers(){
    glBindVertexArray(this->VAO);
    glBindBuffer(GL_ARRAY_BUFFER, this->VBO); 

    //position
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(BallData), (void*)0);
    
    //size
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 1, GL_FLOAT, GL_FALSE, sizeof(BallData), (void*)offsetof(BallData, size));

    //color
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(BallData), (void*)offsetof(BallData, color));

    glBindBuffer(GL_ARRAY_BUFFER, 0); 
}
