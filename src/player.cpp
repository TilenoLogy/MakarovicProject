#include "player.hpp"
#include "Engine.hpp"
#include <iostream>


void Player::update(float dt) {

    // for (int i = 0; i < engine->num_of_cubes; i++) {
    //     if (y + height < engine->blocks[0][0]->y_pos) {
    //         is_colliding = false;
    //     } else {
    //         is_colliding = true;
    //         break;
    //     }
    // }
    // if (velocity > 0.0f) air = true;


    if (!floor) {
        velocity += dt * gravity;
    }

    x += velocityx * dt;


    for (int i = 0; i < engine->blocks.size(); i++) {
        Block* blk = engine->blocks[i];
        if (!blk) continue;

        float px1 = x;
        float px2 = x + width;
        float py1 = y;
        float py2 = y + height;
        float bx1 = blk->x_pos;
        float bx2 = blk->x_pos + 50;
        float by1 = blk->y_pos;
        float by2 = blk->y_pos + 50;


        if (px2 > bx1 && px1 < bx2 && py2 > by1 && py1 < by2) {
            float overlap_Left = px2 - bx1;
            float overlap_Right = bx2 - px1;

            if (overlap_Left < overlap_Right) {
                // Collision from the left
                // simple collision with blocks
                x -= overlap_Left;
            } else {
                // Collision from the right

                x += overlap_Right;
            }

            velocityx = 0; // simple collision with blocks
        }
    }

    y += velocity * dt;
    is_colliding = false;
    floor = false;


    for (int i = 0; i < engine->blocks.size(); i++) {

        auto blk = engine->blocks[i];
        if (!blk) continue;

        float px1 = x;
        float px2 = x + width;
        float py1 = y;
        float py2 = y + height;
        float bx1 = blk->x_pos;
        float bx2 = blk->x_pos + 50.0f;
        float by1 = blk->y_pos;
        float by2 = blk->y_pos + 50.0f;



        if (px2 > bx1 && px1 < bx2 && py2 + 2 > by1 && py1 < by2) {
            float overlapTop = py2 - by1;    // penetration from above (player landed on block)
            float overlapBottom = by2 - py1; // penetration from below (hit block ceiling)
            is_colliding = true;
            if (overlapTop < overlapBottom) {
                // landed on top of block
                y -= overlapTop;
                velocity = 0.0f;
                floor = true;

            } else {
                // hit block from below
                y += overlapBottom;
                velocity = 0.0f;
            }
        }

        if (abs(velocity) < 0.5f) velocity = 0.0f;

        // else {
        //     is_colliding = false;
        // }
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


    if (floor) {

        velocity += -500;
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