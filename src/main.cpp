#include <SDL.h>
#include <iostream>

#include "Engine.hpp"



int WinMain() {
    Engine* CEngine = new Engine();

    // Block* block = new Block();

    CEngine->Initialize();


    while (CEngine->running) {
        CEngine->Main();
    }

    CEngine->Shutdown();
    return 0;
}