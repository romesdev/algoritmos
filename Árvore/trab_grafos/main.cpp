#include <iostream>
#include "bigrafo.h"


using namespace std;

#define DIRECIONADO true
#define NAO_DIRECIONADO false

//FRANCISCO ROMES DA SILVA FILHO // MATRICULA: 409976
//IMPLEMENTAÇÃO DE GRAFOS:
//COLORAÇÃO DE GRAFOS
//VERIFICAÇÃO DE GRAFO BIPARTIDO (BIGRAFO)
//Referência do código:
//Implementações passadas pelo professor em aula e do autor do trabalho


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
    Grafo *g = ler_grafo(NAO_DIRECIONADO);
    
    g->printCores();
    cout << endl;
    if (g->bigrafo() == true) cout << "SIM" << endl;
    else cout << "NAO" << endl;

    g->~Grafo();
    delete g;

}