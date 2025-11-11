#include "clouds.hpp"

void Clouds::draw(SDL_Renderer* renderer, Color color) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_Rect r{x, y, width, height};
    SDL_RenderFillRect(renderer, &r);
}

void Clouds::update(float dt) {
}