#pragma once
#include <SDL.h>
#include <config.hpp>



class Block {
public:
    void draw(SDL_Renderer* renderer, Color color, int x, int y);
    void update(float dt);
    int x_pos;
    int y_pos;
};