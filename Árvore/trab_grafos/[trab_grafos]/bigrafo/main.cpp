#include <iostream>
#include "bigrafo.h"
#include <fstream>
using namespace std;

#define DIRECIONADO true
#define NAO_DIRECIONADO false

//FRANCISCO ROMES DA SILVA FILHO // MATRICULA: 409976
//IMPLEMENTAÇÃO DE GRAFOS:
//COLORAÇÃO DE GRAFOS
//VERIFICAÇÃO DE GRAFO BIPARTIDO (BIGRAFO)
//Referência do código:
//Implementações passadas pelo professor em aula e do autor do trabalho



int main(){
    ifstream arq;
    arq.open("grafos.txt");
    
    int n, u, v;
    bool d = NAO_DIRECIONADO;
    
    while(true){
        arq >> n;
        if (n != 0){//se o número de vértices for diferente de 0
            Grafo *g = new Grafo(n, d);//aloco meu grafo   
            
            while (true){
            arq >> u >> v;//leio as arestas
                if (u == 0 && v == 0) break;//analiso
                    g->addAresta(u,v);//e adiciono as arestas          
            }

            //chamada da função p/ verificar a coloração do grafo
            if (g->bigrafo() == true){
                cout << "SIM" << endl;
                g->printCores();
            }     
            
            else cout << "NAO" << endl;

            g->~Grafo();//chamo o destrutor      
       }
       else break;    
    }
}