#include <iostream>
#include <vector>   
#include "container.h"

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
int main()
{
    container c(10, 10, 1, 4);
    box b1(2, 2, 1);
    box b2(3, 3, 1);
    box b3(4, 4, 1);
    box b4(5, 5, 1);
    c.add_box(b1);
    c.add_box(b2);
    c.add_box(b3);
    c.add_box(b4);
    c.place_boxes();
    c.show();
    c.show_objects();
    return 0;
}
