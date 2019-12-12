#ifndef GRAPH_H
#define GRAPH_H
#include <iostream >
#include <list >
using namespace std;

	class Grafo {
		private:
			int V; // número de vértices
			bool direcionado; // grafo é direcionado ou não?
			list <int > *listaAdj; // lista de vetores de int
			void removeDaLista(list <int > &lista , int v);
		public:
			Grafo(int n, bool d);
			~Grafo ();
			void addAresta(int u, int v);
			void removeAresta(int u, int v);
			bool temAresta(int u, int v);
			void imprimeAdjLista ();

};
#endif