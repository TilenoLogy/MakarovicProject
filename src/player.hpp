#pragma once

class Engine;

#include <SDL.h>
#include <config.hpp>
// float velocity = 0;
// float maxVelocity = 10;


class Player {
    // private:
    // Engine* engine;

protected:
    float gravity = 700.0f;
    float acceleration = 500.0f;
    float x = 100;
    float y = 100;
    int width = 50;
    int height = 50;
    Color col;
    bool air;
    float velocity = 0.0f;
    float velocityx = 0.0f;
    float maxvelocityx = 250.0f;
    bool floor = false;
    float kt = 1.0f; // koeficient trenja

public:
    // Player(Engine* enginePtr) : engine(enginePtr) {}
    Engine* engine;

    void move(int smer, float dt);
    void jump(float dt);
    void update(float dt);
    void draw(SDL_Renderer* renderer, Color color);
    void trenje(float dt);
};