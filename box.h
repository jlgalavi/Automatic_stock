class box 
{
    private:

        int length_box;
        int width_box;
        int height_box;

    public:

        box(int l, int w, int h);
        int volume();
        int surface_area();
        int get_length();
        int get_width();
        int get_height();
        void show();

};