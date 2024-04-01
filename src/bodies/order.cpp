#include <iostream>
#include <fstream>
#include <vector>
#include "../headers/box.h"
#include "../headers/order.h"

// Constructor de la orden, donde generamos el menú para seleccionar las cajas
// Order constructor, where we generate the menu to select the boxes
order::order()
{
    std::cout << "Welcome to the box ordering system" << std::endl;
    std::cout << "Type the number of the box that you want to order" << std::endl;
    for(int i = 0; i < 1000; i++)
    {
        std::cout << "--------------------------" << std::endl;
        std::cout << "Select Box: " << std::endl;
        std::cout << "  Box 1: 200mm x 150mm x 200mm" << std::endl;
        std::cout << "  Box 2: 300mm x 170mm x 300mm" << std::endl;
        std::cout << "  Box 3: 500mm x 300mm x 100mm"<< std::endl;
        std::cout << "  Box 4: 100mm x 30mm x 20mm" << std::endl;
        std::cout << "  Box 5: 70mm x 70mm x 30mm" << std::endl;
        std::cout << "  Box 6: 140mm x 140mm x 100mm" << std::endl;
        std::cout << "  Finish the order: 7" << std::endl;
        std::cout << "--------------------------" << std::endl;

        int menu;
        std::cin >> menu;
        switch (menu)
        {
        case 1:
            std::cout << "Selected Box 1" << std::endl;
            V_boxes_order.push_back(box(2, 2, 2, false, 1));
            break;
        case 2:
            std::cout << "Selected Box 2" << std::endl;
            V_boxes_order.push_back(box(3, 2, 3, false, 2));
            break;
        case 3:
            std::cout << "Selected Box 3" << std::endl;
            V_boxes_order.push_back(box(5, 3, 1, false, 3));
            break;
        case 4:
            std::cout << "Selected Box 4" << std::endl;
            V_boxes_order.push_back(box(1, 3, 2, false, 4));
            break;
        case 5:
            std::cout << "Selected Box 5" << std::endl;
            V_boxes_order.push_back(box(7, 7, 3, false, 5));
            break;
        case 6:
            std::cout << "Selected Box 6" << std::endl;
            V_boxes_order.push_back(box(1, 2, 1, false, 6));
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
// Mostrar la orden
// Show the order
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
// Obtener el número de cajas
// Get the number of boxes
int order::get_num_boxes()
{
    return num_boxes;
}
// Obtener el vector que contiene las cajas
// Get the vector that contains the boxes
std::vector<box> order::get_V_boxes()
{
    return V_boxes_order;
}
// Guardar la orden en un archivo
// Save the order in a file
void order::save_order()
{
    std::ofstream file("D:\\repos\\Automatic_stock\\filesTXT\\order.txt", std::ios::app);
    file << std::endl << "--------------------------" << std::endl;
    file << "  Number of boxes: " << V_boxes_order.size() << std::endl;
    for (int i = 0; i < V_boxes_order.size(); i++)
    {
        file << "  Box " << i + 1 << std::endl;
        V_boxes_order[i].save_box(file);
    }
}