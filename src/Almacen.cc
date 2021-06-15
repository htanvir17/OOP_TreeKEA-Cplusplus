/** @file Almacen.cc
    @brief Código de la clase Almacen 
*/

#include "Almacen.hh"


void Almacen::leer_bintree_int(BinTree<int>& a, int marca){
    
    int x;
    cin >> x;
    if (x != marca){
        BinTree <int> l;
        leer_bintree_int(l,marca);
        BinTree <int> r;
        leer_bintree_int(r,marca);
        a = BinTree<int> (x,l,r);
    }
    //tengo la estructura del arbol
}


Almacen::Almacen(){
    
}

Almacen::Almacen(int n_sala){
    almacen = vector<Sala> (n_sala); //tengo creado el vector de n_salas
    leer_bintree_int(estructura_almacen, 0); //voy a leer la estructura en preorden
}

int Almacen::poner_items(int n_sala, string identificador, int cantidad, Inventario& inventario){
    int no_cabido = almacen[n_sala -1].poner_items_sala(identificador, cantidad);   //me retorna la cantidad que no ha cabido
    
    int cabido = cantidad - no_cabido;
    inventario.poner_items_actualizado(identificador, cabido); //aqui actualizo el inventario del sistema y el inventario de la sala se he actualizado dentro de la sala
    
    return no_cabido;
}

int Almacen::quitar_items(int n_sala, string identificador, int cantidad, Inventario& inventario){
    int no_quitado = almacen[n_sala -1].quitar_items_sala(identificador, cantidad);     //me retorna la cantidad que no ha quitado
    
    int quitado = cantidad - no_quitado;
    inventario.quitar_items_actualizado(identificador, quitado);  //aqui actualizo el inventario del sistema y el inventario de la sala se he actualizado dentro de la sala
    
    return no_quitado;
     
}

int Almacen::i_distribuir(const BinTree<int>& a, string identificador, int cantidad, Inventario& inventario){
    if (a.empty()) return cantidad;
    else{
        int ndl, ndr; //nodo izquierda y derecha
        int x = a.value();  //x=raiz del arbol por donde empezaré a repartir
        int nd = poner_items(x,identificador, cantidad, inventario);    // nd = no distribuido, si nd es par distribuiré la mitad de cantidad al ndl. y otra al ndr, en caso contrario la mitad + sobrante irán al ndl y otra mitad al ndr 
        
        if(nd %2 == 0) ndl = i_distribuir(a.left(),identificador, nd/2, inventario);
        else ndl = i_distribuir(a.left(),identificador, (nd/2) + 1, inventario);
        
        ndr = i_distribuir(a.right(),identificador, nd/2, inventario);
        
        return ndl+ndr; //devulevo las cantidades que no se han podido distribuir
    }
}

int Almacen::distribuir(string identificador, int cantidad, Inventario& inventario){
    return i_distribuir(estructura_almacen, identificador, cantidad, inventario);   //función de inmersión
}

void Almacen::compactar(int n_sala){
    almacen[n_sala -1].compactar_sala();
}

void Almacen::reorganizar(int n_sala){
    almacen[n_sala -1].reorganizar_sala();

}

void Almacen::redimensionar(int n_sala, int f, int c){
    if (not almacen[n_sala -1].redimensionar_sala(f, c)) cout << "  " << "error" <<endl;
    
}

void Almacen::consultar_pos(int n_sala, int f, int c){
    almacen[n_sala -1].consultar_pos_sala(f, c);
}

void Almacen::dimensionar(int n_sala){
    int f, c;
    cin >> f >> c;
    almacen[n_sala - 1].dimensionar_sala(f,c);
}

void Almacen::escribir(int n_sala){
    almacen[n_sala - 1].escribir();
    
}


