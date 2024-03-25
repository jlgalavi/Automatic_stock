// File: shipment.h
#include "box.h"
#include "container.h"
#include <vector>

class shipment
{
    private:
        int num_containers;
        int num_boxes;
        std::vector<box> V_boxes;
        std::vector<container> V_containers;
    public:
        shipment(int nc, int nb);    
        void set_container(container c);
        void show();
        int get_num_containers();
        int get_num_boxes();
};