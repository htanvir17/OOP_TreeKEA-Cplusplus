/** @file Inventario.hh
    @brief Especificación de la clase Inventario. 
*/


#ifndef _INVENTARIO_HH_
#define _INVENTARIO_HH_
                
#ifndef NO_DIAGRAM
#include <iostream>  
#include <string>
#include <map> 
#endif                       
using namespace std;

/** Clase Inventario
*/

/** @class Inventario
    
    @brief Representa toda la información del sistema.
    
    Ofrece operaciones para introducir o eliminar un producto en el sistema, modificadoras para cambiar cantidad de un producto, de lectura y escritura del sistema. 
*/

class Inventario{
    
    // Descripción: contiene el computo de las unidades de un producto, si existe. También las operaciones necesarias para gestionar todos los productos.
    
private:
   
    /** @brief Map del inventario.Ordenada crecientemente por el id de sus producto */
    map <string, int> inventario_del_sistema;
    
    /** @brief Iterador del map del inventario */
    map <string, int>::iterator it;
    
    /** @brief Cantidad total del producto */
    int cantidad_total;
    
    
public:
    
//Creadora
    
    /** @brief Creadora por defecto. 

        Se ejecuta automáticamente al declarar inventario.
        \pre <em>cierto</em>
        \post El resultado es un inventario vacio con cantidad 0.
    */  
    Inventario();
    
//Modificadoras
    
    /** @brief Añade un producto en el inventario.
        \pre <em>cierto</em>
        \post El resultado es un producto que se da de alta en el sistema con cero unidades.
        \coste Constante respecto al producto.
    */
    void poner_prod(string identificador);
    
    
    /** @brief Elimina un producto del inventario.
        \pre <em>cierto</em>
        \post El resultado es un producto que se da de baja del sistema.
        \coste Log n respecto al producto.
    */
    void quitar_prod(string identificador);
    
    
    /** @brief Actualiza un producto con su cantidad.
        \pre <em>cierto</em>
        \post El resultado es un producto actualizado con su cantidad.
        \coste Constante respecto al producto.
    */
    void poner_items_actualizado(string identificador, int cantidad);
    
        
    /** @brief Actualiza un producto con su cantidad.
        \pre <em>cierto</em>
        \post El resultado es un producto que se elimina dependiendo de la cantidad.
        \coste Constante respecto al producto.
    */
    void quitar_items_actualizado(string identificador, int cantidad);
    
//consultoras
    
    /** @brief Operación consultora de un producto.

        \pre Se prepara el canal estandard de entrada para un producto.
        \post El resultado es el producto con sus unidades correspondientes del almacen.
        \coste Log n respecto al producto.
    */  
    int consultar_prod(string identificador)const;
    
    
        
    /** @brief Operación consultora del producto total.

        \pre Cierto.
        \post El resultado es el producto total del sistema.
        \coste Constante respecto al producto.
    */ 
    int consultar_prods_total()const;
    
    
    /** @brief Operación para cunsultar la existencia de un producto.

        \pre Se prepara el canal estandard para un identificador del producto.
        \post El resultado indica si el producto existe.
        \coste Constante respecto al producto.
    */  
    bool consultar_existe_producto(string identificador)const;

//Escriptura
    
    /** @brief Operación de escritura del contenido del sistema.

        \pre <em>cierto</em>
        \post El resultado es el contenido del sistema.
        \coste Lineal respecto al producto.
    */  
    void escribir();
    
};

#endif
