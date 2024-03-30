// Purpose: Define the box class, which represents a box with a length, width, height, and volume.
#ifndef BOX_H
#define BOX_H

class box 
{
    protected:

        int length_box;
        int width_box;
        int height_box;
        int volume_box;
        bool placed;

    public:

        box() : length_box(0), width_box(0), height_box(0), volume_box(0), placed(false) {}
        box(int l, int w, int h, bool p);
        int surface_area();
        int get_length();
        int get_width();
        int get_height();
        int get_volume();
        void show_box();
        void set_placed(bool p);
        bool get_placed();
};

#endif