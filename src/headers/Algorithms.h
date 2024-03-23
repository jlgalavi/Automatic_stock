#include <iostream>
#include <vector>   
#include "container.h"

class Algorithms : public container
{
    public:
        container c;
        Algorithms(container c);
        void set_container(container in);
        void place_boxes();
        bool prove_object(int **objects, int w, int l, box v);
        //void order_boxes();    
};
