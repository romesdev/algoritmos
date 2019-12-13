#include <iostream>
#include "heap.h"

//definições
#define PAI(i) (i / 2)
#define ESQ(i) (2 * i)
#define DIR(i) ((2 * i) + 1)

using namespace std;
        // Constructores
MaxHeap::MaxHeap(){
        //vázio
}

MaxHeap::MaxHeap(int n){ 
      //A = (int*)malloc(sizeof(int)*10); 
      length = n;
      heapSize = 0;
      A = new int [length];
}// Constructor

        
//Destrutor
MaxHeap::~MaxHeap (){
        //delete A;
} // Destrutor

void MaxHeap::buildMaxHeap(){
     heapSize = length;
     for (int i = ((length/2) - 1); i >= 1; i--){
             maxHeapify(i);
     }
}


void MaxHeap::maxHeapInsert (int key){ // Insere novo valor
        if (heapSize == length) {
                cout << "Heap cheia até o talo!" << endl;
                return;     
        }
                
        heapSize += 1;// incremento 1 no tamanho atual
        A[heapSize] = key - 1;
        heapIncreaseKey(heapSize, key);
} 
void MaxHeap::maxHeapify(int i){
        int esq = ESQ(i);
        int dir = DIR (i);
        int maior = 0;

        if (esq <= heapSize and A[esq] > A[i]) maior = esq;
        else maior = i;

        if (dir <= heapSize and A[dir] > A[maior]) maior = dir;
        
        if (maior != i){
                swap(A[i], A[maior]);
                maxHeapify(maior);
        }
}        

int  MaxHeap::heapMaximum (){// Retorna valor máximo
        if (heapSize == 0) return -42; //resposta para a vida o universo e tudo mais
        return A[1];//o primeiro elemento é sempre o maior
}
int  MaxHeap::heapExtractMax (){ // Remove e retorna máximo
        if (heapSize < 1)
                cout <<  "Heap vázia, menor!" << endl;
        int max = A[1];
        A[1] = A[heapSize];
        heapSize = heapSize - 1;

        maxHeapify (1);
        return max;
}
        
void MaxHeap::heapIncreaseKey (int i, int key){ //incrementa o valor da posição i por key
        if (key < A[i])
                cout << "Tá errado, menor!" << endl;
        A[i] = key;
        
        while (i > 1 and A[PAI(i)] < A[i]){
                swap (A[i], A[PAI(i)]);
                i = PAI(i);
        }
}

bool MaxHeap::isEmpty (){ // retorna true se heap vazio
        if (heapSize == 0) true;
        else false;
}

int MaxHeap::percorrer(){
        cout << endl << "Heap: ";
        for (int i = 1; i <= length; i++){
                if(A[i] != 0) cout << A[i] << " >> ";// desconsiderando uma prioridade 0
        }
        cout << endl;
}

int MaxHeap::heapSort(){
        buildMaxHeap();

        for (int i = length; i >= 1; i--){
                swap(A[1], A[i]);
                heapSize = heapSize - 1;
                maxHeapify(1);
        }
        percorrer();

}

void MaxHeap::menu (){
	cout << endl;
        cout << "--------------------------------" << endl;
	cout << "| HEAP |" << endl;
        cout << "1: INSERIR ELEMENTO." << endl;
	cout << "2: MOSTRAR CONFIGURAÇÃO." << endl;
	cout << "3: HEAPSORT " << endl;
	cout << "4: MOSTRAR O MAIOR ELEMENTO." << endl;
	cout << "5: SAIR." << endl;
	cout << "--------------------------------" << endl;
	cout << "Digite sua escolha (1-5): ";
	
	int op;
	cin >> op;	
	
	switch(op){
        case 1:
		cout << "Digite o valor: ";
		int novo;
		cin >> novo;
                maxHeapInsert(novo);
		percorrer();
                menu();
		break;
	case 2:
	        cout << "Configuração do Heap: " << endl;
		percorrer();
		cout << endl;
		menu();
		break;
	case 3:
		cout << "O HeapSort modificará o Heap e mostrará o Heap Ordenado" << endl;
                heapSort();
		cout << endl;
		menu();
		break;

	case 4: 
		cout << "Maior Elemento: " << heapMaximum();
		cout << endl;
		menu();
		break;
	case 5:
		exit(0);
		
	default: 
		cout << "Escolha Inválida" << endl;
		menu();		
}	

}

