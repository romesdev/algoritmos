#include <iostream>
#include "RB.h"
//Implementação Árvore Rubro-Negra

/*Algoritmo baseado no livro de Algoritmos Cormen 3ª ed
obs: com convenções para o funcionamento;
*/

using namespace std;

#define PRETO 'P' //variável global para nós pretos
#define VERMELHO 'V' //variável global para nós vermelhos

typedef struct No{
	int dado;
	struct No *pai, *esq, *dir;
	char cor;
} No;

RB::RB(){//construtor 
	nil = new No;
	nil->cor = PRETO; //meu nó nil sempre é preto
	nil->dado = -42;//resposta para a vida o universo e tudo mais
	//(-42) apenas para inicializar
	raiz = nil;//raiz de inicio aponta para nil
    nil->pai = nil->esq = nil->dir = nil;//redefinição dos nós de nil 
};

RB::~RB(){
	//destrutor
	delete raiz;
	delete nil;
};

//INSERIR::insercão de nós
void RB::inserir(int x){
	No* no = new No;
	no->dado = x;
	RB_inserir(no);
}
//IgualNil:: função auxiliar para dizer se: nó == nil
bool RB::igual(No* a, No* b){
	if (a->cor == b->cor && a->dado == b->dado)
		return true;
	else return false;
}

//Método Inserir baseado no Pseudo-Código do Cormen
void RB::RB_inserir(No* no){
	No* y;
	No* x;
	y = nil;
	x = raiz;
	while(x != nil){
		y = x;
		if (no->dado < x->dado) //procuro o local certo para o nó na árvore
			x = x->esq;	
		else x = x->dir;
	}

	no->pai = y;
	if (y == nil) raiz = no;
	else if (no->dado < y->dado) y->esq = no;
	else y->dir = no;
	no->esq = nil; //folhas apontam para nil
	no->dir = nil; //folhas apontam para nil
	no->cor = VERMELHO;//sempre insiro o nó como vermelho
	RB_inserirBalancear(no);// realizo a chamada da função que balanceia após a inserção

}
//parte final da Inserção, onde realizo o balanceamento
void RB::RB_inserirBalancear (No* no){ 
	No* y;
	while (no->pai->cor == VERMELHO){ //realizo a troca de cores necessárias
	// e chamo as rotações quando necessário para manter o balanceamento
		
		if (no->pai == no->pai->pai->esq){

			y = no->pai->pai->dir;
			if (y->cor == VERMELHO){
				no->pai->cor = PRETO;
				y->cor = PRETO;
				no->pai->pai->cor = VERMELHO;
				no = no->pai->pai;
			
			}else{

			 if (no == no->pai->dir){ 
				no = no->pai;
				RB_rotacaoEsquerda(no);
			}
			
			no->pai->cor = PRETO;
			no->pai->pai->cor = VERMELHO;
			RB_rotacaoDireita(no->pai->pai);
			}
	}else{
		y = no->pai->pai->esq;
			if (y->cor == VERMELHO){

				no->pai->cor = PRETO;
				y->cor = PRETO;
				no->pai->pai->cor = VERMELHO;
				no = no->pai->pai;
			
			}else{ 
			
				if (no == no->pai->esq){ 
				no = no->pai;
				RB_rotacaoDireita(no);
			}	

			no->pai->cor = PRETO;
			no->pai->pai->cor = VERMELHO;
			RB_rotacaoEsquerda(no->pai->pai);
			}
		}
	}
	raiz->cor = PRETO;
}



//ROTAÇÕES::rotacões para manter minha árvore balanceada

void RB::RB_rotacaoEsquerda(No* x){

	No* y;
	y = x->dir;
	x->dir = y->esq;
	if (y->esq != nil){
		y->esq->pai = x;
	}
	y->pai = x->pai;
	if (x->pai == nil){
		raiz = y;
	}
	else if (x == x->pai->esq){
		x->pai->esq = y;
	}
	else x->pai->dir = y;
	y->esq = x;
	x->pai = y;
}

void RB::RB_rotacaoDireita(No* x){

	No* y;
	y = x->esq;
	x->esq = y->dir;
	if (y->dir != nil){
		y->dir->pai = x;
	}
	y->pai = x->pai;
	if (x->pai == nil){
		raiz = y;
	}
	else if (x == x->pai->dir){
		x->pai->dir = y;
	}
	else x->pai->esq = y;
	y->dir = x;
	x->pai = y;
}

//função de apoio para a minha remoção
void RB::RB_transplante (No* a, No* b){
	if (a->pai == nil) this->raiz = b;
	
	else if (a == a->pai->esq) a->pai->esq = b;
	
	else a->pai->dir = b;

	b->pai = a->pai;
}

//DELETE::Remocão de nós
//aqui passo o nó exato a ser removido
void RB::RB_delete (No* no){
	No* y = no;
	No* x;
	char corY = y->cor;
	if (no->esq == nil){
		x = no->dir;
		RB_transplante(no, no->dir);
	}
	else if (no->dir == nil){
		x = no->esq;
		RB_transplante(no, no->esq);
	} 
	else{
		y = minimo(no->dir);
		corY = y->cor;
		x = y->dir;
		if (y->pai == no) x->pai = y;
		else{
			RB_transplante(y, y->dir);
			y->dir = no->dir;
			y->dir->pai = y;
		}
		RB_transplante(no, y);
		y->esq = no->esq;
		y->esq->pai = y;
		y->cor = no->cor;
	}
	if (corY == PRETO) RB_deleteBalancear(x);// chamo a função que balanceia depois da remoção
}

//função que balanceia quando há remoção
//altero cores se for necessário e chamo as rotações
void RB::RB_deleteBalancear (No* no){
	No* w;
	while (no != raiz && no->cor == PRETO){
		if (no == no->pai->esq){
			w = no->pai->dir;
			if (w->cor == VERMELHO){ //caso 1
				w->cor = PRETO;
				no->pai->cor = VERMELHO;
				RB_rotacaoEsquerda(no->pai);
				w = no->pai->dir;
			}
			if (w->esq->cor == PRETO && w->dir->cor == PRETO){ //caso 2
				w->cor = VERMELHO;
				no = no->pai;
			}else{ 
				if (w->dir->cor == PRETO){//caso 3
				w->esq->cor = PRETO;
				w->cor = VERMELHO;
				RB_rotacaoDireita(w);
				w = no->pai->dir;
			}//caso 4
			w->cor = no->pai->cor;
			no->pai->cor = PRETO;
			w->dir->cor = PRETO;
			RB_rotacaoEsquerda(no->pai);
			no = raiz;
			}
		}else{
		   if (no == no->pai->dir){
				w = no->pai->esq;
				if (w->cor == VERMELHO){//caso 1
					w->cor = PRETO;
					no->pai->cor = VERMELHO;
					RB_rotacaoDireita(no->pai);
					w = no->pai->esq;
				}
				if (w->dir->cor == PRETO && w->esq->cor == PRETO){//caso 2
					w->cor = VERMELHO;
					no = no->pai;
				}else{
				    if (w->esq->cor == PRETO){//caso 3
						w->dir->cor = PRETO;
						w->cor = VERMELHO;
						RB_rotacaoEsquerda(w);
						w = no->pai->esq;
				}//caso 4
				w->cor = no->pai->cor;
				no->pai->cor = PRETO;
				w->dir->cor = PRETO;
				RB_rotacaoDireita(no->pai);
				no = raiz;
				}
			}
		}
	}
	no->cor = PRETO;
}
void RB::RB_delete (int y){
	No* del = RB_buscar(this->raiz, y); // chamo a busca para achar o nó correto com o valor pedido
	if (del->dado == y){ //caso ache passo esse nó para verdadeira remoção
		RB_delete(del);
		cout << "Deletado com sucesso!" << endl;
		RB_preOrdem(raiz);
	}
	else cout << "Elemento não encontrado!" << endl;
}

//PRE_ORDEM::percorre minha árvore (R->E->D)
void RB::RB_preOrdem (No* t){
	if (false == igual (t, nil)){
		cout << " >> "<< "[" << t->dado << ", " << t->cor << "] ";
		RB_preOrdem (t->esq);
		RB_preOrdem (t->dir);
	}
}

void RB::RB_preOrdem (){
	RB_preOrdem(this->raiz);
}

//ALTURA::Calcula a altura da minha árvore
int RB::RB_altura (No* t){
	int esq, dir;

	if (igual (t, nil)) return 0;

	esq = RB_altura(t->esq);
	dir = RB_altura(t->dir);

	return 1 + (esq > dir ? esq : dir);
}

int RB::altura (){
	No* aux = raiz;
	return RB_altura(aux);
}

//funcão necessária p/ remoção
RB::No* RB::minimo(No* t){
	if (igual (t, nil) || igual(t->esq, nil))
		return t;
	return minimo(t->esq);
}


//BUSCAR::busca um elemento da árvore
//funções buscar elementos para auxiliar
//na remoção de nós da minha árvore
RB::No* RB::RB_buscar (No* t, int x){
	if (igual (t,nil) || t->dado == x)		
		return t;		
	No *esq;
	esq = RB_buscar  (t->esq, x);
	if (esq != nil) return esq;
	return RB_buscar (t->dir, x);
}
RB::No* RB::RB_buscar (int z){
	return RB_buscar (raiz, z);
}


//MENU:: Implementação das opções de menu

void RB::menu(){
	
	cout << endl;
	cout << "------------------------------" << endl;
	cout << "| ÁRVORE RUBRO-NEGRA |" << endl;
	cout << "1: INSERIR Elemento na Árvore" << endl;
	cout << "2: PERCURSO em Pré-Ordem (R->E->D)" << endl;
	cout << "3: ALTURA da Árvore" << endl;
	cout << "4: DELETAR Elemento da Árvore" << endl;
	cout << "5: Sair" << endl;
	cout << "------------------------------" << endl;
	
	cout << "Digite sua escolha (1-5): ";
	
	int op;
	cin >> op;	
	
	switch(op){
		case 1:
				cout << "Digite o valor: ";
				int novo;
				cin >> novo;
				inserir(novo);
				cout << endl;
				cout << "Sua Árvore em Pre-Ordem: ";
				RB_preOrdem();
				cout << endl;
				menu();
				break;
		case 2:
				cout << "PERCURSO em Pré-Ordem: ";
				RB_preOrdem();
				cout << endl;
				menu();
				break;
		case 3:
				cout << "ALTURA: " << altura() << endl;
				menu();
				break;
		case 4: 
				cout << "Digite o valor: ";
				int del;
				cin >> del;
				RB_delete(del);
				cout << endl;
				menu();
				break;

		case 5:	
				cout << "Tchau, tchau... " << endl;
				exit(0);			
		
		default: 
				cout << "Escolha Inválida" << endl;
				menu();		
		}	

}
