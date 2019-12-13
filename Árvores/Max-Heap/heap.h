#ifndef MAXHEAP_H
#define MAXHEAP_H

class MaxHeap {	
	private:
		int *A; // Ponteiro para vetor de inteiros
		int length; // Capacidade total do vetor
		int heapSize; // Tamanho do heap

	public:
		MaxHeap(); //contrutor vazio
		MaxHeap(int n); // Constructor
		~MaxHeap (); // Destrutor

		int heapMaximum (); // Retorna valor máximo
		int heapExtractMax (); // Remove e retorna máximo
		void maxHeapInsert (int key); // Insere novo valor
		void maxHeapify(int i); //corrige a prioridade do Heap
		void heapIncreaseKey (int i, int key); //incrementa novamente a chave
		bool isEmpty (); // retorna true se heap vazio		
		void buildMaxHeap();// Construi um Heap a partir de um Vetor, nesse projeto ele só é usado no Heapsort
		int percorrer();//percorre o heap
		int heapSort();//Algoritmo de ordenação
		void menu();// menu para interação
};

#endif
