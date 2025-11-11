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

    static const int num_of_cubes = 20;
    Block* blocks[num_of_cubes][2];
    Block* block;

    int first_x = 50;
    int first_y = 550;

    int mouse_x = 0;
    int mouse_y = 0;


protected:
    Player* player;
    Clouds* cloud;

    SDL_Window* window;
    SDL_Renderer* renderer;
    Uint64 lastTick;
    float deltaTime;
};