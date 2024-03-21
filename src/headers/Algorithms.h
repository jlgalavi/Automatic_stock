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
        
};
