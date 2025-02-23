#include <cmath>
#include <cstdint>
#include <sys/types.h>
#include "ball.h"
Ball::Ball(){};
Ball::Ball(float posX, float posY, uint16_t radius){
    this->x = posX;
    this->y = posY;
    this->size = radius;
    this->angle = rand() / (float)RAND_MAX * M_PI * 2.0f;
};
void Ball::setPosition(int16_t x, int16_t y){
    this->x = x;
    this->y = y;
};
