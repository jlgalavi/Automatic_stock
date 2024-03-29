// File: shipment.h

#ifndef SHIPMENT_H
#define SHIPMENT_H

class shipment 
{
    private:
        std::vector<box> V_boxes;
        std::vector<container> V_containers;
    public:
        shipment();
        shipment(std::vector<box> V, std::vector<container> C);    
        void show_shipment();
        int get_num_containers();
        int get_num_boxes();
}; 

#endif