#pragma once
#include <SDL.h>

class Clouds {
protected:
    int x = 0;
    int y = 0;
    int width = 100;
    int height = 50;
    struct color {
        int r = 255;
        int g = 255;
        int b = 255;
        int a = 255;
    } col;

public:
    void draw(SDL_Renderer* renderer);
    void update(float dt);
};