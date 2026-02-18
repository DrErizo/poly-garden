#pragma once

#include <vector>
#include "../libs/glm/glm/glm.hpp"
#include "polyGarden.h"
class PolyGardenRenderer{
public:
    PolyGardenRenderer(PolyGarden &garden);
    ~PolyGardenRenderer();
    void render();
    void rebuildBuffers();
    void updatePhysics(float delta);
private:
    PolyGarden &garden;
    void assignVertexAttribPointers();
    void createBuffers();
    unsigned int VAO, VBO, EBO;
    std::vector<float> verticies;
    std::vector<unsigned int> indicies;
};
