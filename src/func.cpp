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

    /*this->ttf = {
        "0","1","2","3","4","5","6","7","8","9",
        "CE","OFF","√","/","*","-","+","=","."
    };
    */

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

    SDL_SetRenderDrawColor(this->renderer, 255,255,255,255); 
    for(auto const&[key, val] : this->num_buttons){
        SDL_RenderFillRect(this->renderer, &val);    
    }
    SDL_SetRenderDrawColor(this->renderer, 255,0,0,255);
    for(auto const&[key, val] : this->num_buttons){
        SDL_RenderRect(this->renderer,&val);
    }
}

int Cal::OnClick(float x, float y){
        for(auto const& [key, val] : this->num_buttons){
            if( x >= val.x && x <= (val.x + val.w) && y >= val.y && y <= (val.y + val.h)){
                return key;
            }
        }
        return -1;
}


void Cal::DoButton(int n){
    switch (n)
        {
        case 0:
            SDL_Log("This is action of number 0");
            
            break;
        case 1: 
            SDL_Log("This is action of number 1");
            break;
        case 2: 
            SDL_Log("This is action of number 2");
            break;
        case 3: 
            SDL_Log("This is action of number 3");
            break;
        case 4: 
            SDL_Log("This is action of number 4");
            break;
        case 5: 
            SDL_Log("This is action of number 5");
            break;
        case 6: 
            SDL_Log("This is action of number 6");
            break;
        case 7: 
            SDL_Log("This is action of number 7");
            break;     
        case 8: 
            SDL_Log("This is action of number 8");
            break;    
        case 9: 
            SDL_Log("This is action of number 9");
            break;
        case CE: //CE button
            SDL_Log("This is action of CE");
            break;
        case OFF: 
            SDL_Log("This is action of OFF");
            break; 
        case SQRT: 
            SDL_Log("This is action of the square root");
            break;
        case DIVISION: 
            SDL_Log("This is action of division");
            break;
        case MULT: 
            SDL_Log("This is action of multiplication");
            break;
        case MINUS: 
            SDL_Log("This is action of substract");
            break;
        case ADD: 
            SDL_Log("This is action of addition");
            break;
        case EQUAL: 
            SDL_Log("This is action of equal");
            break;
        case DECIMAL_COMMA: 
            SDL_Log("This is action of decimal comma");
            break;                      
        default:
            break;
        }    


}