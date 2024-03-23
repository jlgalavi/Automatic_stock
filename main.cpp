#include <iostream>
#include <vector>
#include "src/headers/Algorithms.h"


int main()
{
    container c(10, 10, 1, 8);
    box b1(2, 6, 1, false);
    box b2(4, 4, 1, false);
    box b3(2, 9, 1, false);
    box b4(3, 6, 1, false);
    box b5(2, 2, 1, false);
    box b6(4, 3, 1, false);
    box b7(1, 4, 1, false);
    box b8(4, 7, 1, false);
    Algorithms a(c);
    Algorithms b(c);
    c.add_box(b1);
    c.add_box(b2);
    c.add_box(b3);
    c.add_box(b4);
    c.add_box(b5);
    c.add_box(b6);
    c.add_box(b7);
    c.add_box(b8);
    a.set_container(c);
    b.set_container(c);
    //a.order_boxes();
    a.place_boxes();
    a.show_objects();
    a.show();
    b.place_boxes();
    b.show_objects();
    b.show();
    return 0;
}
