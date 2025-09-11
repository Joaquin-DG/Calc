#ifndef MY_LIB_H
#define MY_LIB_H

// Your function declarations go here
#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <SDL3_ttf/SDL_textengine.h>
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
    //double value reffering to the number shown in the display
    double display_value;
    //std::string showing the number in the display
    std::string display_string;

    public:
    // Constructor
    Cal(SDL_Window *win, SDL_Renderer *ren){
        this->window = win;
        this->renderer = ren;
    };
    ~Cal(){};

    // Attributes
    SDL_Window *window;
    SDL_Renderer *renderer;
    std::map<int,SDL_FRect> num_buttons;
    SDL_FRect number_display{50,100,500,100};

    //Functions
    void SetDraw();
    void Draw();
    int OnClick(float x, float y);
    void DoButton(int n);
};


#endif // MY_LIB_H