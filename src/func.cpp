#include "myLib.h"



/*
    Funcion para hacer el set de los botones de la calculadora 
    El rectangulo del resultado no se tiene en cuenta aquí ya que no se va a usar, solo es output
    10 botones numericos
    1 Botón del punto decimal
    1 Botón de OFF
    1 Botón de CE
    6 Botones de operaciones {
        =
        + (Botón que va a ocupar el doble para que sea estetico)
        -
        *
        /
        SQRT
        }

*/
void Cal::SetDraw(){
    //10 botones numerico que empiezan en la mitad de abajo
    
    float x , y , h = 100, w  = 150;
    SDL_FRect aux = {0 , 0 , w , h};
    for(int i = 0; i<10 ; ++i){
        switch (i)
        {
        case 0:
            aux.x = 0;
            aux.y = 700;
            break;
        case 1: 
            aux.x = 0;
            aux.y = 600;
            break;
        case 4: 
            aux.x = 0;
            aux.y = 500;
            break;
        case 7: 
            aux.x = 0;
            aux.y = 400;
            break;
        case 2: 
            aux.x = 150;
            aux.y = 600;
            break;
        case 5: 
            aux.x = 150;
            aux.y = 500;
            break;
        case 8: 
            aux.x = 150;
            aux.y = 400;
            break;
        case 3: 
            aux.x = 300;
            aux.y = 600;
            break;
                
        case 6: 
            aux.x = 300;
            aux.y = 500;
            break;
                
        case 9: 
            aux.x = 300;
            aux.y = 400;
            break;
                
        default:
            break;
        }    
        this->num_buttons[i] = aux; 
    }
}

void Cal::Draw(){
 //Por ahora dibujar solo los numeros del 0 al 9 del map num_buttons , renderizar los rectangulos
    SDL_SetRenderDrawColor(this->renderer, 255,0,0,255); //Rojo
    for(auto const&[key, val] : this->num_buttons){ //porque const& : 
        SDL_RenderFillRect(this->renderer, &val);    
    }
}