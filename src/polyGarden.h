#pragma once
#include "ball.h"
#include <vector>

class PolyGarden{
public:
    PolyGarden(int amount, uint16_t width, uint16_t height, uint16_t size);
    int amount; 
    std::vector<Ball> ballz;
};
