#include <SDL.h>
#include <iostream>

#include "renderer.hpp"

#include "player.hpp"



int WinMain() {
    Player* player = new Player();


    Initialize();
    SDL_Window* window = CreateWindow();
    SDL_Renderer* renderer = CreateRenderer(window);

    bool running = true;

    Uint64 lastTick = SDL_GetPerformanceCounter();

    while (running) {
        Uint64 now = SDL_GetPerformanceCounter();
        float deltaTime = (float)(now - lastTick) / (float)SDL_GetPerformanceFrequency();
        lastTick = now;


        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) running = false;
            if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) running = false;
            if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE) player->jump(deltaTime);
        }


        const Uint8* keys = SDL_GetKeyboardState(NULL);
        if (keys[SDL_SCANCODE_D]) player->move(1, deltaTime);
        if (keys[SDL_SCANCODE_A]) player->move(-1, deltaTime);

        SDL_SetRenderDrawColor(renderer, 0, 232, 232, 255);
        SDL_RenderClear(renderer);
        player->update(deltaTime);
        player->draw(renderer);

        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        SDL_Rect r{0, SCREEN_HEIGHT - 100, SCREEN_WIDTH, 200};
        SDL_RenderFillRect(renderer, &r);

        SDL_RenderPresent(renderer);
    }

    delete player;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}