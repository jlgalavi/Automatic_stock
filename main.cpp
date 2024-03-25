#include <iostream>
#include <vector>
#include "src/headers/Algorithms.h"
#include <ctime> 

unsigned t0, t1, t2, t3;

int main()
{
    order O1;
    container C1;
    Algorithms A1(C1);
    A1.set_boxes(O1.get_V_boxes());
    A1.show_boxes();
    A1.place_boxes();
    A1.show_objects(); 
    A1.show();   
    return 0;
}
