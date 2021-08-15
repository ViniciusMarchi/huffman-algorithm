#include "no.h"
#include <unordered_map>

using namespace std;

// Definição da Heap Mínima, como visto em aula
class MinHeap{
    private:
        int numElementos; // tamanho atual
        int max; // tamanho máximo
        No** vetorPonteiros; // vetor de ponteiros do tipo Nó

    public:
        // Construtor cria a heap recebendo o tamanho, o texto e o map que armazena a frequência de cada caractere no texto
        MinHeap(unordered_map<char, int>);
        
        //Devido a alocação dinâmica do vetor, existe um destrutor para desalocar toda a memória alocada dinamicamente
        ~MinHeap();

        void subir(int);
        void descer(int);
        void construirHeap();
        void inserir(No*);
        No* remover();
        bool folha(No*);
};