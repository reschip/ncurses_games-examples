#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>

struct Board
{
    int limites[4];
    int position[2];
};

struct Snake
{
    int position[2];
};


int main()
{
    int row = 0, col = 0; 
    char snake = 22;
    int posXFood = 10, posYFood = 200, posXsnake = 12,posYsnake = 12;
    int input;

    struct Board Bd = {
        {40,20,40,20},
        {0,0}
    };

    struct Snake Sk = {
        {30,20}
    };

    initscr(); //iniciar ncurses
    cbreak(); //no permitir teclas ctrl+
    noecho(); //no mostrar teclas en la pantalla
    keypad(stdscr,TRUE); /// f1 f2 etc..
    curs_set(0); // ocultar el cursor
    
    //CARACTERES ESPECIALES CON ACS_<NAME>
    //printw("La Ventana Tiene %d Filas y %d Columnas",row,col);
    mvaddch(posXFood,posXFood, ACS_DARROW); // Comida
    mvaddch(posXsnake,posYsnake,ACS_CKBOARD); // SNAKE

    int boardPosX = 0;

    for (int i = 0; i < 120; i++)
    {
        if(i < 40){
            Bd.position[0] += 1;
        }
        if(i < 60 && i >= 40){
            Bd.position[1] += 1;
        }
        if(i < 100 && i >= 60){
            Bd.position[0] -= 1;
        }
        if(i < 120 && i >= 100){
            Bd.position[1] -= 1;
        }
        //MVADDCH(Y,X)
        mvaddch(Bd.position[1] + 4,Bd.position[0] + 10, ACS_BOARD); // BOARD
    }
    refresh();
    move(0,0);
    nodelay(stdscr,TRUE); // No bloquear programa para esperar una tecla
  
    int positionSelect = 1; // 0 1 2 3
    int colaLen = 0, contadorLen = 0;
    //colalen Empieza en 0

    int anteriorX, anteriorY;
    int puntaje = 0;
    while ((input = getch()) != KEY_F(4) )
    {
        getmaxyx(stdscr,row,col);  /// obtener x & Y de la pantalla/Terminal
        mvprintw(0,0,"La Ventana Tiene %d Filas y %d Columnas",row,col);
        mvprintw(1,0,"Puntaje: %d",puntaje);
        
        /// Espera entrada (caracter)
        //BUG DE ENTRADAS EJ: PARECE QUE _ guarda en memoria las entradas
        
        if(contadorLen == colaLen){
            mvprintw(anteriorY ,anteriorX ," ");
            anteriorX = Sk.position[0];
            anteriorY = Sk.position[1];
            contadorLen = 0;
        }

        switch(input)
        {   case KEY_LEFT:
                if(positionSelect != 1)
                    positionSelect = 0;
                break;
            case KEY_RIGHT:
                if(positionSelect != 0)
                    positionSelect = 1;
                break;
            case KEY_UP:
                if(positionSelect != 3)
                    positionSelect = 2;
                break;
            case KEY_DOWN:
                if(positionSelect != 2)
                    positionSelect = 3;
                break;
        }
        contadorLen += 1;


        

        if (positionSelect == 1) // derecha
        {
            Sk.position[0]+= 1;

        }    
        
        if (positionSelect == 2) //arriba
        {
            Sk.position[1]-= 1;
            
        }
            

        if (positionSelect == 0) //izquierda
        {
            Sk.position[0]-= 1;
            
        }
            

        if (positionSelect == 3) //abajo
        {
            Sk.position[1]+= 1;
            
        }
        

        mvaddch(Sk.position[1],Sk.position[0],ACS_TTEE); //snake
        refresh();
        usleep(200000);
    }
    
    
    endwin();

    /* code */
    return 0;
}
