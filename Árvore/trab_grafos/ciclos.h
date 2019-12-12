#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <list>
//FRANCISCO ROMES DA SILVA FILHO // MATRICULA: 409976
//IMPLEMENTAÇÃO DE GRAFOS:
//VERIFICAÇÃO DE CICLOS
//Referência do código:
//Implementações passadas pelo professor em aula e do autor do trabalho


using namespace std;

	class Grafo {
		private:
			int V; // número de vértices
			bool direcionado; // grafo é direcionado ou não?
			list <int > *listaAdj; // lista de vetores de int
		public:
			Grafo(int n, bool d);
			~Grafo ();
			void addAresta(int u, int v);
			void imprimeAdjLista ();
			int grau(int v);
			bool cicl4s();
			bool repeticao(int *vector, int n, int x);

};
#endif