#include <iostream>
#include <vector>
#include "container.h"

// Constructor del contenedor
container::container(int l, int w, int h, int k)
{
    length_container = l;
    width_container = w;
    height_container = h;
    this->k = k;
    objects = new int *[w];
    for (int i = 0; i < w; i++)
    {
        objects[i] = new int[l];
        for (int j = 0; j < l; j++)
        {
            objects[i][j] = 0;
        }
    }
    V.reserve(k);
}
// Añadir caja al contenedor
void container::add_box(box b)
{
    V.push_back(b);
}
// Mostrar las cajas del contenedor
void container::show()
{
    std::cout << "Length: " << length_container << std::endl;
    std::cout << "Width: " << width_container << std::endl;
    std::cout << "Height: " << height_container << std::endl;
    std::cout << "Number of boxes: " << k << std::endl;
    for (int i = 0; i < k; i++)
    {
        std::cout << "Box " << i + 1 << std::endl;
        V[i].show();
    }
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
int container::get_k()
{
    return k;
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

void container::place_boxes()
{    
int n_box = 1;
for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < width_container; j++)
        {
            for (int l = 0; l < length_container; l++)
            {
                if (V[i].get_length() <= length_container - l && V[i].get_width() <= width_container - j && objects[j][l] == 0)
                {
                    for (int m = 0; m < V[i].get_length(); m++)
                    {
                        for (int n = 0; n < V[i].get_width(); n++)
                        {
                            objects[j + n][l + m] = n_box;
                        }
                    }
                    l = length_container;
                    j = width_container;
                    n_box++;
                }
                else if (V[i].get_width() <= length_container - l && V[i].get_length() <= width_container - j && objects[j][l] == 0)
                {
                    for (int m = 0; m < V[i].get_width(); m++)
                    {
                        for (int n = 0; n < V[i].get_length(); n++)
                        {
                            objects[j + n][l + m] = n_box;
                        }
                    }
                    l = length_container;
                    j = width_container;
                    n_box++;
                }
            }
        }
    }
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