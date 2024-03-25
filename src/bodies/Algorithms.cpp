#include <iostream>
#include <vector>   
#include "../headers/Algorithms.h"

/*
Variables:
    - l: longitud de la caja
    - w: ancho de la caja
    //- h: altura de la caja 
    - k: número de cajas
    - vx: posición en x de la caja
    - vy: posición en y de la cajaq
    //- vz: posición en z de la caja
    - V: vector de cajas

Funciones:
        
        
*/

/*
 * Tareas:
    - Comentar los ficheros
 * Problemas a resolver:  
    - vincular shipments con algorithms y guardar container.
    - Gestionar contenedores, si quedan cajas sin colocarse, se crea un nuevo contenedor para almacenar el resto.
    - Añadir altura a las cajas
 */
Algorithms::Algorithms(container c)
{
    this->c = c;
    length_container = 10;
    width_container = 10;
    height_container = 1;
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

void Algorithms::show_boxes()
{
    for (int i = 0; i < V_box.size(); i++)
    {
        std::cout << "Box " << i + 1 << std::endl;
        V_box[i].show();
    }
}

void Algorithms::add_container(container in)
{
    V_containers.push_back(in);
    std::cout << std::endl << "--------------------------" << std::endl;
    std::cout << "  Container added" << std::endl;
    std::cout << "  Length: " << in.get_length() << std::endl;
    std::cout << "  Width: " << in.get_width() << std::endl; 
    std::cout << "  Height: " << in.get_height() << std::endl;   
    std::cout << "--------------------------" << std::endl << std::endl;
}

bool Algorithms::prove_object(int **objects, int w, int l, box v, bool inverted)
{
    int width, length;
    if(inverted)
    {
        width = w + v.get_length();
        length = l + v.get_width();
    } else
    {
        width = w + v.get_width();
        length = l + v.get_length();
    }
    for (int i = w; i < width; i++)
    {
        for (int j = l; j < length; j++)
        {
            if(objects[i][j] != 0)
            {
                return false;
            }
        }
    }
    return true;
}

void Algorithms::set_boxes(std::vector<box> V)
{
    V_box = V;
}

void Algorithms::order_boxes()
{
    for (int i = 1; i < V_box.size(); i++)
    {
        int j = i - 1;
        int n = V_box[i].get_volume();        
        while (j >= 0  && V_box[j].get_volume() < n)
        {
            box temp = V_box[j];
            V_box[j] = V_box[j + 1];
            V_box[j + 1] = temp;
            j--;
        }
    }
}

void Algorithms::place_boxes()
{    
int n_box = 1; 
order_boxes();

for (int i = 0; i < V_box.size(); i++)
    {
        for (int w = 0; w < width_container; w++)
        {
            for (int l = 0; l < length_container; l++)
            {
                if (V_box[i].get_length() <= length_container - l && V_box[i].get_width() <= width_container - w && prove_object(objects, w, l, V_box[i]))
                {
                    for (int m = 0; m < V_box[i].get_length(); m++)
                    {
                        for (int n = 0; n < V_box[i].get_width(); n++)
                        {
                            objects[w + n][l + m] = n_box;
                        }
                    }
                    w = width_container;
                    l = length_container;
                    n_box++;
                    V_box[i].set_placed(true);
                }
                else if (V_box[i].get_width() <= length_container - l && V_box[i].get_length() <= width_container - w && prove_object(objects,  w, l, V_box[i], true))
                {
                    for (int m = 0; m < V_box[i].get_width(); m++)
                    {
                        for (int n = 0; n < V_box[i].get_length(); n++)
                        {
                            objects[w + n][l + m] = n_box;
                        }
                    }
                    w = width_container;
                    l = length_container;
                    n_box++;
                    V_box[i].set_placed(true);
                }
            }
        }
    }
}
