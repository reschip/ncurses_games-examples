#include <ncurses.h>

int main() {
    // Inicializar ncurses
    initscr();
    start_color();

    // Definir pares de colores (texto, fondo)
    init_pair(1, COLOR_RED, COLOR_GREEN);  // Ejemplo: texto rojo sobre fondo verde

    // Aplicar el par de colores a la ventana estándar
    attron(COLOR_PAIR(1));

    // Imprimir texto con el nuevo color
    printw("¡Hola, mundo!");

    // Restaurar colores predeterminados
    attroff(COLOR_PAIR(1));

    // Refrescar la pantalla para que se muestren los cambios
    refresh();

    // Esperar a que el usuario presione una tecla antes de salir
    getch();

    // Terminar ncurses
    endwin();

    return 0;
}
