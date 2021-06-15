/**
  @mainpage Diseño modular:  Gestión de una cadena de tienda de muebles.
 
    El programa se construye con un programa modular que ofrece un menú de
    opciones para gestionar un almacén. Se introducen las clases
    <em>Almacen</em>, <em>Sala</em> e <em>Inventario</em>.

    El programa principal se encuentra en el módulo program.cc.
    Atendiendo a los tipos de datos sugeridos en el enunciado. Necesitaremos un
    módulo para representar el Almacén en el que gestionaremos las
    actividades, otro para gestionar la Sala y otro para el Inventario, que 
    controla el sistema.

    Comentarios:

    - En una resolución normal, comenzaríamos por considerar las operaciones
    necesarias para el programa principal y las clasificaríamos en los
    diferentes módulos. Al pasar a su implementación, quizá descubriésemos que
    algún módulo necesita alguna operación adicional y la incorporaríamos en
    ese momento (sólo si es pública, es decir, si se usa en un módulo distinto
    al que pertenece). Sin embargo, en un documento de estas características,
    se presentan los módulos completamente acabados, sin necesidad de reflejar
    el proceso que ha dado lugar a su especificación final.

    - En cuanto a los diagramas modulares que aparecen en este proyecto, tendremos
    una relación entre el sistema(Inventario) y Almacén con el programa principal.
    También cabe tener en cuenta que cada Sala tendrá su propio Inventario.

*/

/** @file program.cc
    
    @brief Programa principal <em>Gestión de un almacen</em>.
    
    Estamos suponiendo que los datos leídos siempre son correctos, ya que
    no incluímos comprobaciones al respecto. Por último, puesto que los datos del
    almacén y salas son naturales (n_sala, identificadores,producto,...) usaremos palabras
    para las actividades.
*/

#include "Almacen.hh"
#include "Inventario.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#endif
using namespace std;


int main (){
    
    int n;  //número de parámetros de las salas
    cin >> n;
    Almacen  almacen(n);  //creo un almacén con n salas
    Inventario inventario; //creo un inventario para ir actualizando el sistema
    
    //se dimensiona las n salas
    for(int i=1; i <= n; ++i){
        almacen.dimensionar(i);
    }
    
    string actividad; //las actividades que tendremos que operar
    
    while( cin >> actividad and actividad != "fin"){
        
        //escribir el contenido de la estanteria
        if(actividad == "escribir"){
            int n;  
            cin >> n;
            cout << actividad << " " << n << endl;
            almacen.escribir(n);
        }
        
        //añadir una cierta cantidad de un producto
        else if (actividad == "poner_items"){
            int n, cantidad;
            string identificador;
            cin >> n >> identificador >> cantidad;
            cout << actividad << " " << n << " " << identificador << " " << cantidad << endl;
            if (not inventario.consultar_existe_producto(identificador)) cout << "  " << "error" <<endl;
            else cout << "  " << almacen.poner_items(n, identificador, cantidad, inventario) <<endl;
        }
        
        //elimina una cierta cantidad de un producto
        else if (actividad == "quitar_items"){
            int n, cantidad;
            string identificador;
            cin >> n >> identificador >> cantidad;
            cout << actividad << " " << n << " " << identificador << " " << cantidad << endl;
            if (not inventario.consultar_existe_producto(identificador)) cout << "  " << "error" <<endl;
            else cout << "  " << almacen.quitar_items(n, identificador, cantidad, inventario) <<endl;
        }
        
        //añadir un producto al sistema con 0 unidad 
        else if(actividad == "poner_prod"){
            string identificador;
            cin >> identificador;
            cout << actividad << " " << identificador << endl;
            if(inventario.consultar_existe_producto(identificador)) cout << "  " << "error" << endl;
            else inventario.poner_prod(identificador);
        }
        
        //el producto se da de baja del sistema
        else if(actividad == "quitar_prod"){
            string identificador;
            cin >> identificador;
            cout << actividad << " " << identificador << endl;
            if(not inventario.consultar_existe_producto(identificador) or  inventario.consultar_prod(identificador) != 0) cout << "  " << "error" << endl;
            else  inventario.quitar_prod(identificador);
        }
        
        //muestra el contenido del sistema
        else if(actividad == "inventario"){
            cout << actividad << endl;
            inventario.escribir();
        }
        
        //consultar la cantidad del producto que hay en el almacen
        else if(actividad == "consultar_prod"){
            string identificador;
            cin >> identificador;
            cout << actividad << " " << identificador << endl;
            if(not inventario.consultar_existe_producto(identificador)) cout << "  " << "error" << endl;
            else cout << "  " << inventario.consultar_prod(identificador) << endl; // aqui imprimire la cantidad del producto
        }
        
        //consultar un producto en una posición dada
        else if(actividad == "consultar_pos"){
            int n, fila, columna;
            cin >> n >> fila >> columna;
            cout << actividad << " " << n << " " << fila << " " << columna << endl;
            almacen.consultar_pos(n,fila,columna);
        }
        
        //distribuir una cierta cantidad de un producto determinado
        else if(actividad == "distribuir") {
            string identificador;
            int cantidad;
            cin >> identificador >> cantidad;
            cout << actividad << " " << identificador << " " << cantidad << endl;
            if(not inventario.consultar_existe_producto(identificador)) cout << "  " << "error" <<endl;
            else cout << "  " << almacen.distribuir(identificador, cantidad, inventario) << endl;  //tendre las unidades que no se han podido repartir
        }
        
        //redimensionar una sala determinada
        else if(actividad == "redimensionar"){
            int n, fila, columna;
            cin >> n >> fila >> columna;
            cout << actividad << " " <<  n << " " << fila << " " << columna << endl;
            almacen.redimensionar(n, fila, columna);
        }
        
        //reorganizar una sala determinada
        else if(actividad == "reorganizar"){
            int n;
            cin >> n;
            cout << actividad << " " << n << endl;
            almacen.reorganizar(n);
        }
        
        //compactar una estanteria determinada
        else if(actividad == "compactar"){
            int n;
            cin >> n;
            cout << actividad << " " << n << endl;
            almacen.compactar(n);
            
        }
        
    }   cout << "fin" << endl; 

}
