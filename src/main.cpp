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

Cal Calc(nullptr, nullptr);

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
    if (event->type == SDL_EVENT_QUIT || event->key.key == SDLK_ESCAPE) {
        return SDL_APP_SUCCESS;  /* end the program, reporting success to the OS. */
    }
    
    //Click en un boton
    
    if(event->button.button == SDL_BUTTON_LEFT && event->button.down){
        int n = Calc.OnClick(event->button.x, event->button.y);
        //Funcion que diga lo que hace cada uno.
        SDL_Log("You clicked on button %d", n);
        Calc.DoButton(n);
    }
    
    
    return SDL_APP_CONTINUE;
}

/* This function runs once per frame, and is the heart of the program. */
SDL_AppResult SDL_AppIterate(void *appstate)
{
    SDL_SetRenderDrawColor(Calc.renderer, 0,0,0,255); // Black
    SDL_RenderClear(Calc.renderer);

    SDL_SetRenderDrawColor(Calc.renderer,0,0,255,255);
    SDL_RenderFillRect(Calc.renderer,&Calc.number_display);
    Calc.Draw();
    
    SDL_RenderPresent(Calc.renderer);
    SDL_Delay(16); /* run at ~60 fps */ 
    return SDL_APP_CONTINUE;
}

/* This function runs once at shutdown. */
void SDL_AppQuit(void *appstate, SDL_AppResult result)
{
}
