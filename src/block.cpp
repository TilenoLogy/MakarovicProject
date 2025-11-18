#include <block.hpp>

void Block::draw(SDL_Renderer* renderer, int x, int y) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_Rect r{x, y, 50, 50};
    SDL_RenderFillRect(renderer, &r);
    x_pos = x;
    y_pos = y;
}

void Block::update(float dt) {
}