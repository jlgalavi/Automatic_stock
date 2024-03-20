#include "box.h"
#include <vector>

class container
{
    private:
        int length_container;
        int width_container;
        int height_container;
        int k;              // Número de cajas
        int **objects;
        std::vector<box> V;

    public:
        container(int l, int w, int h, int k);
        void add_box(box b);
        void show();
        int get_length();
        int get_width();
        int get_height();
        int get_k();
        int volume();
        int surface_area();
        void place_boxes();
        void show_objects();
};