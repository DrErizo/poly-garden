#pragma once
#include <cstdint>
#include <sys/types.h>
#include "../libs/glm/glm/glm.hpp"
class Ball{
public:
    Ball(float posX, float posY, uint16_t radius);
    Ball();
    void setPosition(int16_t x, int16_t y);
    float x,y;
    ushort size;
    ushort angle;
private:
    glm::vec2 velocity;
    float verticies[4];
    uint8_t indecies[6];
};
