// INIT,DELETE,UPDATE
#include <Engine.hpp>



void Engine::Initialize() {

    cloud = new Clouds();
    block = new Block();
    player = new Player(); // this
    player->engine = this;

    window = CreateWindow();
    renderer = CreateRenderer(window);

    running = true;

    lastTick = SDL_GetPerformanceCounter();
}



void Engine::Main() {
    Uint64 now = SDL_GetPerformanceCounter();
    deltaTime = (float)(now - lastTick) / (float)SDL_GetPerformanceFrequency();
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

    if (keys[SDL_SCANCODE_D] == 0 && keys[SDL_SCANCODE_A] == 0) {
        player->trenje(deltaTime);
    }

    SDL_SetRenderDrawColor(renderer, 0, 232, 232, 255);
    SDL_RenderClear(renderer);
    cloud->draw(renderer);
    player->update(deltaTime);
    player->draw(renderer, Color{255, 0, 0, 255});
    block->update(deltaTime);
    block->draw(renderer, Color{0, 255, 0, 255}, 200, 500);

    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_Rect r{0, SCREEN_HEIGHT - 100, SCREEN_WIDTH, 200};
    SDL_RenderFillRect(renderer, &r);

    SDL_RenderPresent(renderer);
}



void Engine::Shutdown() {
    delete cloud;
    delete player;
    delete block;



    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}