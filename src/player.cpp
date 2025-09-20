#include "player.hpp"
#include <iostream>


void Player::update(float dt) {
    if (y + height < 620) {
        y += dt * gravity * 50;
        // std::cout << (dt * gravity);
    } else {
        air = false;
    }
    // SDL_Event e1;
    // if (SDL_PollEvent(&e1)) {
    //     if (e1.type == SDL_KEYDOWN && e1.key.keysym.sym == SDLK_d) {
    //         x += 10;
    //     } else if (e1.type == SDL_KEYDOWN && e1.key.keysym.sym == SDLK_a) {
    //         x -= 10;
    //     }
    // }
}

void Player::move(int smer, float dt) {
    if (smer == 1) { // right
        x += 1 * dt * acceleration;
    } else if (smer == -1) { // left
        x += -1 * dt * acceleration;
    }
}

void Player::jump(float dt) {
    printf("1");
    if (!air) {

        y -= dt * gravity * 1500;
        air = true;
    }
}

void Player::draw(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, col.r, col.g, col.b, col.a);
    SDL_Rect r{x, y, width, height};
    SDL_RenderFillRect(renderer, &r);
}