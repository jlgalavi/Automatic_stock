// Purpose: Header file for order class.
#ifndef ORDER_H
#define ORDER_H

class order : public box
{
    private:
        int num_boxes;
        std::vector<box> V_boxes_order;
    public:
        order();
        void show_order();
        int get_num_boxes();
        std::vector<box> get_V_boxes();
};

#endif