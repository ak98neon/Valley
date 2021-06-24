#include <cstdio>

#include "CApp.h"

void CApp::OnRender()
{
    SDL_RenderClear(mainApp.getRenderer());

    moveObject(player_.texture, player_.x, player_.y, 90);
    SDL_RenderPresent(mainApp.getRenderer());
}
