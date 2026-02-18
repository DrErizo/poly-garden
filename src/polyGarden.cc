#include "polyGarden.h"
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <ctime>
#include <iostream>

PolyGarden::PolyGarden(int amount, uint16_t width, uint16_t height) : amount(amount), width(width), height(height){
    std::srand(std::time(NULL));
    this->balls.reserve(amount);
    for(int i = 0; i<amount;++i){
        balls.push_back(Ball(
            glm::vec2(((float)rand() / RAND_MAX) * 2.0f - 1.0f,
            ((float)rand() / RAND_MAX) * 2.0f - 1.0f),
            40.0f,
            glm::vec3(((float)rand() / RAND_MAX), ((float)rand() / RAND_MAX),((float)rand() / RAND_MAX)),
            0.5f)
        );
    }
};

void PolyGarden::updatePhysics(float delta) {
    for (auto &ball : balls) {
        ball.pos.x += ball.vel.x * delta;
        ball.pos.y += ball.vel.y * delta;

        if (ball.pos.x > 1.0f || ball.pos.x < -1.0f) ball.vel.x *= -1;
        if (ball.pos.y > 1.0f || ball.pos.y < -1.0f) ball.vel.y *= -1;
    }

    for (size_t i = 0; i < balls.size(); ++i) {
        for (size_t j = 0; j < balls.size(); ++j) {
            glm::vec2 posDelta = balls[j].pos - balls[i].pos;
            float radius = ((balls[i].size * 0.5 / this->width) + (balls[i].size * 0.5 / this->height)) * 0.5; 
            float radiusSum = radius * 2;
            float dist = sqrt(dot(posDelta,posDelta)); 
            if(dot(posDelta,posDelta) < radiusSum * radiusSum){
                glm::vec2 normal = (dist > 0.0f) ? posDelta / dist : glm::vec2(1.0f,0.0f);
                float overlap = radiusSum - dist;
                glm::vec2 correction = normal * (overlap * 0.5f);
                balls[i].pos -= correction;
                balls[j].pos += correction;
            }
        }
    }
}
