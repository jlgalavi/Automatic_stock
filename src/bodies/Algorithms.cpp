#include <iostream>
#include <vector>
#include "../headers/box.h"
#include "../headers/container.h"
#include "../headers/shipment.h"
#include "../headers/order.h"   
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
    - Añadir altura a las cajas y contenedores.
    (Para ello reconfigurar todos los bucles con el siguiente orden: i = height, j = width, l = length)
 */
Algorithms::Algorithms(int nb, int l, int w, int h, std::vector<box> V)
{
    length_container_in_use = l;
    width_container_in_use = w;
    height_container_in_use = h;
    objects_in_use = new int*[width_container_in_use];
    for (int i = 0; i < width_container_in_use; i++)
    {
        objects_in_use[i] = new int[length_container_in_use];
    }
    for (int i = 0; i < width_container_in_use; i++)
    {
        for (int j = 0; j < length_container_in_use; j++)
        {
            objects_in_use[i][j] = 0;
        }
    }
    V_containers_in_use.reserve(nb);
    V_boxes_in_use = V;
}

void Algorithms::show_boxes()
{
    for (int i = 0; i < V_boxes_in_use.size(); i++)
    {
        std::cout << "Box " << i + 1 << std::endl;
        V_boxes_in_use[i].show_box();
    }
}

void Algorithms::add_container(container in)
{
    V_containers_in_use.push_back(in);
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
    V_boxes_in_use = V;
}

void Algorithms::order_boxes()
{
    for (int i = 1; i < V_boxes_in_use.size(); i++)
    {
        int j = i - 1;
        int n = V_boxes_in_use[i].get_volume();        
        while (j >= 0  && V_boxes_in_use[j].get_volume() < n)
        {
            box temp = V_boxes_in_use[j];
            V_boxes_in_use[j] = V_boxes_in_use[j + 1];
            V_boxes_in_use[j + 1] = temp;
            j--;
        }
    }
}

void Algorithms::show_objects()
{
    for (int i = 0; i < width_container_in_use; i++)
    {
        for (int j = 0; j < length_container_in_use; j++)
        {
            std::cout << objects_in_use[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void Algorithms::show_containers()
{
    for (int i = 0; i < V_containers_in_use.size(); i++)
    {
        std::cout << "Container " << i + 1 << std::endl;
        V_containers_in_use[i].show_container();
    }
}

void Algorithms::reset_objects()
{
    for (int i = 0; i < width_container_in_use; i++)
    {
        for (int j = 0; j < length_container_in_use; j++)
        {
            objects_in_use[i][j] = 0;
        }
    }
}

void Algorithms::place_boxes()
{    
    int n_box = 1; 
    order_boxes();
    bool all_boxes_placed = false;
    while(!all_boxes_placed)
    { 
        for (int i = 0; i < V_boxes_in_use.size(); i++)
        {
            if(!V_boxes_in_use[i].get_placed())
            {
                for (int w = 0; w < width_container_in_use; w++)
                {
                    for (int l = 0; l < length_container_in_use; l++)
                    {
                        if (V_boxes_in_use[i].get_length() <= length_container_in_use - l 
                        && V_boxes_in_use[i].get_width() <= width_container_in_use - w 
                        && prove_object(objects_in_use, w, l, V_boxes_in_use[i]))
                        {
                            for (int m = 0; m < V_boxes_in_use[i].get_length(); m++)
                            {
                                for (int n = 0; n < V_boxes_in_use[i].get_width(); n++)
                                {
                                    objects_in_use[w + n][l + m] = n_box;
                                }
                            }
                            w = width_container_in_use;
                            l = length_container_in_use;
                            n_box++;
                            V_boxes_in_use[i].set_placed(true);
                        }
                        else if (V_boxes_in_use[i].get_width() <= length_container_in_use - l 
                        && V_boxes_in_use[i].get_length() <= width_container_in_use - w 
                        && prove_object(objects_in_use,  w, l, V_boxes_in_use[i], true))
                        {
                            for (int m = 0; m < V_boxes_in_use[i].get_width(); m++)
                            {
                                for (int n = 0; n < V_boxes_in_use[i].get_length(); n++)
                                {
                                    objects_in_use[w + n][l + m] = n_box;
                                }
                            }
                            w = width_container_in_use;
                            l = length_container_in_use;
                            n_box++;
                            V_boxes_in_use[i].set_placed(true);
                        }
                    }
                }
            } 
        }
        container C1(width_container_in_use, length_container_in_use, height_container_in_use);
        for (int i = 0; i < width_container_in_use; i++)
        {
            for (int j = 0; j < length_container_in_use; j++)
            {
                C1.objects[i][j] = objects_in_use[i][j];
            }
        }
        for(int i = 0; i < V_boxes_in_use.size(); i++)
        {
            if(V_boxes_in_use[i].get_placed())
            {
                C1.add_box(V_boxes_in_use[i]);
            }
        }
        
        add_container(C1);
        reset_objects();
        
        for(int i = 0; i < V_boxes_in_use.size(); i++)
        {
            if(V_boxes_in_use[i].get_placed())
            {   
                V_boxes_in_use.erase(V_boxes_in_use.begin() + i);
                i--;
            }
        }
        std::cout << "Number of left boxes: " << V_boxes_in_use.size() << std::endl;
        if(V_boxes_in_use.empty())
        {
            all_boxes_placed = true;
        }
    }
}
