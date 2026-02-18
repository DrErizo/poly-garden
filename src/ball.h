#pragma once
#include <cstdint>
#include <sys/types.h>
#include "../libs/glm/glm/glm.hpp"
class Ball{
public:
    Ball(glm::vec2 pos, uint16_t radius, glm::vec3 color, float speed);
    Ball();
    void setPosition(int16_t x, int16_t y);
    glm::vec3 color;
    glm::vec2 pos;
    glm::vec2 vel;
    uint16_t size;
    float speed;
    float health;
    float damage;
};
