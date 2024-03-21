#include <ncurses.h>
#include <stdlib.h>



int main()
{
    int row = 0, col = 0; 
    char snake = 22;
    int posXFood = 10, posYFood = 200, posXsnake = 12,posYsnake = 12;
    int input;
    initscr();
    cbreak();
    noecho();
    keypad(stdscr,TRUE); /// f1 f2 etc..

    
    //CARACTERES ESPECIALES CON ACS_<NAME>
    //printw("La Ventana Tiene %d Filas y %d Columnas",row,col);
    mvaddch(posXFood,posXFood, ACS_DIAMOND); // Comida
    mvaddch(posXsnake,posYsnake,ACS_CKBOARD); // SNAKE
    
    int contadorX = 0, contadorY = 0;
    while ((input = getch()) != KEY_F(4) )
    {
        getmaxyx(stdscr,row,col);  /// obtener x & Y de la pantalla/Terminal
        mvprintw(0,0,"La Ventana Tiene %d Filas y %d Columnas",row,col);
        /// Espera entrada (caracter)
        switch(input)
        {   case KEY_LEFT:
                posYsnake -= 1; 
                break;
            case KEY_RIGHT:
                posYsnake += 1;
                break;
            case KEY_UP:
                posXsnake += 1;
                break;
            case KEY_DOWN:
                posXsnake -= 1;
                break;
        }

        mvaddch(posXsnake,posYsnake,ACS_CKBOARD); // SNAKE
    }
    
    endwin();

    /* code */
    return 0;
}
