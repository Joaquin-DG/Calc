/*
  Copyright (C) 1997-2025 Sam Lantinga <slouken@libsdl.org>

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely.
*/
#define SDL_MAIN_USE_CALLBACKS 1  /* use the callbacks instead of main() */
#include "myLib.h"
#include "SDL3/SDL_main.h"

Cal Calc;

/* This function runs once at startup. */
SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[])
{
    /* Create the window */
    if (!SDL_CreateWindowAndRenderer("Calc", 600, 800, 0, &Calc.window, &Calc.renderer)) {
        SDL_Log("Couldn't create window and renderer: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }
    
    Calc.SetDraw();
    
    return SDL_APP_CONTINUE;
}

/* This function runs when a new event (mouse input, keypresses, etc) occurs. */
SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event)
{
    if (event->type == SDL_EVENT_QUIT || event->key.key == SDLK_ESCAPE || event->key.key == SDLK_Q) {
        return SDL_APP_SUCCESS;  /* end the program, reporting success to the OS. */
    }
    //Click en un boton
    if(event->button.button == SDL_BUTTON_LEFT && event->button.down){
        float x = event->button.x;
        float y = event->button.y;
        for(auto const& [key, val] : Calc.num_buttons){
            if( x >= val.x && x <= (val.x + val.w) && y >= val.y && y <= (val.y + val.h)){
                SDL_Log("Click en el boton %d", key);
            }
        }
    }
    

    return SDL_APP_CONTINUE;
}

/* This function runs once per frame, and is the heart of the program. */
SDL_AppResult SDL_AppIterate(void *appstate)
{
    SDL_SetRenderDrawColor(Calc.renderer, 255,255,255, 255);
    SDL_RenderClear(Calc.renderer);
    Calc.Draw();
    
    SDL_RenderPresent(Calc.renderer);
    SDL_Delay(16); /* run at ~60 fps */ 
    return SDL_APP_CONTINUE;
}

/* This function runs once at shutdown. */
void SDL_AppQuit(void *appstate, SDL_AppResult result)
{
}
