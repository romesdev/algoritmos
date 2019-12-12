#include <iostream>
#include "ciclos.h"
#include <fstream>
//FRANCISCO ROMES DA SILVA FILHO // MATRICULA: 409976
//IMPLEMENTAÇÃO DE GRAFOS:
//VERIFICAÇÃO DE CICLOS
//Referência do código:
//Implementações passadas pelo professor em aula e do autor do trabalho

using namespace std;

#define DIRECIONADO true
#define NAO_DIRECIONADO false

int main(){
    ifstream arq;
    arq.open("grafos.txt");
    int n, u, v;
    bool d = NAO_DIRECIONADO;
    while (true){        
        arq >> n;
        if (n != 0){
            Grafo *g = new Grafo (n, d);
            while(true){
            arq >> u >> v;
            if (u == 0 && v == 0) break;

            g->addAresta(u,v);
        }        
        cout << endl;
        if (g->cicl4s() == true) cout << "SIM" << endl; 
        else cout << "NAO" << endl;        
        g->~Grafo();
        }        
        else break;

    }
}


