#include <iostream>
#include <vector>
#include "../headers/container.h"

// Constructor del contenedor
container::container()
{
    length_container = 0;
    width_container = 0;
    height_container = 0;
    num_boxes = 0;
    objects = new int *[width_container];
    for (int i = 0; i < width_container; i++)
    {
        objects[i] = new int[length_container];
        for (int j = 0; j < length_container; j++)
        {
            objects[i][j] = 0;
        }
    }
}
container::container(int l, int w, int h)
{
    length_container = l;
    width_container = w;
    height_container = h;
    objects = new int *[w];
    for (int i = 0; i < w; i++)
    {
        objects[i] = new int[l];
        for (int j = 0; j < l; j++)
        {
            objects[i][j] = 0;
        }
    }
}
// Añadir caja al contenedor
void container::add_box(box b)
{
    V_box.push_back(b);
    num_boxes++;
}
// Mostrar las cajas del contenedor
void container::show()
{
    std::cout << std::endl << "--------------------------" << std::endl;
    std::cout << "  Length: " << length_container << std::endl;
    std::cout << "  Width: " << width_container << std::endl;
    std::cout << "  Height: " << height_container << std::endl;
    std::cout << "  Number of boxes: " << num_boxes << std::endl;
    for (int i = 0; i < num_boxes; i++)
    {
        bool placed = V_box[i].get_placed();
        if(!placed)
        {
        std::cout << "  Box " << i + 1 << std::endl;
        V_box[i].show();
        }
    }
    std::cout << "  Volume of left boxes: " << add_volume_boxes() << std::endl;
    std::cout << "--------------------------" << std::endl << std::endl;
}
// Obtener la longitud del contenedor
int container::get_length()
{
    return length_container;
}
// Obtener el ancho del contenedor
int container::get_width()
{
    return width_container;
}
// Obtener la altura del contenedor
int container::get_height()
{
    return height_container;
}
// Obtener el número de cajas
int container::get_num_boxes()
{
    return num_boxes;
}
// Calcular el volumen del contenedor
int container::volume()
{
    return length_container * width_container * height_container;
}
// Calcular el área superficial del contenedor
int container::surface_area()
{
    return length_container * width_container;
}

void container::show_objects()
{
    for (int i = 0; i < width_container; i++)
    {
        for (int j = 0; j < length_container; j++)
        {
            std::cout << objects[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

std::vector<box> container::get_V()
{
    return V_box;
}

int container::add_volume_boxes()
{
    int volume = 0;
    for (int i = 0; i < num_boxes; i++)
    {
        if(!V_box[i].get_placed())
        {
            volume += V_box[i].get_volume();
        }
    }
    return volume;
}
