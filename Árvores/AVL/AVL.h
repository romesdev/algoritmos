#include <iostream>
//Francisco Romes da Silva Filho - 409976
using namespace std;

typedef struct No {
	int dado;
	struct No *esq, *dir; 
	int balanco;
	//bool desbalanceada;
} No;

bool desbalanceada; //declarei dessa forma a variável para identificar se está balanceada ou não

No *criar_arvore (int x, No *esq, No *dir);
No *inserir (No *raiz, int valor);
No *rotacaoDireita (No *raiz);
No *rotacaoEsquerda (No *raiz);
No *procurar_no (No *raiz, int x);
int numero_nos (No *raiz);
int altura (No *raiz);
int minimo (No *raiz);
int maximo (No *raiz);
int numero_folhas(No *raiz);
void pre_ordem (No *raiz);
void pos_ordem (No *raiz);
void em_ordem (No *raiz);
void menu();
void escolha(No *no);
