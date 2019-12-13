#include <iostream>
#include "heap.h"

using namespace std;

int main(){

    cout << "Digite o tamanho máximo do Heap: ";
    int tam;//tamanho máximo do heap
    cin >> tam;

    MaxHeap heap = MaxHeap(tam);//crio um heap passando o seu tamanho máximo
    heap.menu();
    return 0;
}


