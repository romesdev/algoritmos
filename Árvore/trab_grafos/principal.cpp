#include <iostream>
#include "ciclos.h"

//FRANCISCO ROMES DA SILVA FILHO // MATRICULA: 409976
//IMPLEMENTAÇÃO DE GRAFOS:
//VERIFICAÇÃO DE CICLOS
//Referência do código:
//Implementações passadas pelo professor em aula e do autor do trabalho

using namespace std;

#define DIRECIONADO true
#define NAO_DIRECIONADO false

Grafo *ler_grafo(bool d){
    int n, u, v;
    cin  >> n;
    Grafo *g = new Grafo(n, d);

    while (true){
        cin >> u >> v;
        if (u == 0 && v == 0) break;
        g->addAresta(u,v);
    }
    return g;
}

int main(){
    //while(true){        
    Grafo *g = ler_grafo(NAO_DIRECIONADO);
    cout << endl;
    if (g->cicl4s() == true) cout << endl << "SIM" << endl; 
    else cout << "NÃO" << endl;
    //}


}