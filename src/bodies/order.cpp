#include <iostream>
#include <vector>
#include "../headers/box.h"
#include "../headers/order.h"


order::order()
{
    std::cout << "Welcome to the box ordering system" << std::endl;
    std::cout << "Type the number of the box that you want to order" << std::endl;
    for(int i = 0; i < 1000; i++)
    {
        std::cout << "--------------------------" << std::endl;
        std::cout << "Select Box: " << std::endl;
        std::cout << "  Box 1: 200mm x 150mm" << std::endl;
        std::cout << "  Box 2: 300mm x 170mm" << std::endl;
        std::cout << "  Box 3: 500mm x 300mm "<< std::endl;
        std::cout << "  Box 4: 100mm x 30mm" << std::endl;
        std::cout << "  Box 5: 70mm x 70mm" << std::endl;
        std::cout << "  Box 6: 140mm x 140mm" << std::endl;
        std::cout << "  Finish the order: 7" << std::endl;
        std::cout << "--------------------------" << std::endl;

        int menu;
        std::cin >> menu;
        switch (menu)
        {
        case 1:
            std::cout << "Selected Box 1" << std::endl;
            V_boxes_order.push_back(box(2, 2, 1, false));
            break;
        case 2:
            std::cout << "Selected Box 2" << std::endl;
            V_boxes_order.push_back(box(3, 2, 1, false));
            break;
        case 3:
            std::cout << "Selected Box 3" << std::endl;
            V_boxes_order.push_back(box(5, 3, 1, false));
            break;
        case 4:
            std::cout << "Selected Box 4" << std::endl;
            V_boxes_order.push_back(box(1, 3, 1, false));
            break;
        case 5:
            std::cout << "Selected Box 5" << std::endl;
            V_boxes_order.push_back(box(7, 7, 1, false));
            break;
        case 6:
            std::cout << "Selected Box 6" << std::endl;
            V_boxes_order.push_back(box(1, 2, 1, false));
            break;
        case 7:
            std::cout << "The order is finished" << std::endl;
            i = 1000;
            break;
        default:    
            std::cout << "Invalid option" << std::endl;
            break;
        }
    }
    num_boxes = V_boxes_order.size();
}

void order::show_order()
{
    std::cout << std::endl << "--------------------------" << std::endl;
    std::cout << "  Number of boxes: " << V_boxes_order.size() << std::endl;
    for (int i = 0; i < V_boxes_order.size(); i++)
    {
        std::cout << "  Box " << i + 1 << std::endl;
        V_boxes_order[i].show_box();
    }
}

int order::get_num_boxes()
{
    return num_boxes;
}

std::vector<box> order::get_V_boxes()
{
    return V_boxes_order;
}