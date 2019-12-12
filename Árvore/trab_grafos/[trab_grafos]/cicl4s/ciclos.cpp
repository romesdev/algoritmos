#include <iostream>
#include <list>
#include "ciclos.h"
//FRANCISCO ROMES DA SILVA FILHO // MATRICULA: 409976
//IMPLEMENTAÇÃO DE GRAFOS:
//VERIFICAÇÃO DE CICLOS
//Referência do código:
//Implementações passadas pelo professor em aula e do autor do trabalho

//CONSTRUTOR
Grafo :: Grafo(int n, bool d) {
	V = n;
	direcionado = d;
	listaAdj = new list<int >[V];
}


//DESTRUTOR
Grafo ::~Grafo () {
	for (int i = 0; i < V; i++)
		listaAdj[i].clear();
}

//Inserção de Arestas
void Grafo :: addAresta(int u, int v) {
	listaAdj[u].push_back(v);
		
		if (!direcionado)
			listaAdj[v].push_back(u);
}

void Grafo :: imprimeAdjLista () {//imprime a minha lista
	for (int i = 0; i < V; i++) {
		cout << "Lista de adjacências do vértice " << i << ": ";
		for (const auto &vertex : listaAdj[i]) {
			cout << vertex << " ";
		}	
		cout << endl;
	}
}

bool Grafo::cicl4s (){
	int vetor[V];//vetor auxiliar
	list <int>::iterator it;//interador para percorrer minha lista
	list <int>::iterator ut;// 2º interador para percorrer minha lista
	int j = 0;
	for (int i = 0; i < V; i++){//laço para pecorrer minha lista
		if (grau(i) >= 2){//caso o vértice tenha grau 2 ou maior
			for (it = listaAdj[i].begin(); it != listaAdj[i].end(); it++) {//pecorro sua lista de Adj
				j = *it;//conforme aparecem, guardo os elementos que aparecem na lista
				for (ut = listaAdj[j].begin(); ut != listaAdj[j].end(); ut++){//analiso essas adjacências
					vetor[i] = *ut;//guardo em um vetor, para depois verificar repetições
				}
			}
			bool flag = repeticao(vetor, V, i);//chamo minha função repetição, que verifica os ciclos c4
			if (flag == true) return true;//caso eu tenha um retorno true, então tenho um ciclo c4
		}		
	}
	return false;//caso chegue nessa linha, não temos ciclos c4
}

int Grafo :: grau (int v){//Calcula o grau de um vértice V qualquer
	int grau = 0;
	list <int>::iterator it;
		for (it = listaAdj[v].begin(); it != listaAdj[v].end(); it++) {
			grau++;
		}
	return grau;
}

//função auxilixar na busca de ciclos c4
//procura repetições nas listas de adjacências
bool Grafo :: repeticao(int *vetor, int n, int x){

	for (int i = 0; i < n; i++){//tenho 2 laços para procurar repetições no vetor
		for (int j = i + 1; j < n; j++){
			//condições para ser um ciclo c4
			if (vetor[i] != 0 and vetor[j] !=0){
				if(vetor [j] != x and  vetor[i] == vetor[j]){ 
					return true;// chegar nessa linha representa que tenho um c4.
				}
			}
		}
	}
	return false;
	//se chego nessa linha, não tenho um ciclo c4.
}