#include <cstdint>
#include "../libs/glm/glm/glm.hpp"
class Ball{
public:
    Ball(int16_t posX, int16_t posY, uint16_t radius);
    void setPosition(int16_t x, int16_t y);
private:
    uint16_t size;
    glm::vec2 direction;
    glm::vec2 velocity;
    int16_t x,y;
};
