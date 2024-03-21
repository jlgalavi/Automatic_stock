#include <iostream>
#include <vector>
#include "Algorithms.h"


int main()
{
    container c(10, 10, 1, 4);
    box b1(2, 2, 1);
    box b2(3, 3, 1);
    box b3(4, 4, 1);
    box b4(5, 5, 1);
    Algorithms a(c);
    c.add_box(b1);
    c.add_box(b2);
    c.add_box(b3);
    c.add_box(b4);
    a.set_container(c);
    a.place_boxes();
    a.show();
    a.show_objects();
    return 0;
}
