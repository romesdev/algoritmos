#ifndef GRAPHMATRIX
#define GRAPHMATRIX
//FRANCISCO ROMES DA SILVA FILHO // MATRICULA: 409976
//IMPLEMENTAÇÃO DE GRAFOS:
//COLORAÇÃO DE GRAFOS
//VERIFICAÇÃO DE GRAFO BIPARTIDO (BIGRAFO)
//Referência do código:
//Implementações passadas pelo professor em aula e do autor do trabalho

class Grafo {
    private: 
        int **adjM; // matriz de adjacências 
        int V; //ordem da matriz -- |V (G)|
        bool direcionado; // grafo é direcionado?
        char *cores;
    
    public:
        Grafo (int n, bool d);
        ~Grafo();
        void addAresta (int orig, int dest);
        void imprimeAdjMatriz ();
        bool bigrafo ();
        void printCores();

};
#endif