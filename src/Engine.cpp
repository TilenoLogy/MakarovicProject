#include <Engine.hpp>



void Engine::Initialize() {

    cloud = new Clouds();
    // block = new Block();
    player = new Player();
    player->engine = this;

    window = CreateWindow();
    renderer = CreateRenderer(window);

    running = true;

    lastTick = SDL_GetPerformanceCounter();

    for (int j = 0; j < 2; j++) {

        for (int i = 0; i < num_of_cubes; i++) {
            blocks[i][j] = new Block();
            blocks[i][j]->x_pos = first_x;
            first_x += 50;
            blocks[i][j]->y_pos = first_y;
        }
        first_x = 50;
        first_y += 50;
    }
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
    SDL_GetMouseState(&mouse_x, &mouse_y);


    const Uint8* keys = SDL_GetKeyboardState(NULL);
    if (keys[SDL_SCANCODE_D]) player->move(1, deltaTime);
    if (keys[SDL_SCANCODE_A]) player->move(-1, deltaTime);

    if (keys[SDL_SCANCODE_D] == 0 && keys[SDL_SCANCODE_A] == 0) {
        player->trenje(deltaTime);
    }

    SDL_SetRenderDrawColor(renderer, 0, 232, 232, 255);
    SDL_RenderClear(renderer);
    cloud->draw(renderer, Color{255, 255, 255, 255});
    player->update(deltaTime);
    player->draw(renderer, Color{255, 0, 0, 255});



    for (int j = 0; j < 2; j++) {
        if (j == 0) {
            for (int i = 0; i < num_of_cubes; i++) {
                blocks[i][j]->update(deltaTime);
                blocks[i][j]->draw(renderer, Color{0, 255, 0, 255}, blocks[i][j]->x_pos, blocks[i][j]->y_pos);
            }
        } else {
            for (int i = 0; i < num_of_cubes; i++) {
                blocks[i][j]->update(deltaTime);
                blocks[i][j]->draw(renderer, Color{79, 44, 19, 255}, blocks[i][j]->x_pos, blocks[i][j]->y_pos);
            }
        }
    }
    SDL_RenderPresent(renderer);
}



void Engine::Shutdown() {
    delete cloud;
    delete player;
    // delete block;
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < num_of_cubes; i++) {
            delete blocks[i][j];
        }
    }


    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}