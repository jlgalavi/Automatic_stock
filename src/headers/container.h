#include "box.h"
#include <vector>

class container
{
    protected:
        int length_container;
        int width_container;
        int height_container;
        int k;              // Número de cajas
        std::vector<box> V_box;

    public:
        int **objects;
        container();
        container(int l, int w, int h, int k);
        void add_box(box b);
        void show();
        int get_length();
        int get_width();
        int get_height();
        int get_k();
        std::vector<box> get_V();
        int volume();
        int surface_area();
        void show_objects();
        int add_volume_boxes();
};