/** @file Sala.cc
    @brief Código de la clase Sala
*/

#include "Sala.hh"

Sala::Sala(){
    
}

int Sala::poner_items_sala(string identificador, int cantidad){
    int f = Estanteria.size();
    int c = Estanteria[0].size();
    int no_cabido = cantidad;
    
    for(int i=f - 1; i >= 0 and no_cabido > 0 ; --i){
        for(int j= 0; j < c and no_cabido > 0; ++j){
            if(Estanteria[i][j].empty()){
                Estanteria[i][j] = identificador;
                --no_cabido;
            }
        }
    }
    int cabido = cantidad - no_cabido;
    
    if(cabido != 0)
        inventario_de_sala.poner_items_actualizado(identificador, cabido);
        
    return no_cabido;
    
}

int Sala::quitar_items_sala(string identificador, int cantidad){
    int f = Estanteria.size();
    int c = Estanteria[0].size();
    int no_quitado = cantidad;
    int items_actuals = inventario_de_sala.consultar_prod(identificador);

    for(int i = f-1; i>=0 and items_actuals > 0 and no_quitado > 0; --i){
        for(int j = 0; j < c and items_actuals > 0 and no_quitado > 0; ++j){
            if(Estanteria[i][j] == identificador){
                Estanteria[i][j] = "";
                --no_quitado;
                --items_actuals;
            }
        }
    }
      
    int quitado = cantidad - no_quitado;
    
    inventario_de_sala.quitar_items_actualizado(identificador, quitado);
    
    if(inventario_de_sala.consultar_prod(identificador) <= 0)
        inventario_de_sala.quitar_prod(identificador);
    
    return no_quitado;
}

void Sala::compactar_sala(){
    int f = Estanteria.size();
    int c = Estanteria[0].size();
    int fc = f-1;
    int cc = 0;
    
    Matriz sala_cp(f,Fila(c));
    
    for(int i = f-1; i >= 0; --i){
        for(int j= 0; j < c; ++j){
            if(not Estanteria[i][j].empty()){
                sala_cp[fc][cc] = Estanteria[i][j];
                
                if(fc >= 0 and cc < c-1) ++cc;
                else if (cc == c-1 and fc >= 0){
                    --fc;
                    cc = 0;
                }
                
            }
        }
    }
    
    Estanteria = sala_cp;
}

void Sala::reorganizar_sala(){    
    int f = Estanteria.size();
    int c = Estanteria[0].size();
    Fila vec_aux;
    
    for(int i = f-1; i>=0; --i){
        for(int j = 0; j < c; ++j){
            if(not Estanteria[i][j].empty()){
                vec_aux.push_back(Estanteria[i][j]);
                Estanteria[i][j] = "";
            }
        }
    }
    sort(vec_aux.begin(), vec_aux.end());
    
    int tam = vec_aux.size();
    int aux = 0;
    for(int i = f-1; i>=0 and aux < tam; --i){
        for(int j = 0; j < c and aux < tam; ++j){
            Estanteria[i][j] = vec_aux[aux];
            ++aux;
        }
    }

}

bool Sala::redimensionar_sala(int fr, int cr){
    
    int cantidad = inventario_de_sala.consultar_prods_total();
    bool r = fr*cr >= cantidad;
    
    if(r){
        int f = Estanteria.size();
        int c = Estanteria[0].size();
        
        Matriz sala_re(fr,Fila(cr));
        int fa = fr-1;
        int ca = 0;
        
        for(int i = f-1; i >= 0; --i){
            for(int j= 0; j < c; ++j){
                if(not Estanteria[i][j].empty()){
                    sala_re[fa][ca] = Estanteria[i][j];
                
                    if(fa >= 0 and ca < cr-1) ++ca;
                    else if (ca == cr-1 and fa >= 0){
                        --fa;
                        ca = 0;
                    }
                }
            }
        }
        
        Estanteria = sala_re;
        
        return r;
    }
    
    return r;
}



void Sala::consultar_pos_sala(int f, int c){
    cout << "  ";
    if(f <= Estanteria.size() and c <= Estanteria[0].size() and not Estanteria[f-1][c-1].empty()) cout << Estanteria[f - 1][c - 1];
    else cout << "NULL";
   
    cout << endl;
}


void Sala::dimensionar_sala(int f, int c){
    Estanteria = Matriz (f,Fila(c,"")); //creo una estanteria de x filas y x columnas
}


void Sala::escribir(){
    
    int f = Estanteria.size();
    int c = Estanteria[0].size();

    for(int i=0; i < f; ++i){
        cout << "  ";
        for(int j=0; j < c; ++j){
            if (Estanteria[i][j].empty()){
                cout << "NULL";
            }
            else{
                cout << Estanteria[i][j];
            }
            if(j != c -1) cout << " "; 
        }
        cout << endl;
    }
    
    cout << "  " << inventario_de_sala.consultar_prods_total()<< endl;
    inventario_de_sala.escribir(); //en el inventario voy a escribir el identificador del producto y su cantidad;
}



