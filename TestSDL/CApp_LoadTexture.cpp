#include "CApp.h"

SDL_Texture *CApp::LoadTexture(char *filename)
{
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename);
    return IMG_LoadTexture(mainApp.getRenderer(), filename);
}
