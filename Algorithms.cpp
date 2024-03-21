#include <iostream>
#include <vector>   
#include "Algorithms.h"

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

    - Colocar cajas en contenedor:

        Obtenemos vector de cajas
        Comprobamos que la caja que queremos colocar no sobrepase el ancho ni el largo del contenedor
        Si la caja cabe, la colocamos en el contenedor
        Si la caja no cabe, la rotamos y volvemos a comprobar si cabe
        Si la caja no cabe en ninguna posición, pasamos a la siguiente caja
        Si ninguna caja cabe, pasaremos a la siguiente fila
        Para recorrer
            - Recorremos siempre en horizontal
            - Cuando sobrepasemos la horizontal, bajamos una fila y volvemos a recorrer en horizontal.
        
        void container::place_boxes()
        {
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
                                    objects[j + n][l + m] = 1;
                                }
                            }
                            break;
                        }
                        else if (V[i].get_width() <= length_container - l && V[i].get_length() <= width_container - j && objects[j][l] == 0)
                        {
                            for (int m = 0; m < V[i].get_width(); m++)
                            {
                                for (int n = 0; n < V[i].get_length(); n++)
                                {
                                    objects[j + n][l + m] = 1;
                                }
                            }
                            break;
                        }
                    }
                }
            }
        }

        
*/

/*
 * Problemas a resolver:
    - Modificar colocación, para revisar que la caja no se solape con otra caja.
    - Modificar colocación, para que si no cabe en una posición, la rote y vuelva a comprobar si cabe.
 */
Algorithms::Algorithms(container c)
{
   this->c = c;
}

void Algorithms::set_container(container in)
{
    length_container = in.get_length();
    width_container = in.get_width();
    height_container = in.get_height();
    k = in.get_k();
    objects = new int *[width_container];
    for (int i = 0; i < width_container; i++)
    {
        objects[i] = new int[length_container];
        for (int j = 0; j < length_container; j++)
        {
            objects[i][j] = in.objects[i][j];
        }
    }
    V_box = in.get_V();
    std::cout << "Container set" << std::endl;
    std::cout << "Length: " << length_container << std::endl;
    std::cout << "Width: " << width_container << std::endl; 
    std::cout << "Height: " << height_container << std::endl;   
    std::cout << "Number of boxes: " << k << std::endl;
}

void Algorithms::place_boxes()
{    
int n_box = 1;
for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < width_container; j++)
        {
            for (int l = 0; l < length_container; l++)
            {
                if (V_box[i].get_length() <= length_container - l && V_box[i].get_width() <= width_container - j && objects[j][l] == 0)
                {
                    for (int m = 0; m < V_box[i].get_length(); m++)
                    {
                        for (int n = 0; n < V_box[i].get_width(); n++)
                        {
                            objects[j + n][l + m] = n_box;
                        }
                    }
                    l = length_container;
                    j = width_container;
                    n_box++;
                    std::cout << n_box << std::endl;
                }
                else if (V_box[i].get_width() <= length_container - l && V_box[i].get_length() <= width_container - j && objects[j][l] == 0)
                {
                    for (int m = 0; m < V_box[i].get_width(); m++)
                    {
                        for (int n = 0; n < V_box[i].get_length(); n++)
                        {
                            objects[j + n][l + m] = n_box;
                        }
                    }
                    l = length_container;
                    j = width_container;
                    n_box++;
                    std::cout << n_box << std::endl;
                }
            }
        }
    }
}

