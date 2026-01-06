#ifndef MY_LIB_H
#define MY_LIB_H

#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <SDL3_ttf/SDL_textengine.h>
#include <array>
#include <map>
#include <string>
#include <sstream>
#include <cmath>


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

        //double value reffering to the number shown in the display
        double final_value , value, value_aux;
        //std::string showing the number in the display
        std::string display_string;
        std::string num_string = ""; //string to build the number when pressing buttons
        //Stringstream to convert from string to double
        std::stringstream ss;
        std::map<char, double(*)(double, double)> operations;
        //Previous operation (+,-,*,/)
        char previous_op;
        bool isalpha = false;

    //Functions
    void SetAll();
    void Draw();
    int OnClick(float& x, float& y);
    void DoButton(int& n);
    bool LastnotOperator();
};


#endif // MY_LIB_H