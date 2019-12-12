#include <iostream>
#include "bigrafo.h"
//FRANCISCO ROMES DA SILVA FILHO // MATRICULA: 409976
//IMPLEMENTAÇÃO DE GRAFOS:
//COLORAÇÃO DE GRAFOS
//VERIFICAÇÃO DE GRAFO BIPARTIDO (BIGRAFO)
//Referência do código:
//Implementações passadas pelo professor em aula e do autor do trabalho


//CORES:: estou definindo 3 tipos de cores:
#define EPSILON 'e' //COR EPSILON (NULA), PARA INICIALIZAÇÃO
#define RED 'R' // COR RED, COMO A 1ª COR
#define BLACK 'B' // COR BLACK, COMO A 2ª COR 


using namespace std;

//CONSTRUTOR
Grafo::Grafo (int n, bool d){//recebo o número de vértices e se o grafo é direcionado
    V = n; //V recebe a quantidade vértices
    direcionado = d;//true ou false p/ direcionado
    adjM = new int*[n];//aloco memória para minha matriz de adj
    cores = new char[n];//aloco memória para o vetor de cores

    for (int i = 0; i < n; i++){//crio minha matriz 
        adjM[i] = new int[n];
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            adjM[i][j] = 0;//inicializo minha matriz com 0s
        }
        cores[i] = EPSILON;//defino as cores inicialmente como todas EPSILON
    }
}

//DESTRUTOR
Grafo::~Grafo(){
    for (int i = 0; i < V; i++)
        delete[] adjM[i];//apago minha matriz
    delete[] adjM;
}


//INSERÇÃO DE ARESTAS
void Grafo::addAresta (int orig, int dest){
    adjM[orig][dest] = 1; //DADO A ORIGEM E O DESTINO DA SETA, SET(1)
    //cores[orig] = ROSA;

    if (!direcionado)
        adjM[dest] [orig] = 1;
    
    if (cores[orig] == EPSILON){//se o vértice ainda não tem cor
        if(cores[dest] == EPSILON || cores[dest] == BLACK){//dado a cor do destino
            cores[orig] = RED; //pinto de vermelho
        }
        else if (cores[dest] == RED){//caso a cor seja vermelho
        cores[orig] = BLACK;//pinto de preto
        }
    }
    if (cores[dest] == EPSILON){//se o vértice que acabou de ser ligado for EPSILON
        //verifico a cor do seu vizinho e
        if(cores[orig] == BLACK){//se for preto
            cores[dest] = RED;//pinto de vermelho
        }//ou
        else if (cores[orig] == RED){//se for vermelho
        cores[dest] = BLACK;//pinto de preto
        }
    }
}

//VERIFICAR UM BIGRAFO
bool Grafo::bigrafo(){
    //pecorro minha matriz de adjacências
    for (int i = 0; i < V; i++){
        for (int j = i + 1; j < V; j++){
            if (adjM[i][j] == 1)//caso exista um caminho entre os vértices
                if (cores[i] == cores[j])//verifico se existe cores iguais
                    return false;//se sim, retorno falso
                    //ou seja, não é um grafo bipartido
        }
    }
    return true;//caso chegue nessa linha, tenho um bigrafo
    //retorno verdadeiro
}

//COLORAÇÃO DOS VÉRTICES
void Grafo::printCores(){
    for (int i = 0; i < V; i++){//pecorro meu vetor de cores
        cout << i << " ==> " 
        << cores[i] << endl;//printo o vértice[i] e a cor[i]
    }    
}

//MOSTRAR NA TELA A MATRIZ DE ADJACÊNCIAS
void Grafo::imprimeAdjMatriz (){
    for (int i = 0; i < V; i++){
            for (int j = 0; j < V; j++){
                cout << adjM[i][j] << " ";
        }
        cout <<  endl;
    }
}

