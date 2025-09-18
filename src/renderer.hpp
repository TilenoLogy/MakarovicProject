#pragma once
#include <SDL.h>
#include <iostream>

#define SCREEN_WIDTH 1080
#define SCREEN_HEIGHT 720


int Initialize();
SDL_Window* CreateWindow();
SDL_Renderer* CreateRenderer(SDL_Window* window);