#include <iostream>
#include <vector>
#include "src/headers/Algorithms.h"
#include <ctime> 

unsigned t0, t1, t2, t3;

int main()
{
    container c(10, 10, 1, 8); 
    box b1(2, 4, 1, false);
    box b2(1, 4, 1, false);
    box b3(3, 1, 1, false);
    box b4(6, 2, 1, false);
    box b5(3, 7, 1, false);
    box b6(5, 3, 1, false);
    box b7(4, 2, 1, false);
    box b8(2, 5, 1, false);
    box b9(4, 3, 1, false);
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
    c.add_box(b9);
    a.set_container(c);
    b.set_container(c);
    a.place_boxes();
    a.show_objects();
    a.show();
    return 0;
}
