#include <cstdio>

#include "CApp.h"

void CApp::OnEvent(SDL_Event* Event)
{
    switch (Event->type)
    {
        case SDL_QUIT:
            printf("Exit");
            Running = false;
            break;

        case SDL_KEYDOWN:
            doKeyDown(&Event->key);
            break;

        case SDL_KEYUP:
            doKeyUp(&Event->key);
            break;

        default:
            break;
    }

    if (mainApp.up1() == 1)
    {
        player_.y -= 4;
    }

    if (mainApp.down1() == 1)
    {
        player_.y += 4;
    }

    if (mainApp.left1() == 1)
    {
        player_.x -= 4;
    }

    if (mainApp.right1() == 1)
    {
        player_.x += 4;
    }
}

void CApp::doKeyDown(SDL_KeyboardEvent* event)
{
    if (event->repeat == 0)
    {
        if (event->keysym.scancode == SDL_SCANCODE_W)
        {
            mainApp.set_up(1);
        }

        if (event->keysym.scancode == SDL_SCANCODE_S)
        {
            mainApp.set_down(1);
        }

        if (event->keysym.scancode == SDL_SCANCODE_A)
        {
            mainApp.set_left(1);
        }

        if (event->keysym.scancode == SDL_SCANCODE_D)
        {
            mainApp.set_right(1);
        }
    }
}

void CApp::doKeyUp(SDL_KeyboardEvent* event)
{
    if (event->repeat == 0)
    {
        if (event->keysym.scancode == SDL_SCANCODE_W)
        {
            mainApp.set_up(0);
        }

        if (event->keysym.scancode == SDL_SCANCODE_S)
        {
            mainApp.set_down(0);
        }

        if (event->keysym.scancode == SDL_SCANCODE_A)
        {
            mainApp.set_left(0);
        }

        if (event->keysym.scancode == SDL_SCANCODE_D)
        {
            mainApp.set_right(0);
        }
    }
}
