#ifndef MY_LIB_H
#define MY_LIB_H

// Your function declarations go here
#include <iostream>
#include <SDL3/SDL.h>
#include <array>
#include <map>

#define CE 10
#define OFF 11
#define SQRT 12
#define DIVISION 13
#define MULT 14
#define MINUS 15
#define ADD 16
#define EQUAL 17
#define DECIMAL_COMMA 18

class Cal{ 
    private:
    
    public:
    SDL_Window *window;
    SDL_Renderer *renderer;
    
    std::map<int,SDL_FRect> num_buttons;

    SDL_FRect number_display{50,100,500,100};
    void SetDraw();
    void Draw();
    int OnClick(float x, float y);
    
};


#endif // MY_LIB_H