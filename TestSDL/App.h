#pragma once
#include <SDL_render.h>

class App
{
private:
    SDL_Renderer *renderer;
    SDL_Window *window;
    
    int up = 0;
    int down = 0;
    int left = 0;
    int right = 0;
    
public:
    App(SDL_Renderer* renderer, SDL_Window* window);
    App();

    SDL_Renderer* getRenderer() const
    {
        return renderer;
    }

    SDL_Window* getWindow() const
    {
        return window;
    }

    void set_renderer(SDL_Renderer* renderer)
    {
        this->renderer = renderer;
    }

    void set_window(SDL_Window* window)
    {
        this->window = window;
    }

    int up1() const
    {
        return up;
    }

    void set_up(int up)
    {
        this->up = up;
    }

    int down1() const
    {
        return down;
    }

    void set_down(int down)
    {
        this->down = down;
    }

    int left1() const
    {
        return left;
    }

    void set_left(int left)
    {
        this->left = left;
    }

    int right1() const
    {
        return right;
    }

    void set_right(int right)
    {
        this->right = right;
    }
};
