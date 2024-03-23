#include <iostream>
#include <vector>
#include "src/headers/Algorithms.h"


int main()
{
    container c(11, 11, 1, 8); // Hay uno de más en el ancho y en el largo para que el algoritmo actual funcione, a falta de revisar el algoritmo.
    box b1(2, 3, 1, false);
    box b2(1, 4, 1, false);
    box b3(3, 3, 1, false);
    box b4(2, 2, 1, false);
    box b5(1, 3, 1, false);
    box b6(3, 4, 1, false);
    box b7(4, 4, 1, false);
    box b8(2, 5, 1, false);
    Algorithms a(c);
    c.add_box(b1);
    c.add_box(b2);
    c.add_box(b3);
    c.add_box(b4);
    c.add_box(b5);
    c.add_box(b6);
    c.add_box(b7);
    c.add_box(b8);
    a.set_container(c);
    a.place_boxes();
    a.show_objects();
    a.show();
    return 0;
}
