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
    for (int i = 0; i < 4; i++) {



        if ((x + width >= engine->blocks[i]->x_pos && x + width < engine->blocks[i]->x_pos + 5) && (y + height > engine->blocks[i]->y_pos && y < engine->blocks[i]->y_pos + 50)) {
            velocityx = 0; // simple collision with blocks
            x = engine->blocks[i]->x_pos - width;
        }

        if ((x < engine->blocks[i]->x_pos + 50 && x > engine->blocks[i]->x_pos + 45) && (y + height + 2 > engine->blocks[i]->y_pos && y < engine->blocks[i]->y_pos + 50)) {
            velocityx = 0; // simple collision with blocks
            x = engine->blocks[i]->x_pos + 50;
        }

        if (x + width > engine->blocks[i]->x_pos && x < engine->blocks[i]->x_pos + 50 && y < engine->blocks[i]->y_pos + 50 && y > engine->blocks[i]->y_pos + 45) {
            floor = true;
            y = engine->blocks[i]->y_pos + 50;
            velocity = 0;
        }
        if (engine->blocks[i]->x_pos < x + width && engine->blocks[i]->x_pos + 50 > x && engine->blocks[i]->y_pos < y + height && engine->blocks[i]->y_pos + 5 > y + height) {
            floor = true;
            air = false;
            y = engine->blocks[i]->y_pos - height;
            velocity = 0;
        }
    }
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