#include <iostream>
#include "AVL.h"
//Francisco Romes da Silva Filho - 409976 - Trabalho de EDA 
using namespace std;

//função de inserção
No* inserir (No *raiz, int valor){
	if (raiz == NULL){
		raiz = new No;
		raiz->dado = valor;
		raiz->esq = raiz->dir = NULL;
		raiz->balanco = 0;
		desbalanceada = true;
		return raiz;
	}else if (valor < raiz->dado){
		raiz->esq = inserir (raiz->esq, valor);
		if (desbalanceada){
			switch (raiz->balanco){
				case 1:
						raiz->balanco = 0;
						desbalanceada = false;
						break;
				case 0:
						raiz->balanco = -1;
						break;
				case -1://caso de necessidade de balancemamento
						raiz = rotacaoDireita(raiz);//chama a função de rotação direita e retorna a atualização
						break;	
			}
		}
	}else if (valor > raiz->dado){
		raiz->dir = inserir (raiz->dir, valor);
		if(desbalanceada){
			switch (raiz->balanco){
				case -1:
						raiz->balanco = 0;
						desbalanceada = false;
						break;
				case 0:	
						raiz->balanco = 1;						
						break;
				case 1: //caso de necessidade de balancemamento
						raiz = rotacaoEsquerda(raiz);//chama a função de rotação esquerda e retorna a atualização
						break;
			}
		}
	}
	return raiz;
}

No *criar_arvore (int x, No *esq, No *dir){
	No *r = new No;
	r->dado = x;
	r->esq = esq;
	r->dir = dir;
	r->balanco = 0; 
	return r;
}

No* rotacaoDireita (No *raiz){
	No *ptu = raiz->esq;
		if (ptu->balanco == -1){//rotação simples dir
			raiz->esq = ptu->dir;
			ptu->dir = raiz;
			raiz->balanco = 0;
			raiz = ptu;
		} else{//rotação dupla esq
			No* ptv = ptu->dir;
			ptu->dir = ptv->esq;
			ptv->esq = ptu;
			raiz->esq = ptv->dir;
			ptv->dir = raiz;
			raiz->balanco = (ptv->balanco == -1) ? 1: 0;
			ptu->balanco = (ptv->balanco == 1) ? -1: 0;
			raiz = ptv;

		}
	raiz->balanco = 0;
	desbalanceada = false;
	return raiz;
}

No* rotacaoEsquerda(No *raiz){
	No * ptu = raiz->dir;
		if (ptu->balanco == 1){//rotação simples esq
			raiz->dir = ptu->esq;
			ptu->esq = raiz;
			raiz->balanco = 0;
			raiz = ptu;
		} else{//rotação dupla esq
			No* ptv = ptu->esq;
			ptu->esq = ptv->dir;
			ptv->dir = ptu;
			raiz->dir = ptv->esq;
			ptv->esq = raiz;
			raiz->balanco = (ptv->balanco == 1) ? -1: 0;
			ptu->balanco = (ptv->balanco == -1) ? 1: 0;
			raiz = ptv;
		}
	raiz->balanco = 0;
	desbalanceada = false;
	return raiz;
}

No* procurar_no (No *raiz, int x){
	if (raiz == NULL || raiz->dado == x)
		return raiz;
		
	No *esq;
	esq = procurar_no (raiz->esq, x);
	if (esq != NULL) return esq;
	return procurar_no (raiz->dir, x);
}

int numero_nos (No *raiz){
	if (raiz == NULL) return 0;
	return numero_nos (raiz->esq) + numero_nos (raiz->dir) + 1;
}

int altura(No *raiz){
	int h_esq, h_dir;

	if (raiz == NULL) return 0;

	h_esq = altura(raiz->esq);
	h_dir = altura(raiz->dir);

	return 1 + (h_esq > h_dir ? h_esq : h_dir);

}

int minimo(No *raiz){
	if (raiz == NULL || raiz->esq ==  NULL)
		return raiz->dado;
	return minimo(raiz->esq);
}

int maximo (No *raiz){
	if (raiz == NULL || raiz->dir ==  NULL)
		return raiz->dado;
	return maximo (raiz->dir);
}

int numero_folhas(No *raiz){
	//int f1, f2;
	if (raiz == NULL) return 0;
	else if(raiz->esq == NULL && raiz->dir == NULL) return 1;
	return (numero_folhas(raiz->esq))+ (numero_folhas(raiz->dir));

}

void pre_ordem(No *raiz){
	if (raiz != NULL){
		cout << raiz->dado << " ";
		pre_ordem (raiz->esq);
		pre_ordem (raiz->dir);
	}
}

void pos_ordem (No *raiz){
	if (raiz != NULL){
		pos_ordem (raiz->esq);
		pos_ordem (raiz->dir);
		cout << raiz->dado << " ";
	}
}

void em_ordem (No *raiz){
	if (raiz != NULL){
		em_ordem (raiz->esq);
		cout << raiz->dado << " ";
		em_ordem (raiz->dir);
	}
}


void menu(){
	No *no = NULL;

	while(true){
		cout << endl;
		cout << "| ÁRVORE AVL.trab_01 |" << endl;
		cout << "1: Inserir Elemento na Árvore" << endl;
		cout << "2: Percurso em Pre-Ordem" << endl;
		cout << "3: Percurso em Em-Ordem" << endl;
		cout << "4: Percurso em Pós-Ordem" << endl;
		cout << "5: Altura da Árvore" << endl;
		cout << "6: Número de Folhas da Árvore" << endl;
		cout << "7: Valor Mínimo e Máximo da Árvore" << endl;
		cout << "8: Sair" << endl;
		
		cout << "Digite sua escolha (1-8): ";
		cout << endl;
		cout << endl;
		
		int op;
		cin >> op;	
	
		switch(op){
			case 1:
					cout << "Digite o valor: ";
					int novo;
					cin >> novo;
					no = inserir(no, novo);
					cout << "Sua Árvore em Ordem: ";
					em_ordem(no);
					break;
			case 2:
					cout << "Percurso em Pré-Ordem: ";
					pre_ordem(no);
					cout << endl;
					break;
			case 3:
					cout << "Percurso em Em-Ordem: ";
					em_ordem(no);
					cout << endl;
					break;

			case 4: 
					cout << "Percurso em Pós-Ordem: ";
					pos_ordem(no);
					cout << endl;
					break;

			case 5:	
					cout << "Altura: " << altura(no) << endl;
					break;

			case 6:
					cout <<  "Número de Folhas: " << numero_folhas(no) << endl;
					break;
			case 7:	
					cout << "Mín: " << minimo(no) << " e " << "Máx: " << maximo(no) << endl;
					break; 

			case 8:
					delete no;
					exit(0);
			
			default: 
					cout << "Escolha Inválida" << endl;	
			}	
	}

}

int main(){
		menu();
		return 0;
}
