#include <iostream>
#include <vector>
#include "../headers/shipment.h"

shipment::shipment(int nc, int nb)
{
    num_containers = nc;
    num_boxes = nb;
}

void shipment::set_container(container c)
{
    V_containers.push_back(c);
}

void shipment::show()
{
    std::cout << std::endl << "--------------------------" << std::endl;
    std::cout << "  Number of containers: " << num_containers << std::endl;
    std::cout << "  Number of boxes: " << num_boxes << std::endl;
    for (int i = 0; i < num_containers; i++)
    {
        std::cout << "  Container " << i + 1 << std::endl;
        V_containers[i].show();
    }
    std::cout << "--------------------------" << std::endl;
}

int shipment::get_num_containers()
{
    return num_containers;
}

int shipment::get_num_boxes()
{
    return num_boxes;
}