#include <iostream>
#ifndef RB_H
#define RB_H
//Implementação Árvore Rubro-Negra


/*Algoritmo baseado no livro Algoritmos: Teoria e Prática Cormen 3ª ed
obs: 
	- com convenções para o funcionamento;
*/

class RB{
	private:
		typedef struct No No;
		No* raiz;
		No* nil;
		
		void RB_inserir(No* no);
		void RB_inserirBalancear (No* no);
		bool igual(No* a, No* b);
		
		void RB_rotacaoEsquerda(No *y);
		void RB_rotacaoDireita(No *y);
		
		void RB_transplante (No *a, No *b);
		void RB_delete (No *z);
		void RB_deleteBalancear (No *z);
		
		void RB_preOrdem (No *no);
		int RB_altura (No *no);
		No* RB_buscar (No *no, int w);
		No* minimo(No* no);

	public:
		RB();
		~RB();

		void inserir(int x);
		void RB_delete (int z);
		void RB_preOrdem ();
		int altura ();
		No* RB_buscar (int w);	
		void menu();

};
#endif 