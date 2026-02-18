#pragma once
#include "ball.h"
#include <vector>

class PolyGarden{
public:
    PolyGarden(){};
    PolyGarden(int amount, uint16_t width, uint16_t height);
    void updatePhysics(float delta);
    int amount; 
    ushort width, height;
    std::vector<Ball> balls;
};
