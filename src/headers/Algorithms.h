// File: Algorithms.h
#include "container.h"
#include "order.h"
#include "shipment.h"
#include <vector>

class Algorithms : public container
{
    public:
        std::vector<box> V_boxes;
        container c;
        std::vector<container> V_containers;
        Algorithms(container c);
        void set_boxes(std::vector<box> V);
        void show_boxes();
        void add_container(container in);
        void place_boxes();
        bool prove_object(int **objects, int w, int l, box v, bool inverted = false);
        void order_boxes();    
};
