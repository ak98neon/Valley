#include <iostream>

#include "App.h"
#include "CApp.h"

bool CApp::OnInit()
{
    memset(&player_, 0, sizeof(Player));
    player_.x = 10;
    player_.y = 10;

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return false;
    }

    SDL_Window* window = SDL_CreateWindow("SDL",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          800, 600,
                                          0);

    if (!window)
    {
        std::cout << "Failed to create window\n";
        return false;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    mainApp.set_renderer(renderer);
    mainApp.set_window(window);

    SDL_SetRenderDrawColor(mainApp.getRenderer(), 96, 128, 255, 255);
    SDL_RenderClear(mainApp.getRenderer());

    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags))
    {
        printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
        return false;
    }

    SDL_Surface* window_surface = SDL_GetWindowSurface(window);

    if (!window_surface)
    {
        std::cout << "Failed to get the surface from the window\n";
        return false;
    }

    char shipFileName[] = "ship.png";
    SDL_Texture* player_texture = LoadTexture(shipFileName);
    player_.texture = player_texture;
    moveObject(player_.texture, player_.x, player_.y, 90);

    SDL_UpdateWindowSurface(window);
    SDL_RenderPresent(mainApp.getRenderer());

    return true;
}
