#include <cmath>
#include <cstdint>
#include <sys/types.h>
#include "ball.h"
Ball::Ball(){};
Ball::Ball(glm::vec2 pos, uint16_t size,glm::vec3 color, float speed) {
    this->pos = pos;
    this->size = size;
    this->vel = glm::vec2(((float)rand() / RAND_MAX) * 2.0f - 1.0f,((float)rand() / RAND_MAX) * 2.0f - 1.0f);
    this->speed = speed;
    this->color = color;
    this->health = 100;
    this->damage = 1;
    this->alive = true;
};
void Ball::setPosition(int16_t x, int16_t y){
    this->pos.x = x;
    this->pos.y = y;
};
