/** @file Sala.hh
    @brief Especificación de la clase Sala
*/

#ifndef _SALA_HH_
#define _SALA_HH_

#include "Inventario.hh"

#ifndef NO_DIAGRAM
#include <string>
#include <vector>
#include <algorithm>
#endif
using namespace std;

#ifndef NO_DIAGRAM
typedef vector<string> Fila;
typedef vector<Fila> Matriz;
#endif
/** Clase Sala
*/

/** @class Sala
    @brief Representa la información y las operaciones asociadas a una sala.  

    Una sala es estanteria con f filas y c columnas, que representamos mediante una matriz. Tenemos todas las operación de la sala que se encarga de modificar items y de las operaciones compactar, redimensionar,... la consultora de un determinado producto de la sala, la de lectura (única para dimensionar la sala) y la de escritura(única para escribir los productos de la estanteria).
    
    Cabe tener en cuenta que cada sala tiene su propio inventario, que he declarado como \em private.
*/

class Sala{
    
    // Descripción: contiene una matriz de producto, su propio inventario y las operaciones de la sala.

private:
    
    /* Una Sala se representa mediante una matriz de string, que será
        el identificador del producto y se encontrará en una fila y columna determinada. */
    
    /** @brief Estanteria de producto que contiene una sala  */
    Matriz Estanteria;
    
    /** @brief Inventario de la sala */
    Inventario inventario_de_sala;
    
    
public:

//Constructora

    /** @brief Creadora por defecto. 
        Se ejecuta automáticamente al declarar una sala.
        \pre <em>cierto</em>
        \post El resultado es una sala vacia.
    */  
    Sala();

//Modificadoras
    
    /** @brief Añade un producto en la sala.
        \pre <em>cierto</em>
        \post El resultado es un entero que indica las unidades que no han cabido en la estanteria de una sala.
        \coste Lineal respecto la cantidad de items de un producto. 
    */
    int poner_items_sala(string identificador, int cantidad);
    
    
    
    /** @brief Quita un producto de la sala.
        \pre <em>cierto</em>
        \post El resultado es un entero que indica las unidades que no han podido quitar de la estanteria de esa sala.
        \coste Lineal respecto la cantidad de items de un producto.
    */
    int quitar_items_sala(string identificador, int cantidad);
        
    
    
    /** @brief Operación para compactar la estanteria de la sala.

        \pre <em>cierto</em>.
        \post La sala queda compactada.
        \coste Lineal respecto la cantidad de items de un producto.
    */  
    void compactar_sala();
    
    
    
    /** @brief Operación para reorganizar la estanteria de la sala.

        \pre <em>cierto</em>
        \post La sala queda reorganizada.
        \coste Cuadrática respecto al producto.
    */  
    void reorganizar_sala();
    
    
    
    /** @brief Operación para redimensionar la estanteria de la sala.

        \pre Se prepara el canal estandard para nuvas filas y columnas de la sala.
        \post El resultado indica si la sala puede ser redimensionada. 
        \coste Lineal respecto al producto.
    */  
    bool redimensionar_sala(int f, int c);
    
    
    
//Consultora

    /** @brief Operación consultora de una sala.

        \pre Se prepara el canal estandard de entrada para una una posición de la sala.
        \post El resultado es el producto correspondiente de dicha sala.
        \coste Constante.
    */  
    void consultar_pos_sala(int f, int c);
 
//Lectura y escriptura
    
    /** @brief Operación para dimensionar una sala.
        Permite declarar una sala nueva con una estanteria.
        \pre Se prepara el canal estandard de entrada para una sala.
        \post El resultado es una sala con su dimension.
        \coste Lineal respecto a la fila y columna de la sala.
    */  
    void dimensionar_sala(int f, int c);
    
    
    
    /** @brief Operación de escritura del contenido de una estanteria.

        \pre <em>cierto</em>
        \post El resultado es el contenido de la sala.
        \coste Lineal respecto al número del producto. 
    */  
    void escribir();
    
};

#endif
