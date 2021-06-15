/** @file Inventario.cc
    @brief Código de la clase Inventario
*/

#include "Inventario.hh"

Inventario::Inventario(){
    // Inicializa el inventario con 0 unidad del producto
    cantidad_total = 0;
}

void Inventario::poner_prod(string identificador){
    inventario_del_sistema[identificador]; //doy de alta el producto con 0 unidad
}

void Inventario::quitar_prod(string identificador){
    it = inventario_del_sistema.find(identificador); //doy de baja el producto que tiene 0 unidad
    inventario_del_sistema.erase(it);
}

void Inventario::poner_items_actualizado(string identificador, int cantidad){
    inventario_del_sistema[identificador] += cantidad; 
    cantidad_total += cantidad;
}

void Inventario::quitar_items_actualizado(string identificador, int cantidad){
    inventario_del_sistema[identificador] -= cantidad; 
    cantidad_total -= cantidad;

}

int Inventario::consultar_prod(string identificador)const{
    map <string, int>::const_iterator it_const;
    it_const = inventario_del_sistema.find(identificador);
    if (it_const != inventario_del_sistema.end()) return it_const->second;
    return -1;
}

int Inventario::consultar_prods_total()const{
    return cantidad_total;
}


bool Inventario::consultar_existe_producto(string identificador)const{
    map <string, int>::const_iterator it_const;
    it_const = inventario_del_sistema.find(identificador);
    return it_const != inventario_del_sistema.end(); 
}

void Inventario::escribir(){
    it = inventario_del_sistema.begin();
    while(it != inventario_del_sistema.end()){
        cout << "  " <<(*it).first << " " << (*it).second << endl;
        ++it;
    }    
}
