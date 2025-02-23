#pragma once

#include <vector>
#include "../libs/glm/glm/glm.hpp"
#include "polyGarden.h"
class PolyGardenRenderer{
public:
    PolyGardenRenderer(PolyGarden &garden);
    ~PolyGardenRenderer();
    void render();
    void updatePhysics(float delta);
    inline glm::mat4 &getTransform(){
        return this->uTrans;
    }
private:
    glm::mat4 uTrans;
    void assignVertexAttribPointers();
    void createBuffers();
    unsigned int VAO, VBO, EBO;
    std::vector<float> verticies;
    std::vector<unsigned int> indicies;
};
