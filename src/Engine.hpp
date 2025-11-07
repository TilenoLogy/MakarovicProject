#pragma once
#include <config.hpp>

#include "block.hpp"
#include "clouds.hpp"
#include "player.hpp"
#include "renderer.hpp"
#include <SDL.h>


class Engine {
public:
    void Initialize();
    void Main();
    void Shutdown();
    bool running;
    Block* blocks[10];
    Block* block;
    bool first_time = true;
    int first_x = 50;


protected:
    Player* player;
    Clouds* cloud;

    SDL_Window* window;
    SDL_Renderer* renderer;
    Uint64 lastTick;
    float deltaTime;
};