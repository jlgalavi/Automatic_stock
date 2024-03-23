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
    - Ordenar vector de mayor a menor
    - Gestionar contenedores, si quedan cajas sin colocarse, se crea un nuevo contenedor para almacenar el resto.
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

bool Algorithms::prove_object(int **objects, int w, int l, box v)
{
    int width = w + v.get_width();
    int length = l + v.get_length();
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
void Algorithms::order_boxes()
{
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k - 1; j++)
        {
            if (V_box[j].get_volume() < V_box[j + 1].get_volume())
            {
                box temp = V_box[j];
                V_box[j] = V_box[j + 1];
                V_box[j + 1] = temp;
            }
        }
    }
}

void Algorithms::place_boxes()
{    
int n_box = 1;
for (int i = 0; i < k; i++)
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
                    l = length_container;
                    w = width_container;
                    n_box++;
                    V_box[i].set_placed(true);
                }
                else if (V_box[i].get_width() <= length_container - l && V_box[i].get_length() <= width_container - w && prove_object(objects,  l, w, V_box[i]))
                {
                    for (int m = 0; m < V_box[i].get_width(); m++)
                    {
                        for (int n = 0; n < V_box[i].get_length(); n++)
                        {
                            objects[w + n][l + m] = n_box;
                        }
                    }
                    w = length_container;
                    l = width_container;
                    n_box++;
                    V_box[i].set_placed(true);
                }
            }
        }
    }
}

