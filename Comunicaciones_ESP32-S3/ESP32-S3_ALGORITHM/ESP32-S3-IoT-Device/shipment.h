// Definicion de la clase envio que se utiliza para mostrar el envio de cajas y contenedores
// Definition of the class shipment which is used to show the shipment of boxes and containers 
#include "target.h"

#ifndef SHIPMENT_H
#define SHIPMENT_H

class shipment
{
    private:
        std::vector<box> V_boxes;
        std::vector<container> V_containers;
        std::vector<target> V_targets;
    public:
        shipment();
        shipment(std::vector<box> V, std::vector<container> C, std::vector<target> T);    
        void show_shipment();
        int get_num_containers();
        int get_num_boxes();
        void save_shipment(std::string output);
}; 

#endif