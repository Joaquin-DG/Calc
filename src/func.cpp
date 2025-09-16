#include "myLib.h"


/*
    Funciones de operaciones de la calculadora
    ADD
    SUBSTRACTION
    MULTIPLICATION
    DIVISION
    SQRT

*/

double Add(double x, double y){
    return x+y;
}

double Substract(double x, double y){
    return x-y;
}

double Mult(double x, double y){
    return x*y;
}
double Div(double x, double y){
    return x/y;
}
double Sqrt(double x, double y){
    return sqrt(x);
}



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
void Cal::SetAll(){
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

    //Create the map of functions to make operations
    this->operations = {
        {'+', Add},
        {'-', Substract},
        {'*', Mult},
        {'/', Div},
        {'√', Sqrt}
    };
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

int Cal::OnClick(float &x, float &y){
        for(auto const& [key, val] : this->num_buttons){
            if( x >= val.x && x <= (val.x + val.w) && y >= val.y && y <= (val.y + val.h)){
                return key;
            }
        }
        return -1;
}

bool Cal::LastnotOperator(){
    if(!num_string.empty() && num_string.back() >= '0' && num_string.back() <= '9'){
        return true;
    }
    else{
        return false;
    }
}


void Cal::DoButton(int& n){
    switch (n)
        {
        case 0:
            num_string.append("0");
            break;
        case 1: 
            num_string.append("1");
            break;
        case 2: 
            num_string.append("2");
            break;
        case 3: 
            num_string.append("3");
            break;
        case 4: 
            num_string.append("4");
            break;
        case 5: 
            num_string.append("5");
            break;
        case 6: 
            num_string.append("6");
            break;
        case 7: 
            num_string.append("7");
            break;     
        case 8: 
            num_string.append("8");
            break;    
        case 9: 
            num_string.append("9");
            break;
        case CE: //CE button
            num_string.clear();
            display_string.clear();
            break;
        case OFF: 
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Off button pressed, exiting...");
            exit(0);
            break; 


            //Now we should check if the last char is not an operator in the string
        case SQRT: 
                num_string.append("√");    
            break;
        case DIVISION:
            if(LastnotOperator()){ //if true i can place next a operator
                num_string.append("/");    
            }else{ 
                SDL_Log("Syntax Error: Cannot place division here, rewrite the expression.");
                num_string.clear();
                display_string.clear();                
            }
            break;
        case MULT: 
            if(LastnotOperator()){ //if true i can place next a operator
                num_string.append("*");
            }else{ 
                SDL_Log("Syntax Error: Cannot place multiplication here, rewrite the expression.");
                num_string.clear();
                display_string.clear();                
            }
            break;
        case MINUS: 
            if(this->num_string.size() == 0){ //This makes sure that the negative char '-' is appended if it's the first element, after that a negatvie number is just substracting
                num_string.append("-");
                break;
            }
            if(LastnotOperator()){ 
                num_string.append("-");
            }else{ 
                SDL_Log("Syntax Error: Cannot place subtraction here, rewrite the expression.");
                num_string.clear();
                display_string.clear();                
            }
            break;
        case ADD: 
            if(LastnotOperator()){ //if true i can place next a operator
                num_string.append("+");
            }else{ 
                SDL_Log("Syntax Error: Cannot place addition here, rewrite the expression.");
                num_string.clear();
                display_string.clear();                
            }
            break;
        case EQUAL:
            if(!LastnotOperator()){
                SDL_Log("Last element must be a number");
                num_string.clear();
                break;
            }
            SDL_Log("Equal");
            //Here we should evaluate the expression in num_string    
            this->Calculate();



            break;
        case DECIMAL_COMMA: //Current bug: You can place 215.21.21.2 for example and doesnt throw error because it evaluates only the last element of the string. Prob won't fix it
            if(LastnotOperator()){ //if true i can place next a operator
                num_string.append(".");
            }else{ 
                SDL_Log("Syntax Error: Cannot place decimal point here, rewrite the expression.");
                num_string.clear();
                display_string.clear();
            }
            break;                      
        default:
            break;
        }    

    }

//Function to calculate the whole thing, might dont work 
void Cal::Calculate() {
    this->ss.clear();
    this->ss.str(num_string);


    // Clear the stringstream for future use
    this->ss.clear();
    this->ss.str("");
}