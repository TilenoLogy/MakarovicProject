#pragma once
#include <SDL.h>


// float velocity = 0;
// float maxVelocity = 10;



struct color {
    int r = 255;
    int g = 0;
    int b = 0;
    int a = 255;
};


class Player {
protected:
    float gravity = 10.0f;
    float acceleration = 500.0f;
    int x = 100;
    int y = 100;
    int width = 50;
    int height = 50;
    color col;
    bool air;

public:
    void move(int smer, float dt);
    void jump(float dt);
    void update(float dt);
    void draw(SDL_Renderer* renderer);
};