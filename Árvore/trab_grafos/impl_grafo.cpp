#include <iostream>
#include "grafo.h"

#define BRANCO 'B'
#define AMARELO 'A'
#define ROSA 'R'

using namespace std;


Grafo::Grafo (int n, bool d){
    V = n;
    direcionado = d;
    adjM = new int*[n];
    cores = new char[n];

    for (int i = 0; i < n; i++)
        adjM[i] = new int[n];
    //cores[i] = new char[n]; 
    int k = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adjM[i][j] = 0;
            cores[k] = BRANCO;
            k++;
}

Grafo::~Grafo(){
    for (int i = 0; i < V; i++)
        delete[] adjM[i];
    delete[] adjM;
}

void Grafo::addAresta (int orig, int dest){
    adjM[orig][dest] = 1;
    
    if (cores[orig] == BRANCO){
        if(cores[dest] == BRANCO || cores[dest] == ROSA)
            cores[orig] = AMARELO;
    }
    if (cores[dest] == AMARELO){
        cores[orig] = ROSA;
    }

    if (!direcionado)
        adjM[dest] [orig] = 1;
}

void Grafo::printCores(){
    for (int i = 0; i < V; i++){
        cout << i << " ==> " << cores[i] << endl;
    } 
    cout << endl;
        
}






















void Grafo::removeAresta (int orig, int dest){
    adjM[orig][dest] = 0;
    if (!direcionado)
        adjM[dest][orig] = 0;
}

bool Grafo::temAresta (int orig, int dest){
    return adjM[orig][dest];
}

void Grafo::imprimeVizinhos (int u){
    cout << "===> Vizinhos de " << u << ": ";
    
    for (int v = 0; v < V; v++)
        if (adjM[u][v])
            cout << v << " ";

    cout << endl;
}

void Grafo::imprimeAdjMatriz (){
    for (int u = 0; u < V; u++){
        for (int v = 0; v < V; v++){
            cout << adjM[u][v];
        }
        cout << endl;
    }
}
