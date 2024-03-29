#include <iostream>
#include "../headers/box.h"
// Constructor de la caja
box::box(int l, int w, int h, bool p)
{
    length_box = l;
    width_box = w;
    height_box = h;
    placed = p;
    volume_box = l * w * h;
}
// Obtener la longitud de la caja
int box::get_length()
{
    return length_box;
}
// Obtener el ancho de la caja
int box::get_width()
{
    return width_box;
}
// Obtener la altura de la caja
int box::get_height()
{
    return height_box;
}
// Calcular el volumen de la caja (largo * ancho * altura)
int box::get_volume()
{
    return volume_box;
}
// Calcular el área superficial de la caja (length * width)
int box::surface_area()
{
    return length_box * width_box;
}

void box::show_box()
{
    std::cout << "  Length: " << length_box << std::endl;
    std::cout << "  Width: " << width_box << std::endl;
    std::cout << "  Height: " << height_box << std::endl;
    std::cout << "  Volume: " << volume_box << std::endl;
}

void box::set_placed(bool p)
{
    placed = p;
}

bool box::get_placed()
{
    return placed;
}
