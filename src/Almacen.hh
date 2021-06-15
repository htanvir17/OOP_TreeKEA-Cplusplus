/** @file Almacen.hh
    @brief Especificación de la clase Almacen
*/

#ifndef _ALMACEN_HH_
#define _ALMACEN_HH_

#include "Sala.hh"
#include "Inventario.hh"

#ifndef NO_DIAGRAM 
#include <string>
#include <vector>
#include "BinTree.hh"
#endif
using namespace std;

/** Clase Almacen 
*/
/** @class Almacen
    
    @brief Representa el conjunto de características y operaciones del almacén. 
    
    Sus operaciones son las modificadoras de items, de repartir productos y de las operaciones de la sala(compactar, redimensionar,...), la consultora de un determinado producto, la de lectura (única para dimensionar la sala) y la de escritura(única para escribir los productos de la sala).

    He declarado algunas operaciones auxiliares como \em private. 

*/

class Almacen{
    
    // Descripción: contiene la estructura del almacén y sus operaciones relacionados con la sala.
    
    
private:
    /* La estructura de un Almacen se representa de forma arborescente de enteros, que tendrá
        su identificador de la sala. */

    /** @brief Estructura del almacen de enteros */
    BinTree <int> estructura_almacen;
    
    
    /** @brief Almacen de las salas  */
    vector <Sala> almacen;
    

public:

//Constructoras

    /** @brief Creadora por defecto. 

        Se ejecuta automáticamente al declarar un almacén.
        \pre <em>cierto</em>
        \post El resultado es un almacen vacio.
    */  
    Almacen();

    
    /** @brief Creadora del almacén. 

        Permite declarar un almacén nuevo con n_salas y su estructura.
        \pre <em>cierto</em>
        \post El resultado es un almacén con n_salas y su estructura.
        \coste Lineal respecto al número de salas.
    */  
    Almacen(int n_sala);

//Modificadoras
    
    /** @brief Añade un producto en una sala.
        \pre 1 <= n_sala <= nombre de salas del almacén
        \post El resultado es un entero que indica las unidades que no han cabido en la estanteria de una sala.
        \coste Lineal respecto al número de unidades del producto. 
    */
    int poner_items(int n_sala, string identificador, int cantidad, Inventario& inventario);
    
        
    /** @brief Quita un producto de la sala.
        \pre  1 <= n_sala <= nombre de salas del almacén
        \post El resultado es un entero que indica las unidades que no han podido quitar de la estanteria de esa sala.
        \coste Lineal respecto al número de unidades del producto.
    */
    int quitar_items(int n_sala, string identificador, int cantidad, Inventario& inventario);

    
    /** @brief Operación de distribución.

        \pre Se prepara el canal estandard de entrada para un producto con n cantidad.
        \post El resultado es un entero que indica las unidades que no se han podido distribuir.
        \coste Lineal respecto al número de cantidad de producto. 
    */  
    int distribuir(string identificador, int cantidad, Inventario& inventario);
    
    
    /** @brief Operación para compactar la estanteria de la sala.

        \pre Se prepara el canal estandard de entrada para una sala.
        \post La sala queda compactada.
        \coste Lineal respecto al número de sala del parámetro implícito. 
    */  
    void compactar(int n_sala);
    
    
    
    /** @brief Operación para reorganizar la estanteria de la sala.

        \pre Se prepara el canal estandard de entrada para una sala.
        \post La sala queda reorganizada.
        \coste Lineal respecto al número de sala del parámetro implícito. 
    */  
    void reorganizar(int n_sala);
    
    
    
    /** @brief Operación para redimensionar la estanteria de la sala.

        \pre Se prepara el canal estandard de entrada para una sala.
        \post La sala queda redimensioda.
        \coste Lineal respecto al número de sala del parámetro implícito. 
    */  
    void redimensionar(int n_sala, int fila, int columna); 
    
//Consultores

    /** @brief Operación consultora de una sala.

        \pre Se prepara el canal estandard de entrada para una sala.
        \post El resultado es el producto correspondiente de la estanteria de dicha sala.
        \coste Lineal respecto al número de sala con su fila y columna. 
    */  
    void consultar_pos(int n_sala, int fila, int columna);
    
    
//Lectura y escriptura
    
    /** @brief Operación para dimensionar una sala.

        \pre Se prepara el canal estandard de entrada para una identificador de la sala y se esperara una fila y columna.
        \post El resultado es una sala con su dimension.
        \coste Lineal respecto al número de sala del parámetro implícito. 
    */  
    void dimensionar(int n_sala);
    
    
    
    /** @brief Operación de escritura del contenido de una estanteria.

        \pre Se prepara el canal estandard de entrada para una determinada sala.
        \post El resultado es el contenido de la sala.
        \coste Lineal respecto al número de parámetros de una sala. 
    */  
    void escribir(int n_sala);
    
    
    
private:
        
    // Tipos de modulo: datos
    // Descripcion del tipos: representa un conjunt de salas
    // Se puede consultar y  modificar los productos de la sala elements. Se puede aplicar el mismo criterio con una sala.
    
    
    /** @brief Operación de lectura de un árbol de enteros.
        \pre  marca = 0; estructura_almacen es vacío
        \post estructura_almacen contiene el árbol de enteros leído de la entrada
        \coste Lineal respecto al número de enteros del árbol leído
    */ 
    void leer_bintree_int(BinTree <int>& estructura_almacen, int marca);
    
    
    /** @brief Distribución de unidades de un pruducto.
        @pre Se prepara el canal estandard para a = estructura_almacen con el producto y su cantidad.
        @post Inventario actualiza las cantidades que se han podido repartir y retorna las cantidades que no se han podido repartir.
        @coste Lineal respecto al número de producto.
  */
    int i_distribuir(const BinTree<int>& a, string identificador, int cantidad, Inventario& inventario);
    
    /*
    Invariante de la representacion:
    - almacen[0..n_salas-1] 1 <= n_salas <= almacen.size();
    */
    
};

#endif
