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
            glm::vec2((float)(rand() % width),
            (float)(rand() % height)),
            40.0f,
            glm::vec3(((float)rand() / RAND_MAX), ((float)rand() / RAND_MAX),((float)rand() / RAND_MAX)),
            300.0f)
        );
    }
};

void PolyGarden::updatePhysics(float dt, float windowWidth, float windowHeight){
for (auto &ball : balls) {
        ball.pos += ball.vel * dt * ball.speed;
        float radius = ball.size * 0.5f;

        if (ball.pos.x - radius < 0) {
            ball.vel.x = std::abs(ball.vel.x);
            ball.pos.x = radius;
        } else if (ball.pos.x + radius > windowWidth) {
            ball.vel.x = -std::abs(ball.vel.x);
            ball.pos.x = windowWidth - radius;
        }

        if (ball.pos.y - radius < 0) {
            ball.vel.y = std::abs(ball.vel.y);
            ball.pos.y = radius;
        } else if (ball.pos.y + radius > windowHeight) {
            ball.vel.y = -std::abs(ball.vel.y);
            ball.pos.y = windowHeight - radius;
        }
    }
    for (int i = 0; i < balls.size(); ++i) {
        for (int j = 0; j + 1 < balls.size(); ++j) {
            glm::vec2 delta = balls[j].pos - balls[i].pos;
            float radiusSum = 0.5f * (balls[i].size + balls[j].size);
            float dist = glm::length(delta); 
            if(dist < radiusSum){
                balls[i].health--;
                glm::vec2 normal = (dist > 0.0f) ? delta / dist : glm::vec2(1.0f,0.0f);
                const float restitution = 1.0f;
                float relativeVel = glm::dot(balls[i].vel - balls[j].vel, normal);
                if(relativeVel > 0.0f) {
                    float impulse = relativeVel * (1.0f + restitution) * 0.5f;
                    balls[i].vel -= impulse * normal;
                    balls[j].vel += impulse * normal;
                }
                float overlap = radiusSum - dist;
                glm::vec2 correction = normal * (overlap * 0.5f);
                balls[i].pos -= correction;
                balls[j].pos += correction;
            }
        }
    }
}
