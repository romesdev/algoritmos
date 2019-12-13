#include <iostream>
#include "RB.h"
// Implementação Árvore Rubro-Negra

/*Algoritmo baseado no livro de Algoritmos Cormen 3ª ed
obs: com convenções para o funcionamento;
*/

using namespace std;

int main(){
	RB *arvore = new RB();
	arvore->menu();
	delete arvore;
	return 0;


}
