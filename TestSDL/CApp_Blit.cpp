#include "CApp.h"

void CApp::moveObject(SDL_Texture* texture, int x, int y, int angle, SDL_RendererFlip flip)
{
    SDL_Rect dest{x, y, 100, 100};
    SDL_Rect srcDest{x, y, 100, 100};

    SDL_RenderCopy(mainApp.getRenderer(), texture, NULL, &dest);
    SDL_RenderCopyEx(mainApp.getRenderer(), texture, NULL, &dest, angle, nullptr, flip);
}
