// Purpose: Define the box class, which represents a box with a length, width, height, and volume.
#pragma once

class box 
{
    private:

        int length_box;
        int width_box;
        int height_box;
        int volume_box;
        bool placed;

    public:

        box(int l, int w, int h, bool p);
        int volume();
        int surface_area();
        int get_length();
        int get_width();
        int get_height();
        int get_volume();
        void show();
        void set_placed(bool p);
        bool get_placed();
};