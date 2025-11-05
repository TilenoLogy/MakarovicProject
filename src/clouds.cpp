#include "clouds.hpp"

void Clouds::draw(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, col.r, col.g, col.b, col.a);
    SDL_Rect r{x, y, width, height};
    SDL_RenderFillRect(renderer, &r);
}

void Clouds::update(float dt) {
}