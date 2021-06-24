#ifndef _CAPP_H_
#define _CAPP_H_

#include <SDL.h>
#include <SDL_image.h>

#include "App.h"
#include "Player.h"

class CApp
{
private:
    bool Running;

    SDL_Surface* Surf_Display;

    App mainApp;

    Player player_;

public:
    CApp();

    int OnExecute();

    bool OnInit();

    void OnEvent(SDL_Event* Event);
    void doKeyDown(SDL_KeyboardEvent* event);
    void doKeyUp(SDL_KeyboardEvent* event);

    void OnLoop();

    void OnRender();

    void OnCleanup();

    SDL_Texture *LoadTexture(char *filename);

    void moveObject(SDL_Texture *texture, int x, int y, int angle, SDL_RendererFlip flip = SDL_FLIP_NONE);
};

#endif
