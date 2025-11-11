#pragma once
#include <SDL.h>
#include <config.hpp>

class Clouds {
protected:
    int x = 0;
    int y = 0;
    int width = 100;
    int height = 50;


public:
    void draw(SDL_Renderer* renderer, Color color);
    void update(float dt);
};