// Purpose: Header file for order class.
#include <vector>
#include "box.h"

class order 
{
    private:
        int num_boxes;
        std::vector<box> V_box;
    public:
        order();
        void show();
        int get_num_boxes();
        std::vector<box> get_V_boxes();
};