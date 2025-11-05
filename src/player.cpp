#include "player.hpp"
#include "Engine.hpp"
#include <iostream>


void Player::update(float dt) {
    if (y + height < 620) {
        velocity += dt * gravity;
        floor = false;
        // std::cout << (dt * gravity);
    } else if ((y + height >= 620) && (floor == false)) {
        floor = true;
        y = 620 - height;
        velocity = 0;
        air = false;
    }
    x += velocityx * dt;
    y += velocity * dt;
    std::cout << engine->block->x_pos << "\n";
    if ((x + width >= engine->block->x_pos && x + width < engine->block->x_pos + 5) && (y + height > 400 && y < 450)) {
        velocityx = 0; // simple collision with blocks
        x = 200 - width;
    }

    if ((x < 250 && x > 245) && (y + height > 400 && y < 450)) {
        velocityx = 0; // simple collision with blocks
        x = 250;
    }

    if (x + width > 200 && x < 250 && y < 450 && y > 445) {
        floor = true;
        y = 450;
        velocity = 0;
    }
    // if (engine && engine->block->x == 10) {
    //      std::cout << "Test";
    //  }
}
void Player::move(int smer, float dt) {

    if (smer == 1) { // right
        if (velocityx < maxvelocityx)
            velocityx += 500 * dt;
    } else if (smer == -1) { // left
        if (velocityx > -maxvelocityx)
            velocityx -= 500 * dt;
    }
}

void Player::jump(float dt) {

    if (!air) {

        velocity += -500;

        air = true;
    }
}

void Player::draw(SDL_Renderer* renderer, Color color) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_Rect r{(int)x, (int)y, width, height};
    SDL_RenderFillRect(renderer, &r);
}

void Player::trenje(float dt) {
    if (floor) {
        if (velocityx > 0) {
            velocityx -= kt * gravity * dt;
            if (velocityx < 0) velocityx = 0;
        } else if (velocityx < 0) {
            velocityx += kt * gravity * dt;
            if (velocityx > 0) velocityx = 0;
        }
    }
}