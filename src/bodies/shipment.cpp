#include <iostream>
#include <vector>
#include "../headers/box.h"
#include "../headers/container.h"
#include "../headers/shipment.h"

shipment::shipment()
{
    V_boxes = {};
    V_containers = {};
}
shipment::shipment(std::vector<box> V, std::vector<container> C)
{
    V_boxes = V;
    V_containers = C;
}

void shipment::show_shipment()
{
    std::cout << "Welcome to the box shipment system" << std::endl;
    std::cout << "This is the resume of your shipment" << std::endl;
    std::cout << std::endl << "--------------------------" << std::endl;
    std::cout << "  Number of containers: " << V_containers.size() << std::endl;
    std::cout << "  Number of boxes: " << V_boxes.size() << std::endl;
    for (int i = 0; i < V_containers.size(); i++)
    {
        std::cout << "  Container " << i + 1 << std::endl;
        V_containers[i].show_container();
    }
    std::cout << "--------------------------" << std::endl;
}

int shipment::get_num_containers()
{
    return V_containers.size();
}

int shipment::get_num_boxes()
{
    return V_boxes.size();
}