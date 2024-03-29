// File: Algorithms.h

#include "box.h"
#include "container.h"

#ifndef ALGORITHMS_H
#define ALGORITHMS_H

class Algorithms 
{
    public:
        std::vector<box> V_boxes_in_use;
        std::vector<container> V_containers_in_use;
        int length_container_in_use;
        int width_container_in_use;
        int height_container_in_use;
        int **objects_in_use;
        Algorithms(int nb, int l, int w, int h, std::vector<box> V);
        void set_boxes(std::vector<box> V);
        void show_boxes();
        void add_container(container in);
        void place_boxes();
        bool prove_object(int **objects, int w, int l, box v, bool inverted = false);
        void order_boxes();    
};

#endif