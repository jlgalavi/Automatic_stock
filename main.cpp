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
    int menu;
    for(;;)
    {
        std::cout << "Welcome to the NN system" << std::endl;
        std::cout << "Select an option" << std::endl;
        std::cout << "1. Order boxes" << std::endl;
        std::cout << "2. Exit" << std::endl;
        std::cin >> menu;
        if(menu == 1)
        {
            order O1;
            Algorithms A1(O1.get_num_boxes(), LENGTH, WIDTH, HEIGHT, O1.get_V_boxes());
            A1.set_boxes(O1.get_V_boxes());
            A1.place_boxes();
            shipment S1(O1.get_V_boxes(), A1.V_containers_in_use);   
            S1.show_shipment();
        }
        else if(menu == 2)
        {
            std::cout << "The program is finished" << std::endl;
            std::cout << "Have a nice day" << std::endl;
            break;
        }
        else
        {
            std::cout << "Invalid option" << std::endl;
        }
        
    }
    return 0;
}
