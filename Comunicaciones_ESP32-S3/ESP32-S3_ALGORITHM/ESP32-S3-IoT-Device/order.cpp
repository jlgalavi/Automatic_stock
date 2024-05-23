#include <iostream>
#include <fstream>
#include <vector>
#include "box.h"
#include "order.h"

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
        std::cout << "  Box 1: 150mm x 120mm x 100mm" << std::endl;
        std::cout << "  Box 2: 200mm x 210mm x  70mm" << std::endl;
        std::cout << "  Box 3: 200mm x 210mm x 210mm"<< std::endl;
        std::cout << "  Box 4: 250mm x 300mm x 210mm" << std::endl;
        std::cout << "  Finish the order: 7" << std::endl;
        std::cout << "--------------------------" << std::endl;

        int menu;
        std::cin >> menu;
        switch (menu)
        {
        case 1:
            std::cout << "Selected Box 1" << std::endl;
            V_boxes_order.push_back(box(15, 12, 10, false, 'S'));
            break;
        case 2:
            std::cout << "Selected Box 2" << std::endl;
            V_boxes_order.push_back(box(20, 21, 7, false, 'M'));
            break;
        case 3:
            std::cout << "Selected Box 3" << std::endl;
            V_boxes_order.push_back(box(20, 21, 21, false, 'L'));
            break;
        case 4:
            std::cout << "Selected Box 4" << std::endl;
            V_boxes_order.push_back(box(25, 30, 21, false, 'X'));
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
order::order(int S, int M, int L, int X)
{
  for(int i = 0; i < S; i++)
  {
    V_boxes_order.push_back(box(15, 12, 10, false, 'S'));
  }
  for(int i = 0; i < M; i++)
  {
    V_boxes_order.push_back(box(20, 21, 7, false, 'M'));
  }
  for(int i = 0; i < L; i++)
  {
    V_boxes_order.push_back(box(20, 21, 21, false, 'L'));
  }
  for(int i = 0; i < X; i++)
  {
    V_boxes_order.push_back(box(25, 30, 21, false, 'X'));
  }
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