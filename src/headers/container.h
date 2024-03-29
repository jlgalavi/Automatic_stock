#ifndef CONTAINER_H
#define CONTAINER_H

class container
{
    protected:
        int length_container;
        int width_container;
        int height_container;
        std::vector<box> V_box;

    public:
        int **objects;
        container();
        container(int l, int w, int h);
        void add_box(box b);
        void show_container();
        int get_length();
        int get_width();
        int get_height();
        int get_num_boxes();
        std::vector<box> get_V();
        int volume();
        int get_surface_area();
        void show_objects_container();
        int add_volume_boxes();
};

#endif