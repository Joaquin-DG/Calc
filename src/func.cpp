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
    for(int i = 0; i<19 ; ++i){
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
        case CE: //CE button
            aux.x = 0;
            aux.y = 300;
            break;
            
        case OFF: 
            aux.x = 150;
            aux.y = 300;
            break; 
            
        case SQRT: 
            aux.x = 300;
            aux.y = 300;
            break;
            
        case DIVISION: 
            aux.x = 450;
            aux.y = 300;
            break;
            
        case MULT: 
            aux.x = 450;
            aux.y = 400;
            break;
            
        case MINUS: 
            aux.x = 450;
            aux.y = 500;
            break;
            
        case ADD: 
            aux.x = 450;
            aux.y = 600;
            aux.h = h * 2 ;
            break;
            
        case EQUAL: 
            aux.x = 300;
            aux.y = 700;
            break;
            
        case DECIMAL_COMMA: 
            aux.x = 150;
            aux.y = 700;
            break;                      
        
        default:
            break;
        }    
        this->num_buttons[i] = aux; 
    }
}

void Cal::Draw(){
 //Por ahora dibujar solo los numeros del 0 al 9 del map num_buttons , renderizar los rectangulos
    SDL_SetRenderDrawColor(this->renderer, 255,0,0,255); 
    for(auto const&[key, val] : this->num_buttons){
        if(key >= 10){
            SDL_SetRenderDrawColor(this->renderer,0,255,0,255);
        }
        SDL_RenderFillRect(this->renderer, &val);    
    }
}

int Cal::OnClick(float x, float y){
        for(auto const& [key, val] : this->num_buttons){
            if( x >= val.x && x <= (val.x + val.w) && y >= val.y && y <= (val.y + val.h)){
                SDL_Log("Click en el boton %d", key);
                return key;
            }
        }
        return -1;
}