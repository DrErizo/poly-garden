#include "polyGarden.h"
#include <cstdint>
#include <iostream>

PolyGarden::PolyGarden(int amount, uint16_t width, uint16_t height, uint16_t size) : amount(amount){
    this->ballz.reserve(amount);
    for(int i = 0; i<amount;++i){
        this->ballz[i] = (Ball){(float)(rand() % width - size), (float)(rand() % height - size), size};
        
//        std::cout << i << ". " << this->ballz[i].x << "," << this->ballz[i].y << std::endl; 
    }
};
