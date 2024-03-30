#include <iostream>
#include <vector>
#include "src/headers/Algorithms.h"
#include "src/headers/order.h"
#include "src/headers/shipment.h"
#include "src/headers/box.h"
#include "src/headers/container.h"
#include <ctime> 

#define HEIGHT 5
#define WIDTH 10
#define LENGTH 10

int main()
{
    order O1;
    Algorithms A1(O1.get_num_boxes(), LENGTH, WIDTH, HEIGHT, O1.get_V_boxes());
    A1.set_boxes(O1.get_V_boxes());
    A1.show_boxes();
    A1.place_boxes();
    //A1.show_containers(); Compare this snippet from src/headers/shipment.h:
    shipment S1(O1.get_V_boxes(), A1.V_containers_in_use);   
    S1.show_shipment();
    return 0;
}
