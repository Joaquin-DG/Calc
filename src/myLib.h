#ifndef MY_LIB_H
#define MY_LIB_H

// Your function declarations go here
#include <iostream>
#include <SDL3/SDL.h>
#include <array>
#include <map>

class Cal{ 
    private:
    
    public:
    SDL_Window *window;
    SDL_Renderer *renderer;
    
    std::map<int,SDL_FRect> num_buttons;
    std::array<SDL_FRect,9> non_num_buttons;
    SDL_FRect number_display;
    void SetDraw();
    void Draw();
    
};


#endif // MY_LIB_H